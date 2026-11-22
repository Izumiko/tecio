#include "DataSetWriter.h"
#include "ThirdPartyHeadersBegin.h"
#include <boost/unordered_set.hpp>
#include "ThirdPartyHeadersEnd.h"
#include "SzlFileLoader.h"
#include "AltTecUtil.h"
#include "CodeContract.h"
#include "FileWriterInterface.h"
#include "ItemSetIterator.h"
#include "ZoneVarMetadata.h"
#include "ZoneWriterAbstract.h"
#include "ZoneWriterFactory.h"
#include "zoneUtil.h"
namespace tecplot { namespace ___3934 { DataSetWriter::DataSetWriter( ___37*                 ___36, ___3502                      varsToWrite, ___3502                      zonesToWrite, ___1843 const&                  maxIJKSubzoneSize, ItemAddress64::ItemOffset_t maxFESubzoneSize, bool                        flushingToDisk  ) : ___2338(___36) , m_varIter( new ItemSetIterator(*___36, ___36->___894() ? ___36->___888() : 0, varsToWrite)) , m_zoneIter(new ItemSetIterator( *___36, ___36->___894() ? ___36->___889() : 0, zonesToWrite)) , ___2681(___36, maxIJKSubzoneSize, maxFESubzoneSize) , m_zoneVarMetadata( new ___4707(*___36, *m_varIter, *m_zoneIter, flushingToDisk  )) , m_flushingToDisk(flushingToDisk) { REQUIRE(VALID_REF(___36)); } DataSetWriter::~DataSetWriter() {} ___372 DataSetWriter::writeDataSet( FileWriterInterface& szpltFile, uint32_t fileVersion, ___1390& szpltZoneHeaderFileLocs) { REQUIRE(szpltFile.___2040()); REQUIRE( fileVersion == 105 || fileVersion == 231 || fileVersion == 232); if (!___2338->___894()) return ___4227; ___372 ___2038 = ___4227; m_zoneIter->reset(); ___4636 const ___341 = m_zoneIter->baseItem(); while (___2038 && m_zoneIter->hasNext()) { ___4636 const ___902 = m_zoneIter->next(); if (!___2338->___4638(___902 + 1)) continue; try { std::vector<___372> ___4564; ___372              ___4499; getZoneSharing(___4564, ___4499, ___902, ___341, szpltFile.___842());
 #if defined OUTPUT_TIMES
uint64_t ___3688 = ___4709::___715();
 #endif
___4711                     ___4710(___2681, *___2338); boost::shared_ptr<___4709> ___4708 = ___4710.___4708( fileVersion, *m_varIter, ___902, m_flushingToDisk ? 0 : ___341, ___4564, ___4499);
 #if defined OUTPUT_TIMES
uint64_t ___1165 = ___4709::___715(); ___1930(NULL, "%g seconds partitioning zone.", (double)(___1165 - ___3688) / 1000.0);
 #endif
___2038 = ___4708->writeZone(szpltFile, szpltFile.fileLoc()); ___4636 const fileZone = ___902 - ___341; if (___2038) { szpltZoneHeaderFileLocs[fileZone] = ___4708->getZoneHeaderFilePosition();
 #if defined DO_SUBZONE_HISTOGRAM || defined DO_ITEMANDSUBZONE_HISTOGRAM
{ if (___4644(*___2338, ___902) && !zoneIsPartitioned(*___2338, ___902)) { boost::shared_ptr<___1348> zoneInfo = ___2681.getFEZoneInfo(___902, ___341);
 #ifdef DO_SUBZONE_HISTOGRAM
extern ___372 OutputSubzoneHistograms( char const*                         szpltFileName, ___37&                         ___36, ___4636                         zone, boost::shared_ptr<___1348 const> ___1347); OutputSubzoneHistograms(szpltFile.___1392().c_str(), *___2338, ___902, zoneInfo);
 #endif
 #ifdef DO_ITEMANDSUBZONE_HISTOGRAM
extern ___372 OutputItemAndSubzoneHistograms( char const*                         szpltFileName, ___37&                         ___36, ___4636                         zone, boost::shared_ptr<___1348 const> ___1347); OutputItemAndSubzoneHistograms(szpltFile.___1392().c_str(), *___2338, ___902, zoneInfo);
 #endif
} }
 #endif
} m_varIter->reset(); ___4352 const baseVar = m_varIter->baseItem(); while (m_varIter->hasNext()) { ___4352 const datasetVar                        = m_varIter->next(); ___4352 const fileVar                           = datasetVar - baseVar; m_zoneVarMetadata->m_vzMinMaxes[fileVar][fileZone] = ___4708->varMinMax(datasetVar); } if (szpltFile.___842() == ___843 && !m_flushingToDisk) ___2681.remove(___902); } catch (std::exception const& e) { ___2038 = ___1184(e.what()); } if (!___2038) ___2681.clear(); } return ___2038; } void DataSetWriter::replaceDataSource(___37* ___36, ___3502 varsToWrite, ___3502 zonesToWrite) { REQUIRE(VALID_REF_OR_NULL(___36)); ___2338 = ___36; ___2681.replaceDataSource(___36, zonesToWrite); if (___36 == NULL) { m_varIter.reset(); m_zoneIter.reset(); m_zoneVarMetadata.reset(); } else { m_varIter.reset(new ItemSetIterator( *___2338, ___36->___894() ? ___36->___888() : 0, varsToWrite)); m_zoneIter.reset(new ItemSetIterator( *___2338, ___36->___894() ? ___36->___889() : 0, zonesToWrite)); m_zoneVarMetadata.reset(new ___4707(*___36, *m_varIter, *m_zoneIter, m_flushingToDisk)); } } void DataSetWriter::clear(int32_t numZonesToRetain, int32_t const* zonesToRetain) { REQUIRE(IMPLICATION(numZonesToRetain > 0, VALID_REF(zonesToRetain))); if (numZonesToRetain == 0) { ___2681.clear(); } else { boost::unordered_set<int32_t> retainZoneSet; for (int32_t i = 0; i < numZonesToRetain; ++i) retainZoneSet.insert(zonesToRetain[i]); m_zoneIter->reset(); while (m_zoneIter->hasNext()) { ___4636 const ___902 = m_zoneIter->next(); if (___2338->___4638(___902 + 1) && retainZoneSet.find(___902 + 1) == retainZoneSet.end()) ___2681.remove(___902); } } } void DataSetWriter::getZoneSharing( std::vector<___372>& ___4564, ___372&              ___4499, ___4636             ___902, ___4636             ___341, DataFileType_e          ___842) const { REQUIRE(0 <= ___902 && ___2338->___4638(___902 + 1)); REQUIRE(0 <= ___341 && ___341 <= ___902); REQUIRE(___4564.empty()); m_varIter->reset(); ___4352 const  baseVar  = m_varIter->baseItem(); ___4636 const fileZone = ___902 - ___341; while (m_varIter->hasNext()) { ___4352 const fileVar = m_varIter->next() - baseVar; ___4564.push_back( !m_zoneVarMetadata->m_vzIsPassive[fileVar][fileZone] && m_zoneVarMetadata->m_vzShareVarWithZone[fileVar][fileZone] == -1); } ___4499 = (___842 != ___846 && m_zoneVarMetadata->m_zoneShareConnectivityWithZone[fileZone] == -1); } }}

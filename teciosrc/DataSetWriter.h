 #pragma once
#include "ThirdPartyHeadersBegin.h"
#include <boost/scoped_ptr.hpp>
#include "ThirdPartyHeadersEnd.h"
#include "basicTypes.h"
#include "ZoneInfoCache.h"
#include "ZoneVarMetadata.h"
namespace tecplot { namespace ___3934 { class ___37; class FileWriterInterface; class ItemSetIterator; class DataSetWriter { public: DataSetWriter( ___37*                 ___36, ___3502                      varsToWrite, ___3502                      zonesToWrite, ___1843 const&                  maxIJKSubzoneSize, ItemAddress64::ItemOffset_t maxFESubzoneSize, bool                        flushToDisk = false); virtual ~DataSetWriter(); virtual ___372 writeDataSet(FileWriterInterface& szpltFile, uint32_t fileVersion, ___1390& szpltZoneHeaderFileLocs); void replaceDataSource(___37* ___36, ___3502 varsToWrite, ___3502 zonesToWrite); void clear(int32_t numZonesToRetain, int32_t const* zonesToRetain); ___4707 const& ___4706() { return *m_zoneVarMetadata; } protected: void getZoneSharing( std::vector<___372>& ___4564, ___372&              ___4499, ___4636             zone, ___4636             ___341, DataFileType_e          ___842) const; ___37*                        ___2338; boost::scoped_ptr<ItemSetIterator> m_varIter; boost::scoped_ptr<ItemSetIterator> m_zoneIter; ZoneInfoCache                      ___2681; boost::scoped_ptr<___4707> m_zoneVarMetadata; bool const                         m_flushingToDisk; }; }}

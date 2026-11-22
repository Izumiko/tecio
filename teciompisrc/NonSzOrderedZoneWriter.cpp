#include "NonSzOrderedZoneWriter.h"
#include "ThirdPartyHeadersBegin.h"
#include <boost/assign.hpp>
#include "ThirdPartyHeadersEnd.h"
#include "AltTecUtil.h"
#include "FieldData.h"
#include "ItemSetIterator.h"
#include "checkPercentDone.h"
#include "fileStuff.h"
#include "writeValueArray.h"
namespace tecplot { namespace ___3934 { NonSzOrderedZoneWriter::NonSzOrderedZoneWriter( uint32_t                      fileVersion, ItemSetIterator&              varIter, ___4636                   zone, ___4636                   ___341, std::vector<___372> const& ___4564, ___372                     ___4499, ___37&                   ___36) : NonSzZoneWriterAbstract(fileVersion, varIter, zone, ___341, ___4564, ___4499, ___36) , m_faceNeighborGenerator(___36) , m_faceNeighborWriter(m_faceNeighborGenerator, zone, ___341) {} NonSzOrderedZoneWriter::~NonSzOrderedZoneWriter() {} ___372 NonSzOrderedZoneWriter::writeZoneConnectivity(FileWriterInterface& szpltFile) { ___372 ___2038 = ___4227; m_zoneFileLocations.___2499 = ___330; if (m_writeConnectivity) { m_zoneFileLocations.___2664 = szpltFile.fileLoc(); ___2038                                          = m_faceNeighborWriter.write(szpltFile); } else { m_zoneFileLocations.___2664 = ___330; } return ___2038; } uint64_t NonSzOrderedZoneWriter::zoneConnectivityFileSize(bool ___2001) { if (m_writeConnectivity) return m_faceNeighborWriter.sizeInFile(___2001); else return 0; } }}

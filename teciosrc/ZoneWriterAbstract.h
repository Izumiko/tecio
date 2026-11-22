 #pragma once
#include "ThirdPartyHeadersBegin.h"
#include <string>
#include <vector>
#include "ThirdPartyHeadersEnd.h"
#include "basicTypes.h"
#include "MinMax.h"
namespace tecplot { namespace ___3934 { class ___37; class FileWriterInterface; class ItemSetIterator; class ___4709 { public: ___4709( uint32_t                      fileVersion, ItemSetIterator&              varIter, ___4636                   zone, ___4636                   ___341, std::vector<___372> const& ___4564, ___372                     ___4499, ___37&                   ___36); virtual ~___4709(); uint64_t zoneFileSize(bool ___2001); ___372 writeZone(FileWriterInterface& szpltFile, ___1391 fileLoc); virtual uint64_t getZoneHeaderFilePosition() const; virtual ___2480 varMinMax(___4352 ___4336);
 #if defined OUTPUT_TIMES
static uint64_t ___715();
 #endif
protected: uint32_t               m_fileVersion; ItemSetIterator&       m_varIter; ___4636 const      ___2678; ___4636 const      m_baseZone; std::vector<___372> m_writeVariables; ___372 const        m_writeConnectivity; ___37&            ___2338; uint64_t               m_zoneHeaderFilePosition; uint64_t               m_zoneFileSize; private: virtual uint64_t  zoneConnectivityFileSize(bool ___2001)                = 0; virtual uint64_t  zoneDataFileSize(bool ___2001)                        = 0; virtual uint64_t  zoneHeaderFileSize(bool ___2001)                      = 0; virtual ___372 writeZoneConnectivity(FileWriterInterface& szpltFile) = 0; virtual ___372 writeZoneData(FileWriterInterface& szpltFile)         = 0; virtual ___372 writeZoneHeader(FileWriterInterface& szpltFile)       = 0; }; }}

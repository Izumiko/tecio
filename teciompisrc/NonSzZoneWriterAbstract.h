 #pragma once
#include "NonSzZoneFileLocations.h"
#include "NonSzZoneHeaderWriter.h"
#include "NonSzZoneVariableWriter.h"
#include "ZoneWriterAbstract.h"
namespace tecplot { namespace ___3934 { class NonSzZoneWriterAbstract : public ___4709 { public: NonSzZoneWriterAbstract( uint32_t                      fileVersion, ItemSetIterator&              varIter, ___4636                   zone, ___4636                   ___341, std::vector<___372> const& ___4564, ___372                     ___4499, ___37&                   ___36); virtual ~NonSzZoneWriterAbstract(); protected: NonSzZoneVariableWriter m_variableWriter; NonSzZoneHeaderWriter   m_headerWriter; NonSzZoneFileLocations  m_zoneFileLocations; private: virtual uint64_t  zoneConnectivityFileSize(bool ___2001) = 0; virtual uint64_t  zoneDataFileSize(bool ___2001); virtual uint64_t  zoneHeaderFileSize(bool ___2001); virtual ___372 writeZoneData(FileWriterInterface& szpltFile); virtual ___372 writeZoneConnectivity(FileWriterInterface& szpltFile) = 0; virtual ___372 writeZoneHeader(FileWriterInterface& szpltFile); }; }}

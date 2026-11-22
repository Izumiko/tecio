 #pragma once
#include "ClassMacros.h"
#include "NonSzOrderedZoneFaceNeighborGenerator.h"
#include "NonSzZoneFaceNeighborWriter.h"
#include "NonSzZoneWriterAbstract.h"
namespace tecplot { namespace ___3934 { class ItemSetIterator; class NonSzOrderedZoneWriter : public NonSzZoneWriterAbstract { UNCOPYABLE_CLASS(NonSzOrderedZoneWriter); public: NonSzOrderedZoneWriter( uint32_t                      fileVersion, ItemSetIterator&              varIter, ___4636                   zone, ___4636                   ___341, std::vector<___372> const& ___4564, ___372                     ___4499, ___37&                   ___36); virtual ~NonSzOrderedZoneWriter(); private: virtual uint64_t  zoneConnectivityFileSize(bool ___2001); virtual ___372 writeZoneConnectivity(FileWriterInterface& szpltFile); NonSzOrderedZoneFaceNeighborGenerator m_faceNeighborGenerator; NonSzZoneFaceNeighborWriter           m_faceNeighborWriter; ___372 ___4514(FileWriterInterface& file, ValueLocation_e ___4326, ___4352 ___4336); }; }}

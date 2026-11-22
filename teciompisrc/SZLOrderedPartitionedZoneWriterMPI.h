 #pragma once
#include "ThirdPartyHeadersBegin.h"
#include <map>
#include <mpi.h>
#include <vector>
#include <boost/scoped_ptr.hpp>
#include "ThirdPartyHeadersEnd.h"
#include "SZLOrderedPartitionedZoneWriter.h"
namespace tecplot { namespace ___3934 { class ___1880; }} namespace tecplot { namespace teciompi { class SZLOrderedPartitionedZoneWriterMPI : public ___3934::SZLOrderedPartitionedZoneWriter { public: SZLOrderedPartitionedZoneWriterMPI( uint32_t                      fileVersion, ___3934::ItemSetIterator&       varIter, ___3934::___4636            zone, ___3934::___4636            ___341, std::vector<___372> const& ___4564, ___372                     ___4499, ___3934::___37&            ___36, ___3934::ZoneInfoCache&         zoneInfoCache, MPI_Comm                      communicator, int                           mainProcess); virtual ~SZLOrderedPartitionedZoneWriterMPI(); virtual ___2480 varMinMax(___3934::___4352 datasetVar); private: virtual uint64_t  zoneDataFileSize(bool ___2001); virtual uint64_t  zoneHeaderFileSize(bool ___2001); virtual ___372 writeZoneData(___3934::FileWriterInterface& szpltFile); virtual ___372 writeZoneHeader(___3934::FileWriterInterface& szpltFile); struct Impl; boost::scoped_ptr<Impl> m_impl; }; }}

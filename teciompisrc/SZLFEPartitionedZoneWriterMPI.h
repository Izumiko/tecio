 #pragma once
#include "ThirdPartyHeadersBegin.h"
#include <mpi.h>
#include <vector>
#include <boost/scoped_ptr.hpp>
#include "ThirdPartyHeadersEnd.h"
#include "SZLFEPartitionedZoneWriter.h"
namespace tecplot { namespace ___3934 { class ___37; class ZoneInfoCache; class ItemSetIterator; }} namespace tecplot { namespace teciompi { class SZLFEPartitionedZoneWriterMPI : public ___3934::SZLFEPartitionedZoneWriter { public: SZLFEPartitionedZoneWriterMPI( uint32_t                      fileVersion, ___3934::ItemSetIterator&       varIter, ___3934::___4636            zone, ___3934::___4636            ___341, std::vector<___372> const& ___4564, ___372                     ___4499, ___3934::___37&            ___36, ___3934::ZoneInfoCache&         zoneInfoCache, MPI_Comm                      communicator, int                           mainProcess); virtual ~SZLFEPartitionedZoneWriterMPI(); virtual ___2480 varMinMax(___3934::___4352 datasetVar); private: virtual uint64_t  zoneDataFileSize(bool ___2001); virtual uint64_t  zoneHeaderFileSize(bool ___2001); virtual ___372 writeZoneData(___3934::FileWriterInterface& szpltFile); virtual ___372 writeZoneHeader(___3934::FileWriterInterface& szpltFile); void createPartitionWriters(); void collateAndReturnResponses(class MPINonBlockingCommunicationCollection& communicationCollection); void exchangeGhostInfo(std::map<int, boost::shared_ptr<___3934::___1348>>& partitionInfoMap); struct Impl; boost::scoped_ptr<Impl> const m_impl; }; }}

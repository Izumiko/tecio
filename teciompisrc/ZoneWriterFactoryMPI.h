 #pragma once
#include "ThirdPartyHeadersBegin.h"
#include <mpi.h>
#include "ThirdPartyHeadersEnd.h"
#include "basicTypes.h"
#include "ZoneWriterFactory.h"
namespace tecplot { namespace ___3934 { class ___37; class ZoneInfoCache; class ___4709; class ItemSetIterator; }} namespace tecplot { namespace teciompi { class ZoneWriterFactoryMPI : public ___3934::___4711 { public: ZoneWriterFactoryMPI( ___3934::ZoneInfoCache& zoneInfoCache, ___3934::___37& ___36, MPI_Comm communicator, int mainProcess); boost::shared_ptr<___3934::___4709> ___4708( uint32_t                      fileVersion, ___3934::ItemSetIterator&       varIter, ___3934::___4636            zone, ___3934::___4636            ___341, std::vector<___372> const& ___4564, ___372                     ___4499); private: MPI_Comm m_communicator; int      m_mainProcess; }; }}

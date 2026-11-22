#include "ZoneWriterFactoryMPI.h"
#include "ThirdPartyHeadersBegin.h"
#include <boost/make_shared.hpp>
#include <boost/ref.hpp>
#include "ThirdPartyHeadersEnd.h"
#include "AltTecUtil.h"
#include "ItemSetIterator.h"
#include "SZLFEPartitionedZoneWriterMPI.h"
#include "SZLOrderedPartitionedZoneWriterMPI.h"
#include "zoneUtil.h"
using namespace tecplot::___3934; namespace tecplot { namespace teciompi { ZoneWriterFactoryMPI::ZoneWriterFactoryMPI( ZoneInfoCache& zoneInfoCache, ___37& ___36, MPI_Comm communicator, int mainProcess) : ___4711(zoneInfoCache, ___36) , m_communicator(communicator) , m_mainProcess(mainProcess) {} boost::shared_ptr<___4709> ZoneWriterFactoryMPI::___4708( uint32_t                      fileVersion, ItemSetIterator&              varIter, ___4636                   zone, ___4636                   ___341, std::vector<___372> const& ___4564, ___372                     ___4499) { REQUIRE(0 <= zone && ___2338.___4638(zone + 1)); REQUIRE(0 <= ___341 && ___341 <= zone); REQUIRE(varIter.___2813() == static_cast<___4352>(___4564.size())); REQUIRE(VALID_BOOLEAN(___4499)); ZoneType_e ___4692 = ___2338.___4620(zone + 1); if (zoneIsPartitioned(___2338, zone)) { if (___4692 == ___4704) { return boost::make_shared<SZLOrderedPartitionedZoneWriterMPI>( fileVersion, boost::ref(varIter), zone, ___341, boost::ref(___4564), ___4499, boost::ref(___2338), boost::ref(___2681), m_communicator, m_mainProcess); } else { ___476(___2338.zoneGetDimension(___2338.datasetGetUniqueID(), zone + 1) == 3); return boost::make_shared<SZLFEPartitionedZoneWriterMPI>( fileVersion, boost::ref(varIter), zone, ___341, boost::ref(___4564), ___4499, boost::ref(___2338), boost::ref(___2681), m_communicator, m_mainProcess); } } else { return ___4711::___4708(fileVersion, varIter, zone, ___341, ___4564, ___4499); } } }}

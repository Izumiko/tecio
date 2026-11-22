#include "ZoneWriterFactory.h"
#include "ThirdPartyHeadersBegin.h"
#include <stdexcept>
#include <boost/make_shared.hpp>
#include <boost/ref.hpp>
#include "ThirdPartyHeadersEnd.h"
#include "AltTecUtil.h"
#include "ItemSetIterator.h"
#include "NonSzFEZoneWriter.h"
#include "NonSzOrderedZoneWriter.h"
#include "ZoneInfoCache.h"
#include "FEZoneInfo.h"
#include "IJKZoneInfo.h"
#include "SZLFEPartitionedZoneWriter.h"
#include "SZLFEZoneWriter.h"
#include "SZLOrderedPartitionedZoneWriter.h"
#include "SZLOrderedZoneWriter.h"
#include "zoneUtil.h"
namespace tecplot { namespace ___3934 { ___4711::___4711(ZoneInfoCache& zoneInfoCache, ___37& ___36) : ___2681(zoneInfoCache) , ___2338(___36) {} boost::shared_ptr<___4709> ___4711::___4708( uint32_t                      fileVersion, ItemSetIterator&              varIter, ___4636                   zone, ___4636                   ___341, std::vector<___372> const& ___4564, ___372                     ___4499) { REQUIRE(0 <= zone && ___2338.___4638(zone + 1)); REQUIRE(0 <= ___341 && ___341 <= zone); REQUIRE(varIter.___2813() == static_cast<___4352>(___4564.size())); REQUIRE(VALID_BOOLEAN(___4499)); boost::shared_ptr<___4709> ___3359; ZoneType_e const                      ___4692  = ___2338.___4620(zone + 1); ___4265 const                      datasetID = ___2338.datasetGetUniqueID(); int32_t const                         ___1087 = ___2338.zoneGetDimension(datasetID, zone + 1); if (___1087 == -1) { std::ostringstream ___2893; ___2893 << "Unable to load metrics for zone " << zone + 1; throw std::runtime_error(___2893.str()); } if (___4692 == ___4704) { if (___1087 == 3) { if (zoneIsPartitioned(___2338, zone)) { ___3359 = boost::make_shared<SZLOrderedPartitionedZoneWriter>( fileVersion, boost::ref(varIter), zone, ___341, boost::ref(___4564), ___4499, boost::ref(___2338), boost::ref(___2681)); } else { boost::shared_ptr<___1880 const> ijkZoneInfo = ___2681.getIJKZoneInfo(zone); ___3359                                           = boost::make_shared<SZLOrderedZoneWriter>( fileVersion, boost::ref(varIter), zone, ___341, boost::ref(___4564), ___4499, boost::ref(___2338), ijkZoneInfo); } } else { ___3359 = boost::make_shared<NonSzOrderedZoneWriter>( fileVersion, boost::ref(varIter), zone, ___341, boost::ref(___4564), ___4499, boost::ref(___2338)); } } else if (___4692 == ___4698 || ___4692 == ___4699) { std::ostringstream ___2893; ___2893 << "Type of zone " << zone + 1 << " not currently supported"; throw std::runtime_error(___2893.str()); } else { if (___1087 == 3) { if (zoneIsPartitioned(___2338, zone)) { ___3359 = boost::make_shared<SZLFEPartitionedZoneWriter>( fileVersion, boost::ref(varIter), zone, ___341, boost::ref(___4564), ___4499, boost::ref(___2338), boost::ref(___2681)); } else { boost::shared_ptr<___1348 const> ___1347 = ___2681.getFEZoneInfo(zone); ___3359                                         = boost::make_shared<SZLFEZoneWriter>( fileVersion, boost::ref(varIter), zone, ___341, boost::ref(___4564), ___4499, boost::ref(___2338), ___1347); } } else { ___476(___1087 == 1 || ___1087 == 2); ___3359 = boost::make_shared<NonSzFEZoneWriter>(
fileVersion, boost::ref(varIter), zone, ___341, boost::ref(___4564), ___4499, boost::ref(___2338)); } } return ___3359; } }}

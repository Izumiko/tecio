 #pragma once
 #if defined(___1988)
 #undef ___1988 
 #endif
#include "ThirdPartyHeadersBegin.h"
#include <iterator>
#include <boost/geometry.hpp>
#include <boost/geometry/geometries/box.hpp>
#include <boost/geometry/geometries/point.hpp>
#include <boost/geometry/index/rtree.hpp>
#include "ThirdPartyHeadersEnd.h"
 #if defined(___1988)
 #undef ___1988
 #endif
 #define ___1988 (-1)
#include "IJK.h"
#include "ItemAddress.h"
namespace tecplot { namespace ___3934 { int const RTREE_PAGE_SIZE = 8; typedef boost::geometry::model::point<int64_t, 3, boost::geometry::cs::cartesian> ___1852; typedef boost::geometry::model::box<___1852>                                     ___1854; typedef std::pair<___1854, tecplot::ItemAddress64::___2981>             ___1863; class ___1862 : public boost::geometry::index::rtree<___1863, boost::geometry::index::quadratic<RTREE_PAGE_SIZE>> { public: ___1862() {} explicit ___1862(std::vector<___1863> const& ___2982) : boost::geometry::index::rtree<___1863, boost::geometry::index::quadratic<RTREE_PAGE_SIZE>>( ___2982) {} void ___13(ItemAddress64::___2981 ___2978, ___1843 const& ___2475, ___1843 const& ___2365) { ___1852 ___2479(___2475.i(), ___2475.___2104(), ___2475.___2133()); ___1852 ___2373(___2365.i(), ___2365.___2104(), ___2365.___2133()); insert(std::make_pair(___1854(___2479, ___2373), ___2978)); } bool find(___1843 const& ___2475, ___1843 const& ___2365, std::vector<___1863>& ___2098) { REQUIRE(___2098.empty()); ___1852 ___2479(___2475.i(), ___2475.___2104(), ___2475.___2133()); ___1852 ___2373(___2365.i(), ___2365.___2104(), ___2365.___2133()); query(boost::geometry::index::intersects(___1854(___2479, ___2373)), std::back_inserter(___2098)); return !___2098.empty(); } }; }}

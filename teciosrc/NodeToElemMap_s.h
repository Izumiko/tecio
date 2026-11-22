 #pragma once
#include "ThirdPartyHeadersBegin.h"
#include <boost/scoped_array.hpp>
#include "ThirdPartyHeadersEnd.h"
#include "MASTER.h"
#include "GLOBAL.h"
#include "CodeContract.h"
#include "NodeMap_s.h"
namespace tecplot { namespace tecioszl { struct ___2744 { tecplot::___3934::___2719                      m_nodeCount; boost::scoped_array<tecplot::___3934::___463> m_elemIndex; boost::scoped_array<tecplot::___3934::___463> m_elem; ___2744(___2731 const& ___2724, tecplot::___3934::___2719 nodeCount); tecplot::___3934::___463 cellCountForNode(tecplot::___3934::___2719 ___2710); }; }}

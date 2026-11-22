#include "NodeToElemMap_s.h"
#include "ThirdPartyHeadersBegin.h"
 #if !defined TECIOMPI
#include <atomic>
 #endif
#include <algorithm>
#include <boost/ref.hpp>
#include <boost/shared_ptr.hpp>
#include "ThirdPartyHeadersEnd.h"
#include "NodeMap_s.h"
 #if !defined TECIOMPI
#include "JobControl_s.h"
 #endif
#include "CodeContract.h"
using namespace tecplot::___3934;
 #define MIN_CELLS_FOR_MULTITHREAD 100000 
namespace tecplot { namespace tecioszl {
 #if !defined TECIOMPI
namespace { struct NodeToElemData { tecplot::tecioszl::___2731 const&                     ___2724; boost::scoped_array<tecplot::___3934::___463> const& elemIndex; boost::scoped_array<tecplot::___3934::___463>&       elem; boost::scoped_array<std::atomic<int>>&                  count; int32_t                                                 section; ___463                                             baseCell; ___463                                             begin; ___463                                             end; NodeToElemData( tecplot::tecioszl::___2731 const&                     ___2724, boost::scoped_array<tecplot::___3934::___463> const& elemIndex, boost::scoped_array<tecplot::___3934::___463>&       elem, boost::scoped_array<std::atomic<int>>&                  count, int32_t                                                 section, ___463                                             baseCell, ___463                                             begin, ___463                                             end) : ___2724(___2724) , elemIndex(elemIndex) , elem(elem) , count(count) , section(section) , baseCell(baseCell) , begin(begin) , end(end) {} }; void fillElemArrayForCellRange(___90 ___2123) { NodeToElemData* nodeToElemData = reinterpret_cast<NodeToElemData*>(___2123); for (___463 ___447 = nodeToElemData->begin; ___447 < nodeToElemData->end; ++___447) { int32_t nodesPerCell = nodeToElemData->___2724.m_numNodesPerCellPerSection[nodeToElemData->section]; for (int32_t ___2710 = 0; ___2710 < nodesPerCell; ++___2710) { ___2719 ___2717 = nodeToElemData->___2724.value(nodeToElemData->section, ___447 * nodesPerCell + ___2710); ___463 ind       = nodeToElemData->elemIndex[___2717] + nodeToElemData->count[___2717]; ++nodeToElemData->count[___2717]; ___476(nodeToElemData->elem[ind] == 0); nodeToElemData->elem[ind] = nodeToElemData->baseCell + ___447; } } } }
 #endif
___2744::___2744(tecplot::tecioszl::___2731 const& ___2724, ___2719 nodeCount) : m_nodeCount(nodeCount) { size_t indexSize = static_cast<size_t>(nodeCount + 1); m_elemIndex.reset(new ___463[indexSize]); memset(m_elemIndex.get(), 0, indexSize * sizeof(m_elemIndex[0])); size_t arraySize = 0; for (int32_t section = 0; section < checked_numeric_cast<int32_t>(___2724.m_numCellsPerSection.size()); ++section) arraySize += static_cast<size_t>(___2724.m_numCellsPerSection[section] * ___2724.m_numNodesPerCellPerSection[section]); m_elem.reset(new ___463[arraySize]); memset(m_elem.get(), 0, arraySize * sizeof(m_elem[0])); boost::scoped_array<int> count(new int[m_nodeCount]); memset(count.get(), 0, m_nodeCount * sizeof(count[0])); for (int32_t section = 0; section < checked_numeric_cast<int32_t>(___2724.m_numCellsPerSection.size()); ++section) { size_t ___2822 = static_cast<size_t>(___2724.m_numCellsPerSection[section] * ___2724.m_numNodesPerCellPerSection[section]); for (size_t i = 0; i < ___2822; ++i) { int64_t ___2710 = ___2724.value(section, i); ___476(0 <= ___2710 && ___2710 < m_nodeCount); ++count[___2710]; } } m_elemIndex[0] = 0; for (___2719 ___2710 = 0; ___2710 < m_nodeCount; ++___2710) { m_elemIndex[___2710 + 1] = m_elemIndex[___2710] + count[___2710]; count[___2710]           = 0; } ___463 baseCell = 0; for (int32_t section = 0; section < checked_numeric_cast<int32_t>(___2724.m_numCellsPerSection.size()); ++section) { int64_t const ___2782 = ___2724.m_numCellsPerSection[section];
 #if !defined TECIOMPI
int numThreads = (___2782 >= MIN_CELLS_FOR_MULTITHREAD) ? ___2121::___2828() : 1; if (numThreads == 1) {
 #endif
for (___463 ___447 = 0; ___447 < ___2782; ++___447) { int32_t nodesPerCell = ___2724.m_numNodesPerCellPerSection[section]; for (int32_t ___2710 = 0; ___2710 < nodesPerCell; ++___2710) { ___2719 ___2717 = ___2724.value(section, ___447 * nodesPerCell + ___2710); ___463 ind       = m_elemIndex[___2717] + count[___2717]; ++count[___2717]; ___476(m_elem[ind] == 0); m_elem[ind] = baseCell + ___447; } }
 #if !defined TECIOMPI
} else { boost::scoped_array<std::atomic<int>> atomiccount(new std::atomic<int>[m_nodeCount]); for (___2719 i = 0; i < m_nodeCount; ++i) atomiccount[i] = 0; std::vector<boost::shared_ptr<NodeToElemData>> nodeToElemData; for (int i = 0; i < numThreads; ++i) { ___463 begin = static_cast<___463>((size_t)___2724.m_numCellsPerSection[section] * i / numThreads); ___463 end = static_cast<___463>((size_t)___2724.m_numCellsPerSection[section] * (i + 1) / numThreads); nodeToElemData.push_back( boost::make_shared<NodeToElemData>( boost::cref(___2724), boost::cref(m_elemIndex), boost::ref(m_elem), boost::ref(atomiccount), section, baseCell, begin, end)); } ___2121 ___2118; for (int i = 0; i < numThreads; ++i) ___2118.addJob(fillElemArrayForCellRange, reinterpret_cast<___90>(nodeToElemData[i].get())); ___2118.wait(); }
 #endif
baseCell += ___2782; } } tecplot::___3934::___463 ___2744::cellCountForNode(tecplot::___3934::___2719 ___2710) { REQUIRE(0 <= ___2710 && ___2710 < m_nodeCount); return m_elemIndex[___2710 + 1] - m_elemIndex[___2710]; } }}

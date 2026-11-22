 #pragma once
#include "ThirdPartyHeadersBegin.h"
#include <algorithm>
#include <iterator>
#include <set>
#include <vector>
#include "ThirdPartyHeadersEnd.h"
#include "CodeContract.h"
#include "RawArray.h"
 #define ___2897(X, Y) ((int)(((X) - 1) / (Y) + 1) * (Y))
static size_t const ___3480 = 8 * sizeof(___3484); static size_t const ___3499 = static_cast<___3481>(1) << (___3480 - 1);
 #if defined _DEBUG
 #define USE_FUNCTIONS_FOR_SETS
 #endif
struct ___3503 { ___3494 size; ___3482 data; struct iterator { using iterator_category = std::bidirectional_iterator_tag; using difference_type   = std::ptrdiff_t; using value_type        = ___3494; using pointer           = ___3494*; using reference         = ___3494&; iterator(___3503 const* ___2099, ___3494 ___2402); iterator(iterator const&)            = default; iterator& operator=(iterator const&) = default; iterator(iterator&&)                 = default; iterator& operator=(iterator&&)      = default; ___3494 const& operator*() const; ___3494 const* operator->() const; iterator& operator++(); iterator  operator++(int); iterator& operator--(); iterator  operator--(int); friend bool operator==(iterator const& a, iterator const& b); friend bool operator!=(iterator const& a, iterator const& b); private: ___3503 const* m_itemSet; ___3494   m_member; }; iterator                        begin() const; iterator                        end() const; iterator                        cbegin() const; iterator                        cend() const; std::reverse_iterator<iterator> rbegin() const; std::reverse_iterator<iterator> rend() const; std::reverse_iterator<iterator> crbegin() const; std::reverse_iterator<iterator> crend() const; };
 #define ___2055(___3477) ((___3477) == NULL)
inline size_t ___3483(___3503 const* ___3477) { REQUIRE(VALID_REF(___3477)); return ___3477->size / ___3480 * sizeof(___3484); } ___3503* ___29(___372 ___3575); void ___937(___3503** ___3477); ___372 ___3497(void* ___2097, ___90 ___492); ___372 ___1199(___3503* ___3477, ___3494 max_val, ___372 ___3575); ___372 AllocAndCopySet(___3503*& ___1119, ___3503 const* ___3657); ___372 ___674(___3503* ___1119, ___3503 const* ___3657, ___372 ___3575); ___372 ___83(___3503* ___1119, ___3503 const* ___3657, ___372 ___3575); void ___491(___3503* ___3477);
 #if defined USE_FUNCTIONS_FOR_SETS
___372 ___17(___3503* ___3477, ___3494 ___2402, ___372 ___3575);
 #else
 #if defined __cplusplus
inline ___372 ___17(___3503* ___3477, ___3494 ___2402, ___372 ___3575) { if (___3477 && (___2402 + 1 <= ___3477->size || ___1199(___3477, ___2402 + 1, ___3575))) { ___3494        word = ___2402 / ___3480; ___3481 bit  = (___3481)1 << (___2402 % ___3480); ___3477->data[word] |= bit; return ___4227; } else return ___1303; }
 #elif defined TECPLOTKERNEL
 #define ___17(___3477, ___2402, ___3575)                                                                          \
 (((___3477) && ((___2402) + 1 <= (___3477)->size || ___1199((___3477), (___2402) + 1, (___3575))))                      \
 ? (((___3477)->data[(___2402) / ___3480].___1344((___3481)1 << ((___2402) % ___3480))), ___4227)      \
 : ___1303)
 #else
 #define ___17(___3477, ___2402, ___3575)                                                                          \
 (((___3477) && ((___2402) + 1 <= (___3477)->size || ___1199((___3477), (___2402) + 1, (___3575))))                      \
 ? (((___3477)->data[(___2402) / ___3480] |= (___3481)1 << ((___2402) % ___3480)), ___4227)             \
 : ___1303)
 #endif
 #endif
___372 AddRangeToSet(___3503* ___3477, ___3494 rangeStart, ___3494 rangeEnd); void ___3335(___3503* ___3477, ___3494 ___2402); void ___955(___3503* ___3477, ___3494 ___2403); ___372 ___1954(___3503* ___3477, ___3494 ___2403, ___372 ___3572);
 #if defined USE_FUNCTIONS_FOR_SETS
___372 ___1955(___3503 const* ___3477, ___3494 ___2402);
 #else
 #if defined __cplusplus
inline ___372 ___1955(___3503 const* ___3477, ___3494 ___2402) { if (___3477 && (0 <= ___2402 && ___2402 < ___3477->size)) { ___3494        word = ___2402 / ___3480; ___3481 bit  = (___3481)1 << (___2402 % ___3480); return (___3477->data[word] & bit) != 0; } else return ___1303; }
 #elif defined TECPLOTKERNEL
 #define ___1955(___3477, ___2402)                                                                                             \
 ((___3477 && (0 <= (___2402) && (___2402) < (___3477)->size))                                                                \
 ? ((___3477)->data[(___2402) / ___3480].load() & ((___3481)1 << ((___2402) % ___3480))) != 0        \
 : ___1303)
 #else
 #define ___1955(___3477, ___2402)                                                                                             \
 ((___3477 && (0 <= (___2402) && (___2402) < (___3477)->size))                                                                \
 ? ((___3477)->data[(___2402) / ___3480] & ((___3481)1 << ((___2402) % ___3480))) != 0               \
 : ___1303)
 #endif
 #endif
___372 ___2014(___3503 const* ___3477); ___372 ___1821(___3503 const* ___3477); ___3494 ___2404(___3503 const* ___3477); ___372 ___2032(___3503 const* ___3477); ___3494 ___1760(___3503 const* ___3477, ___3494 ___3683); ___3494 ___1768(___3503 const* ___3477, ___3494 ___3683); ___372 ___1173(___3503 const* ___3478, ___3503 const* ___3479); ___3503* intersection(___3503 const* ___3478, ___3503 const* ___3479); ___372 ___2061(___3503 const* ___484, ___3503 const* ___2974); ___3494 ___2405(___3503 const* ___3477, ___3494 ___2403); ___3494 ___2868(___3503 const* ___3477, ___3494 ___2867); ___372 ___675(___3503* ___1124, ___3494 ___1123, ___3503 const* ___3664, ___3494 ___3663); void ___3561(___3503* ___3477, ___3494 ___3559, ___3494 ___3560, ___3494 ___3557);
 #define ___1745(___3477) (___1760((___3477), ___333))
 #define ___1750(___3477)  (___1768((___3477), ___333))
 #define ___1470(___2403, ___3477)                                                                                        \
 for (___2403 = ___1745((___3477)); ___2403 != ___333; ___2403 = ___1760((___3477), (___2403)))
 #define ForAllMembersInEntIndexSet(___2403, ___3477)                                                                                \
 for (___2403 = static_cast<___1170>(___1745((___3477))); ___2403 != static_cast<___1170>(___333);         \
 ___2403 = static_cast<___1170>(___1760((___3477), (___2403))))
 #define ___1469(___2403, ___3477)                                                                                \
 for (___2403 = ___1750((___3477)); ___2403 != ___333; ___2403 = ___1768((___3477), (___2403)))
inline ___3503::iterator::iterator(___3503 const* ___2099, ___3494 ___2402) : m_itemSet{___2099} , m_member{___2402} {} inline ___3494 const& ___3503::iterator::operator*() const { return m_member; } inline ___3494 const* ___3503::iterator::operator->() const { return &m_member; } inline ___3503::iterator& ___3503::iterator::operator++() { m_member = ___1760(m_itemSet, m_member); return *this; } inline ___3503::iterator ___3503::iterator::operator++(int) { auto temp{*this}; ++(*this); return temp; } inline ___3503::iterator& ___3503::iterator::operator--() { m_member = ___1768(m_itemSet, m_member); return *this; } inline ___3503::iterator ___3503::iterator::operator--(int) { auto temp{*this}; --(*this); return temp; } inline bool operator==(___3503::iterator const& a, ___3503::iterator const& b) { return a.m_itemSet == b.m_itemSet && a.m_member == b.m_member; } inline bool operator!=(___3503::iterator const& a, ___3503::iterator const& b) { return a.m_itemSet != b.m_itemSet || a.m_member != b.m_member; } inline ___3503::iterator ___3503::begin() const { return ___3503::iterator{this, ___1760(this, ___333)}; } inline ___3503::iterator ___3503::cbegin() const { return begin(); } inline ___3503::iterator ___3503::end() const { return ___3503::iterator{this, ___333}; } inline ___3503::iterator ___3503::cend() const { return end(); } inline std::reverse_iterator<___3503::iterator> ___3503::rbegin() const { return std::reverse_iterator<___3503::iterator>(end()); } inline std::reverse_iterator<___3503::iterator> ___3503::rend() const { return std::reverse_iterator<___3503::iterator>(begin()); } inline std::reverse_iterator<___3503::iterator> ___3503::crbegin() const { return rbegin(); } inline std::reverse_iterator<___3503::iterator> ___3503::crend() const { return rend(); } namespace tecplot { template <typename T> std::vector<T> ___4195(___3503 const* ___2099) { REQUIRE(VALID_REF(___2099) || ___2099 == 0); std::vector<T> ___3359; size_t const   count = ___2404(___2099); if (count != 0) { ___3359.reserve(count); ___3494 ___2084; ___1470(___2084, ___2099) ___3359.push_back(static_cast<T>(___2084)); } return ___3359; } template <typename T> inline std::set<T> ___4187(___3503 const* set) { REQUIRE(VALID_REF_OR_NULL(set)); ___1170  value; std::set<T> ___3359; if (set != NULL) { ___1470(value, set) { ___3359.insert(static_cast<T>(value)); } } return ___3359; } template <typename CONTAINER> ___3503* ___4187(CONTAINER const& ___2098, bool isSorted = true) { REQUIRE(IMPLICATION( isSorted && !___2098.empty(), ___2098[___2098.size() - 1] == ___333 || ___2098[___2098.size() - 1] == *std::max_element(&___2098[0], &___2098[0] + ___2098.size()))); ___3503* ___3359 = ___29(___1303); if (___3359 == NULL) throw std::bad_alloc(); if (!___2098.empty()) { typename CONTAINER::value_type largestMember = static_cast<typename CONTAINER::value_type>(___333); if (isSorted) { for (typename CONTAINER::value_type const* iter = &___2098[___2098.size() - 1]; iter >= &___2098[0]; --iter) if ((largestMember = *iter) != static_cast<typename CONTAINER::value_type>(___333))
break; } else { largestMember = *std::max_element(&___2098[0], &___2098[0] + ___2098.size()); } if (largestMember != static_cast<typename CONTAINER::value_type>(___333)) { if (!___1199(___3359, static_cast<___3494>(largestMember + 1), ___1303)) { ___937(&___3359); throw std::bad_alloc(); } typename CONTAINER::value_type const* itemsArray = &___2098[0]; size_t const                          ___2813   = ___2098.size(); for (size_t ___1991 = 0; ___1991 < ___2813; ++___1991) if (itemsArray[___1991] != static_cast<typename CONTAINER::value_type>(___333)) (void)___17(___3359, static_cast<___3494>(itemsArray[___1991]), ___1303); } } ENSURE(VALID_REF(___3359)); return ___3359; } template <typename T> void ___4186(___3503 const* ___2099, ___3270<T>& ___3359) { REQUIRE(VALID_REF(___2099) || ___2099 == 0); size_t const count = ___2404(___2099); if (count != 0) { ___3359.reserve(count); ___3359.___3504(count); T*         ___3361 = &___3359[0]; size_t     ___2866      = 0; ___3494 ___2084; ___1470(___2084, ___2099) ___3361[___2866++] = static_cast<T>(___2084); } else { ___3359.___3504(0); } } }

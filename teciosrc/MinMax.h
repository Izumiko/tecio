 #pragma once
#include "ThirdPartyHeadersBegin.h"
#include <algorithm>
 #if __cplusplus >= 202302L
#include <bit>
 #endif
#include "ThirdPartyHeadersEnd.h"
#include "CodeContract.h"
class ___2480 : public std::pair<double, double> {
 #define INVALID_MINMAX_MIN_VALUE (10. * ___2178) 
 #define INVALID_MINMAX_MAX_VALUE (-10. * ___2178)
public: ___2480() { invalidate(); } ___2480(double newMin, double newMax) { first  = newMin; second = newMax; } explicit ___2480(double ___4299) { first  = ___4299; second = first; } inline void swap(___2480& ___2889) { using std::swap; swap(first, ___2889.first); swap(second, ___2889.second); } inline double minValue(void) const { return first; } inline double maxValue(void) const { return second; } inline void ___3500(double newMin, double newMax) { REQUIRE(newMin <= newMax); first  = newMin; second = newMax; } inline void ___3500(___2480 const& ___2889) { first  = ___2889.first; second = ___2889.second; } inline void include(double ___4299) { first  = std::min(first, ___4299); second = std::max(second, ___4299); } inline void include(___2480 const& minMax) { REQUIRE(minMax.___2066()); first  = std::min(first, minMax.first); second = std::max(second, minMax.second); } inline bool containsValue(double ___4299) const { return (first <= ___4299 && ___4299 <= second); } inline void invalidate(void) { first  = INVALID_MINMAX_MIN_VALUE; second = INVALID_MINMAX_MAX_VALUE; } inline bool ___2066(void) const {
 #if __cplusplus >= 202302L
REQUIRE(std::bit_cast<uint64_t>(first) != 0xcdcdcdcdcdcd || std::bit_cast<uint64_t>(second) != 0xcdcdcdcdcdcd);
 #endif
bool const valid = (first <= second); ___476(IMPLICATION(!valid, first == INVALID_MINMAX_MIN_VALUE && second == INVALID_MINMAX_MAX_VALUE)); return valid; } };

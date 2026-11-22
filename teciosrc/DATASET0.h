 #pragma once
void ___2890();
 #if !defined NO_ASSERTS && !defined NO_DEBUG_FIELDVALUES && !defined DEBUG_FIELDVALUES
 #define DEBUG_FIELDVALUES
 #endif
struct ___1360 { void*                    ___814; ___1381 ___1780; ___1382 ___3507; ZoneType_e               ___4692; FieldDataType_e          ___4335; ValueLocation_e          ___4327; ___1360(___2226 numIPts, ___2226 numJPts, ___2226 numKPts); ~___1360(); ___2226 iDim; ___2226 jDim; ___2226 kDim; ___2226 numIPts() const; ___2226 numJPts() const; ___2226 numKPts() const; }; inline void* ___1719(___1359 ___1350) { return ___1350->___814; } inline void ___3488(___1359 ___1350, void* ___3272) { ___1350->___814 = ___3272; } inline ___1381 ___1695(___1359 ___1350) { return ___1350->___1780; } inline ___1382 ___1722(___1359 ___1350) { return ___1350->___3507; } ___2226 ___1716(___1359 ___1350); inline ValueLocation_e ___1728(___1359 ___1350) { return ___1350->___4327; } inline FieldDataType_e ___1725(___1359 ___1350) { return ___1350->___4335; } double getUniformFieldValueAdapter(___1359 ___1349, ___2226 point); double ___1741(const ___1359 ___1306, ___2226 ___3250); double ___1740(const ___1359 ___1306, ___2226 ___3250); double ___1743(const ___1359 ___1306, ___2226 ___3250); double ___1742(const ___1359 ___1306, ___2226 ___3250); double ___1739(const ___1359 ___1306, ___2226 ___3250); double ___1738(const ___1359 ___1306, ___2226 ___3250); ___1381 DetermineFieldDataGetFunction(___1359 ___1349); ___1382 DetermineFieldDataSetFunction(___1359 ___1349); inline bool ___2018(___1359 ___1350) { return ___1719(___1350) != NULL; } typedef uint32_t ___1435; typedef uint64_t ___1109; typedef uint16_t ___1960; typedef uint32_t ___1965; typedef uint64_t ___1970; inline float* ___1689(___1359 ___1306) { return (float*)___1719(___1306); } inline ___1435* ___1692(___1359 ___1306) { return (___1435*)___1719(___1306); } inline double* ___1683(___1359 ___1306) { return (double*)___1719(___1306); } inline ___1109* ___1686(___1359 ___1306) { return (___1109*)___1719(___1306); } inline int64_t* ___1710(___1359 ___1306) { return (int64_t*)___1719(___1306); } inline ___1970* ___1713(___1359 ___1306) { return (___1970*)___1719(___1306); } inline int32_t* ___1704(___1359 ___1306) { return (int32_t*)___1719(___1306); } inline ___1965* ___1707(___1359 ___1306) { return (___1965*)___1719(___1306); } inline int16_t* ___1698(___1359 ___1306) { return (int16_t*)___1719(___1306); }
inline ___1960* ___1701(___1359 ___1306) { return (___1960*)___1719(___1306); } inline uint8_t* ___1680(___1359 ___1306) { return (uint8_t*)___1719(___1306); } inline uint16_t* ___1671(___1359 ___1306) { return (uint16_t*)___1719(___1306); } inline uint32_t* ___1674(___1359 ___1306) { return (uint32_t*)___1719(___1306); } inline uint64_t* ___1677(___1359 ___1306) { return (uint64_t*)___1719(___1306); } inline void* ___1731(___1359 ___1306) { return ___1719(___1306); } ___1359 ___28(___2226 ___2843, FieldDataType_e ___4237, ___372 ___3572); void ___936(___1359* ___3450); void ___432( ___1359 ___1351, double* min_ptr, double* max_ptr, ___2226 ___3685, ___1928* ___1927); void ___677( FieldDataType_e ___4335, void* ___1120, ___2226 ___1125, void const* ___3658, ___2226 ___3666, ___2226 ___3660); void ___3912( FieldDataType_e ___4335, void* ___3658, ___2226 ___3666, ___2226 ___3660, ___2226 ___3665); void ___3913( FieldDataType_e ___4335, void* ___3658, ___2226 ___3666, ___2226 ___3660, ___2226 ___3665); void ___672( ___1359 ___1119, ___2226 ___1126, ___1359 ___3657, ___2226 ___3667, ___2226 ___3661); void ___671(___1359 ___1119, ___1359 ___3657); void ___673(___1359 ___1119, ___2226 ___1122, ___1359 ___3657, ___2226 ___3662); void SetFieldDataArrayBytesToZero(___1359 ___1306); void ___3487(___1359 ___1351); inline double ___1734(___1359 ___1306, ___2226 ___3250) {
 #if !defined GET_FIELD_VALUE_BY_VIRTUAL_FUNCTION && !defined GET_FIELD_VALUE_BY_FLOAT_ONLY_TEST &&                             \
 !defined GET_FIELD_VALUE_BY_DOUBLE_ONLY_TEST && !defined GET_FIELD_VALUE_BY_FLOAT_AND_DOUBLE_TEST
 #if !defined NO_ASSERTS || defined DEBUG_FIELDVALUES
 #define GET_FIELD_VALUE_BY_VIRTUAL_FUNCTION
 #else
 #define GET_FIELD_VALUE_BY_FLOAT_AND_DOUBLE_TEST
 #endif
 #endif
 #if defined GET_FIELD_VALUE_BY_VIRTUAL_FUNCTION
return ___1695(___1306)(___1306, ___3250);
 #elif defined GET_FIELD_VALUE_BY_FLOAT_ONLY_TEST
return ___1695(___1306) == ___1741 ? ___1689(___1306)[___3250] : ___1695(___1306)(___1306, ___3250);
 #elif defined GET_FIELD_VALUE_BY_DOUBLE_ONLY_TEST
return ___1695(___1306) == ___1740 ? ___1683(___1306)[___3250] : ___1695(___1306)(___1306, ___3250);
 #elif defined GET_FIELD_VALUE_BY_FLOAT_AND_DOUBLE_TEST
return ___1695(___1306) == ___1741 ? ___1689(___1306)[___3250] : (___1695(___1306) == ___1740 ? ___1683(___1306)[___3250] : ___1695(___1306)(___1306, ___3250));
 #else
 #error "Need to define one of GET_FIELD_VALUE_BY_XXX constants"
 #endif
} inline void ___3491(___1359 ___1306, ___2226 ___3250, double ___4299) { ___1722(___1306)(___1306, ___3250, ___4299); }
 #if defined _DEBUG
 #define USEFUNCTIONSFORNODEVALUES
 #endif
___372 ___1353(___1359 ___1350, ___372 ___3572); void ___1356(___1359 ___1350); void ___1355(___1359* ___1350, ___372 ___1101);

 #pragma once
#include "CodeContract.h"
 #if !defined TECPLOTKERNEL
typedef struct ___135* ___134;
 #endif
typedef enum { ArrayListType_UInt8, ArrayListType_UInt16, ArrayListType_UInt32, ArrayListType_UInt64, ArrayListType_Int64, ArrayListType_Char, ArrayListType_Short, ArrayListType_Int, ArrayListType_Long, ArrayListType_Float, ArrayListType_Double, ArrayListType_LgIndex, ArrayListType_EntIndex, ArrayListType_SmInteger, ArrayListType_Boolean, ArrayListType_ArbParam, ArrayListType_UInt8Ptr, ArrayListType_UInt16Ptr, ArrayListType_UInt32Ptr, ArrayListType_UInt64Ptr, ArrayListType_Int64Ptr, ArrayListType_CharPtr, ArrayListType_ShortPtr, ArrayListType_IntPtr, ArrayListType_LongPtr, ArrayListType_FloatPtr, ArrayListType_DoublePtr, ArrayListType_LgIndexPtr, ArrayListType_EntIndexPtr, ArrayListType_SmIntegerPtr, ArrayListType_BooleanPtr, ArrayListType_ArbParamPtr, ArrayListType_VoidPtr, ArrayListType_FunctionPtr, ArrayListType_Any, END_ArrayListType_e, ArrayListType_Invalid = ___329 } ArrayListType_e; typedef union { uint8_t     UInt8; uint16_t    UInt16; uint32_t    UInt32; uint64_t    UInt64; int64_t     ___1968; char        ___470; short       Short; int         Int; long        Long; float       Float; double      Double; ___2226   ___2224; ___1170  ___1168; int32_t     ___3635; ___372   ___350; ___90  ___88; uint8_t*    UInt8Ptr; uint16_t*   UInt16Ptr; uint32_t*   UInt32Ptr; uint64_t*   UInt64Ptr; int64_t*    ___1969; char*       ___472; short*      ___3562; int*        ___1985; long*       ___2322; float*      ___1434; double*     ___1108; ___2226*  ___2225; ___1170* ___1169; int32_t*    ___3636; ___372*  ___371; ___90* ___89; void*       ___4440; void (*___1539)(); } ArrayListItem_u; typedef ___372 (*ArrayListItemVisitor_pf)(void* ___2097, ___90 ___492);
 #if 0 
{ REQUIRE(VALID_REF(___4240)); REQUIRE(VALID_REF(*___4240) || *___4240 == NULL); ___372 ___1094 = ___4227; <type>* ___4240 = static_cast<<type>*>(___2097); ENSURE(VALID_BOOLEAN(___1094)); return ___1094; }
 #endif
typedef ArrayListItemVisitor_pf ArrayListItemDestructor_pf; typedef ___372 (*ArrayListItemDuplicator_pf)(void* ___3950, void* ___3646, ___90 ___492);
 #if 0 
{ REQUIRE(VALID_REF(___3951)); REQUIRE(VALID_REF(___3647)); REQUIRE(VALID_REF(*___3647) || *___3647 == NULL); ___372 ___2039 = ___4227; <type>* ___3951 = static_cast<<type>*>(___3950); <type>* ___3647 = static_cast<<type>*>(___3646); ENSURE(VALID_BOOLEAN(___2039)); return ___2039; }
 #endif
typedef ___2226 (*ArrayListCapacityRequestAdjuster_pf)( ___134 ___94, ___2226 ___691, ___2226 ___3355, ___90 ___492);
 #if 0 
{ REQUIRE(ArrayListIsValid(___94)); REQUIRE((___3355 == 0 && ___691 == 0) || ___3355 > ___94->___437); ___2226 ___3360; ENSURE(___3360 == 0 || ___3360 >= ___3355); return ___3360; }
 #endif
struct ___135 { char*                               Array; ArrayListType_e                     ___4237; int32_t                             ___2101; ___2226                           ___682; ___2226                           ___437; ___372                           ___2079; ArrayListCapacityRequestAdjuster_pf ___438; ___90                          ___439; }; typedef int (*ArrayListItemComparator_pf)(ArrayListItem_u ___2086, ArrayListItem_u ___2087, ___90 ___492); ___372       ArrayListIsValid(___134 ___94); ArrayListType_e ArrayListGetType(___134 ___94); ___372       ArrayListEnlargeCapacity(___134 ___94, ___2226 ___3355); ___134    ArrayListAlloc( ___2226                           ___1186, ArrayListType_e                     ___4237, ArrayListCapacityRequestAdjuster_pf ___438           = 0, ___90                          ___439 = 0); void ArrayListDealloc(___134* ___94, ArrayListItemDestructor_pf ___2093 = 0, ___90 ___492 = 0); void ArrayListDeleteAllItems(___134 ___94, ArrayListItemDestructor_pf ___2093 = 0, ___90 ___492 = 0); void ArrayListDeleteItems( ___134               ___94, ___2226                  ___2096, ___2226                  ___682, ArrayListItemDestructor_pf ___2093 = 0, ___90                 ___492     = 0); void ArrayListDeleteItem( ___134 ___94, ___2226 ___2096, ArrayListItemDestructor_pf ___2093 = 0, ___90 ___492 = 0); ___134    ArrayListRemoveItems(___134 ___94, ___2226 ___2096, ___2226 ___682); ArrayListItem_u ArrayListRemoveItem(___134 ___94, ___2226 ___2096); ___372       ArrayListInsertItem(___134 ___94, ___2226 ___2096, ArrayListItem_u ___2085); ___372       ArrayListInsert(___134 ___3947, ___2226 ___2096, ___134 ___3643); ___372       ArrayListVisitItems( ___134 ___94, ___2226 ___2096, ___2226 ___682, ArrayListItemVisitor_pf ___2102, ___90 ___492); ___134    ArrayListGetItems(___134 ___94, ___2226 ___2096, ___2226 ___682); ArrayListItem_u ArrayListGetItem(___134 ___94, ___2226 ___2096); ___372       ArrayListSetItem( ___134               ___94, ___2226                  ___2096, ArrayListItem_u            ___2085, ArrayListItemDestructor_pf ___2093 = 0, ___90                 ___492     = 0); ___372    ArrayListAppendItem(___134 ___94, ArrayListItem_u ___2085); ___372    ArrayListAppend(___134 ___3947, ___134 ___3643); ___134 ArrayListCopy(___134 ___94, ArrayListItemDuplicator_pf ___2094 = 0, ___90 ___492 = 0); void*        ArrayListToArray(___134 ___94, ArrayListItemDuplicator_pf ___2094, ___90 ___492);
___134 ArrayListFromArray( void*                      ___3643, ___2226                  ___682, ArrayListType_e            ___4237, ArrayListItemDuplicator_pf ___2094 = 0, ___90                 ___492     = 0);
 #if !defined NO_ASSERTS
void runArrayListUnitTests();
 #endif
___372 ArrayListBSearch( ___134               ___94, ArrayListItem_u            ___2085, ArrayListItemComparator_pf ___533, ___90                 ___492, ___2226*                 ___2095 = 0);
 #if defined USE_MACROS_FOR_FUNCTIONS
 #define ___112 ___113
 #define ___115 ArrayListGetItemInternalRef_MACRO
 #define ___101           ArrayListGetCount_MACRO
 #define ___131(___94, ___2096)        ___124(___94, ___2096, uint8_t)
 #define ___125(___94, ___2096)       ___124(___94, ___2096, uint16_t)
 #define ___127(___94, ___2096)       ___124(___94, ___2096, uint32_t)
 #define ___129(___94, ___2096)       ___124(___94, ___2096, uint64_t)
 #define ___110(___94, ___2096)        ___124(___94, ___2096, int64_t)
 #define ___99(___94, ___2096)         ___124(___94, ___2096, char)
 #define ___120(___94, ___2096)        ___124(___94, ___2096, short)
 #define ___109(___94, ___2096)          ___124(___94, ___2096, int)
 #define ___118(___94, ___2096)         ___124(___94, ___2096, long)
 #define ___106(___94, ___2096)        ___124(___94, ___2096, float)
 #define ___102(___94, ___2096)       ___124(___94, ___2096, double)
 #define ___116(___94, ___2096)      ___124(___94, ___2096, ___2226)
 #define ___104(___94, ___2096)     ___124(___94, ___2096, ___1170)
 #define ___122(___94, ___2096)    ___124(___94, ___2096, int32_t)
 #define ___97(___94, ___2096)      ___124(___94, ___2096, ___372)
 #define ___95(___94, ___2096)     ___124(___94, ___2096, ___90)
 #define ___132(___94, ___2096)     ___124(___94, ___2096, uint8_t*)
 #define ___126(___94, ___2096)    ___124(___94, ___2096, uint16_t*)
 #define ___128(___94, ___2096)    ___124(___94, ___2096, uint32_t*)
 #define ___130(___94, ___2096)    ___124(___94, ___2096, uint64_t*)
 #define ___111(___94, ___2096)     ___124(___94, ___2096, int64_t*)
 #define ___100(___94, ___2096)      ___124(___94, ___2096, char*)
 #define ___121(___94, ___2096)     ___124(___94, ___2096, short*)
 #define ___114(___94, ___2096)       ___124(___94, ___2096, int*)
 #define ___119(___94, ___2096)      ___124(___94, ___2096, long*)
 #define ___107(___94, ___2096)     ___124(___94, ___2096, float*)
 #define ___103(___94, ___2096)    ___124(___94, ___2096, double*)
 #define ___117(___94, ___2096)   ___124(___94, ___2096, ___2226*)
 #define ___105(___94, ___2096)  ___124(___94, ___2096, ___1170*)
 #define ___123(___94, ___2096) ___124(___94, ___2096, int32_t*)
 #define ___98(___94, ___2096)   ___124(___94, ___2096, ___372*)
 #define ___96(___94, ___2096)  ___124(___94, ___2096, ___90*)
 #define ___133(___94, ___2096)      ___124(___94, ___2096, void*)
 #define ___108(___94, ___2096)  ___124(___94, ___2096, (**)(void))
 #else
 #define ___112     ArrayListGetInternalRef_FUNC
 #define ___115 ArrayListGetItemInternalRef_FUNC
 #define ___101           ArrayListGetCount_FUNC
 #define ___131(___94, ___2096)                                                                           \
 (*(static_cast<uint8_t*>(const_cast<void*>(ArrayListGetItemInternalRef_FUNC(___94, ___2096)))))
 #define ___125(___94, ___2096)                                                                          \
 (*(static_cast<uint16_t*>(const_cast<void*>(ArrayListGetItemInternalRef_FUNC(___94, ___2096)))))
 #define ___127(___94, ___2096)                                                                          \
 (*(static_cast<uint32_t*>(const_cast<void*>(ArrayListGetItemInternalRef_FUNC(___94, ___2096)))))
 #define ___129(___94, ___2096)                                                                          \
 (*(static_cast<uint64_t*>(const_cast<void*>(ArrayListGetItemInternalRef_FUNC(___94, ___2096)))))
 #define ___110(___94, ___2096)                                                                           \
 (*(static_cast<int64_t*>(const_cast<void*>(ArrayListGetItemInternalRef_FUNC(___94, ___2096)))))
 #define ___99(___94, ___2096)                                                                            \
 (*(static_cast<char*>(const_cast<void*>(ArrayListGetItemInternalRef_FUNC(___94, ___2096)))))
 #define ___120(___94, ___2096)                                                                           \
 (*(static_cast<short*>(const_cast<void*>(ArrayListGetItemInternalRef_FUNC(___94, ___2096)))))
 #define ___109(___94, ___2096)                                                                             \
 (*(static_cast<int*>(const_cast<void*>(ArrayListGetItemInternalRef_FUNC(___94, ___2096)))))
 #define ___118(___94, ___2096)                                                                            \
 (*(static_cast<long*>(const_cast<void*>(ArrayListGetItemInternalRef_FUNC(___94, ___2096)))))
 #define ___106(___94, ___2096)                                                                           \
 (*(static_cast<float*>(const_cast<void*>(ArrayListGetItemInternalRef_FUNC(___94, ___2096)))))
 #define ___102(___94, ___2096)                                                                          \
 (*(static_cast<double*>(const_cast<void*>(ArrayListGetItemInternalRef_FUNC(___94, ___2096)))))
 #define ___116(___94, ___2096)                                                                         \
 (*(static_cast<___2226*>(const_cast<void*>(ArrayListGetItemInternalRef_FUNC(___94, ___2096)))))
 #define ___104(___94, ___2096)                                                                        \
 (*(static_cast<___1170*>(const_cast<void*>(ArrayListGetItemInternalRef_FUNC(___94, ___2096)))))
 #define ___122(___94, ___2096)                                                                       \
 (*(static_cast<int32_t*>(const_cast<void*>(ArrayListGetItemInternalRef_FUNC(___94, ___2096)))))
 #define ___97(___94, ___2096)                                                                         \
 (*(static_cast<___372*>(const_cast<void*>(ArrayListGetItemInternalRef_FUNC(___94, ___2096)))))
 #define ___95(___94, ___2096)                                                                        \
 (*(static_cast<___90*>(const_cast<void*>(ArrayListGetItemInternalRef_FUNC(___94, ___2096)))))
 #define ___132(___94, ___2096)                                                                        \
 (*(static_cast<uint8_t**>(const_cast<void*>(ArrayListGetItemInternalRef_FUNC(___94, ___2096)))))
 #define ArrayListGetUInt16tPtr(___94, ___2096)                                                                      \
 (*(static_cast<uint16_t**>(const_cast<void*>(ArrayListGetItemInternalRef_FUNC(___94, ___2096)))))
 #define ArrayListGetUInt32tr(___94, ___2096)                                                                        \
 (*(static_cast<uint32_t**>(const_cast<void*>(ArrayListGetItemInternalRef_FUNC(___94, ___2096)))))
 #define ___130(___94, ___2096)                                                                       \
 (*(static_cast<uint64_t**>(const_cast<void*>(ArrayListGetItemInternalRef_FUNC(___94, ___2096)))))
 #define ___111(___94, ___2096)                                                                        \
 (*(static_cast<int64_t**>(const_cast<void*>(ArrayListGetItemInternalRef_FUNC(___94, ___2096)))))
 #define ___100(___94, ___2096)                                                                         \
 (*(static_cast<char**>(const_cast<void*>(ArrayListGetItemInternalRef_FUNC(___94, ___2096)))))
 #define ___121(___94, ___2096)                                                                        \
 (*(static_cast<short**>(const_cast<void*>(ArrayListGetItemInternalRef_FUNC(___94, ___2096)))))
 #define ___114(___94, ___2096)                                                                          \
 (*(static_cast<int**>(const_cast<void*>(ArrayListGetItemInternalRef_FUNC(___94, ___2096)))))
 #define ___119(___94, ___2096)                                                                         \
 (*(static_cast<long**>(const_cast<void*>(ArrayListGetItemInternalRef_FUNC(___94, ___2096)))))
 #define ___107(___94, ___2096)                                                                        \
 (*(static_cast<float**>(const_cast<void*>(ArrayListGetItemInternalRef_FUNC(___94, ___2096)))))
 #define ___103(___94, ___2096)                                                                       \
 (*(static_cast<double**>(const_cast<void*>(ArrayListGetItemInternalRef_FUNC(___94, ___2096)))))
 #define ___117(___94, ___2096)                                                                      \
 (*(static_cast<___2226**>(const_cast<void*>(ArrayListGetItemInternalRef_FUNC(___94, ___2096)))))
 #define ___105(___94, ___2096)                                                                     \
 (*(static_cast<___1170**>(const_cast<void*>(ArrayListGetItemInternalRef_FUNC(___94, ___2096)))))
 #define ___123(___94, ___2096)                                                                    \
 (*(static_cast<int32_t**>(const_cast<void*>(ArrayListGetItemInternalRef_FUNC(___94, ___2096)))))
 #define ___98(___94, ___2096)                                                                      \
 (*(static_cast<___372**>(const_cast<void*>(ArrayListGetItemInternalRef_FUNC(___94, ___2096)))))
 #define ___96(___94, ___2096)                                                                     \
 (*(static_cast<___90**>(const_cast<void*>(ArrayListGetItemInternalRef_FUNC(___94, ___2096)))))
 #define ___133(___94, ___2096)                                                                         \
 (*(static_cast<void**>(const_cast<void*>(ArrayListGetItemInternalRef_FUNC(___94, ___2096)))))
 #define ___108(___94, ___2096)                                                                     \
 (*(static_cast<**(void)*>(const_cast<void*>(ArrayListGetItemInternalRef_FUNC(___94, ___2096)))))
 #endif
 #if !defined USE_MACROS_FOR_FUNCTIONS
void const* ArrayListGetInternalRef_FUNC(___134 ___94); void const* ArrayListGetItemInternalRef_FUNC(___134 ___94, ___2226 ___2096); ___2226   ArrayListGetCount_FUNC(___134 ___94);
 #endif
 #define ___113(___94) static_cast<void const*>((___94)->Array)
 #define ArrayListGetItemInternalRef_MACRO(___94, ___2096)                                                               \
 static_cast<void const*>(&((___94)->Array[(___2096) * (___94)->___2101]))
 #define ArrayListGetCount_MACRO(___94)                       ((___94)->___682)
 #define ArrayListGetTypedArrayRef(___94, ___2689)         reinterpret_cast<___2689*>((___94)->Array)
 #define ___124(___94, ___2096, ___2689) (ArrayListGetTypedArrayRef(___94, ___2689)[___2096])
inline bool ArrayListOffsetWithinCapacity(___134 arrayList, ___2226 itemOffset) { REQUIRE(itemOffset >= 0); return itemOffset < arrayList->___437; }
 #define ___161(___94, ___2096, ___2085, ___2689)                                                         \
 ((ArrayListOffsetWithinCapacity((___94), (___2096)) || ArrayListEnlargeCapacity((___94), (___2096) + 1))     \
 ? ((void)((ArrayListGetTypedArrayRef((___94), ___2689)[(___2096)]) = (___2085)),                               \
 (((___2096) + 1 > (___94)->___682) ? (((___94)->___682 = (___2096) + 1), ___4227) : (___4227)))              \
 : (___1303))
 #define ArrayListAppendTypedItem(___94, ___2085, ___2689)                                                                  \
 ((ArrayListOffsetWithinCapacity((___94), (___94)->___682) ||                                                        \
 ArrayListEnlargeCapacity((___94), (___94)->___682 + 1))                                                           \
 ? ((void)((ArrayListGetTypedArrayRef((___94), ___2689)[(___94)->___682]) = (___2085)),                         \
 (((___94)->___682 = (___94)->___682 + 1), ___4227))                                                             \
 : (___1303))
 #define ___168(___94, ___2096, ___2085)      ___161((___94), (___2096), (___2085), uint8_t)
 #define ___162(___94, ___2096, ___2085)     ___161((___94), (___2096), (___2085), uint16_t)
 #define ___164(___94, ___2096, ___2085)     ___161((___94), (___2096), (___2085), uint32_t)
 #define ___166(___94, ___2096, ___2085)     ___161((___94), (___2096), (___2085), uint64_t)
 #define ___150(___94, ___2096, ___2085)      ___161((___94), (___2096), (___2085), int64_t)
 #define ___140(___94, ___2096, ___2085)       ___161((___94), (___2096), (___2085), char)
 #define ___157(___94, ___2096, ___2085)      ___161((___94), (___2096), (___2085), short)
 #define ___149(___94, ___2096, ___2085)        ___161((___94), (___2096), (___2085), int)
 #define ___155(___94, ___2096, ___2085)       ___161((___94), (___2096), (___2085), long)
 #define ___146(___94, ___2096, ___2085)      ___161((___94), (___2096), (___2085), float)
 #define ___142(___94, ___2096, ___2085)     ___161((___94), (___2096), (___2085), double)
 #define ___153(___94, ___2096, ___2085)    ___161((___94), (___2096), (___2085), ___2226)
 #define ___144(___94, ___2096, ___2085)   ___161((___94), (___2096), (___2085), ___1170)
 #define ___159(___94, ___2096, ___2085)  ___161((___94), (___2096), (___2085), int32_t)
 #define ___138(___94, ___2096, ___2085)    ___161((___94), (___2096), (___2085), ___372)
 #define ___136(___94, ___2096, ___2085)   ___161((___94), (___2096), (___2085), ___90)
 #define ___169(___94, ___2096, ___2085)   ___161((___94), (___2096), (___2085), uint8_t*)
 #define ___163(___94, ___2096, ___2085) ___161((___94), (___2096), (___2085), uint16_t*)
 #define ___165(___94, ___2096, ___2085)   ___161((___94), (___2096), (___2085), uint32_t*)
 #define ___167(___94, ___2096, ___2085)  ___161((___94), (___2096), (___2085), uint64_t*)
 #define ___151(___94, ___2096, ___2085)   ___161((___94), (___2096), (___2085), int64_t*)
 #define ___141(___94, ___2096, ___2085)    ___161((___94), (___2096), (___2085), char*)
 #define ___158(___94, ___2096, ___2085)   ___161((___94), (___2096), (___2085), short*)
 #define ___152(___94, ___2096, ___2085)     ___161((___94), (___2096), (___2085), int*)
 #define ___156(___94, ___2096, ___2085)    ___161((___94), (___2096), (___2085), long*)
 #define ___147(___94, ___2096, ___2085)   ___161((___94), (___2096), (___2085), float*)
 #define ___143(___94, ___2096, ___2085)  ___161((___94), (___2096), (___2085), double*)
 #define ___154(___94, ___2096, ___2085) ___161((___94), (___2096), (___2085), ___2226*)
 #define ___145(___94, ___2096, ___2085)                                                                   \
 ___161((___94), (___2096), (___2085), ___1170*)
 #define ___160(___94, ___2096, ___2085) ___161((___94), (___2096), (___2085), int32_t*)
 #define ___139(___94, ___2096, ___2085) ___161((___94), (___2096), (___2085), ___372*)
 #define ___137(___94, ___2096, ___2085)                                                                   \
 ___161((___94), (___2096), (___2085), ___90*)
 #define ___170(___94, ___2096, ___2085) ___161((___94), (___2096), (___2085), void*)
 #define ___148(___94, ___2096, ___2085)                                                                   \
 ___161((___94), (___2096), (___2085), (**)(void))
 #define ArrayListAppendUInt8(___94, ___2085)        ArrayListAppendTypedItem((___94), (___2085), uint8_t)
 #define ArrayListAppendUInt16(___94, ___2085)       ArrayListAppendTypedItem((___94), (___2085), uint16_t)
 #define ArrayListAppendUInt32(___94, ___2085)       ArrayListAppendTypedItem((___94), (___2085), uint32_t)
 #define ArrayListAppendUInt64(___94, ___2085)       ArrayListAppendTypedItem((___94), (___2085), uint64_t)
 #define ArrayListAppendInt64(___94, ___2085)        ArrayListAppendTypedItem((___94), (___2085), int64_t)
 #define ArrayListAppendChar(___94, ___2085)         ArrayListAppendTypedItem((___94), (___2085), char)
 #define ArrayListAppendShort(___94, ___2085)        ArrayListAppendTypedItem((___94), (___2085), short)
 #define ArrayListAppendInt(___94, ___2085)          ArrayListAppendTypedItem((___94), (___2085), int)
 #define ArrayListAppendLong(___94, ___2085)         ArrayListAppendTypedItem((___94), (___2085), long)
 #define ArrayListAppendFloat(___94, ___2085)        ArrayListAppendTypedItem((___94), (___2085), float)
 #define ArrayListAppendDouble(___94, ___2085)       ArrayListAppendTypedItem((___94), (___2085), double)
 #define ArrayListAppendLgIndex(___94, ___2085)      ArrayListAppendTypedItem((___94), (___2085), ___2226)
 #define ArrayListAppendEntIndex(___94, ___2085)     ArrayListAppendTypedItem((___94), (___2085), ___1170)
 #define ArrayListAppendSmInteger(___94, ___2085)    ArrayListAppendTypedItem((___94), (___2085), int32_t)
 #define ArrayListAppendBoolean(___94, ___2085)      ArrayListAppendTypedItem((___94), (___2085), ___372)
 #define ArrayListAppendArbParam(___94, ___2085)     ArrayListAppendTypedItem((___94), (___2085), ___90)
 #define ArrayListAppendUInt8Ptr(___94, ___2085)     ArrayListAppendTypedItem((___94), (___2085), uint8_t*)
 #define ArrayListAppendUInt16tPtr(___94, ___2085)   ArrayListAppendTypedItem((___94), (___2085), uint16_t*)
 #define ArrayListAppendUInt32tr(___94, ___2085)     ArrayListAppendTypedItem((___94), (___2085), uint32_t*)
 #define ArrayListAppendUInt64Ptr(___94, ___2085)    ArrayListAppendTypedItem((___94), (___2085), uint64_t*)
 #define ArrayListAppendInt64Ptr(___94, ___2085)     ArrayListAppendTypedItem((___94), (___2085), int64_t*)
 #define ArrayListAppendCharPtr(___94, ___2085)      ArrayListAppendTypedItem((___94), (___2085), char*)
 #define ArrayListAppendShortPtr(___94, ___2085)     ArrayListAppendTypedItem((___94), (___2085), short*)
 #define ArrayListAppendIntPtr(___94, ___2085)       ArrayListAppendTypedItem((___94), (___2085), int*)
 #define ArrayListAppendLongPtr(___94, ___2085)      ArrayListAppendTypedItem((___94), (___2085), long*)
 #define ArrayListAppendFloatPtr(___94, ___2085)     ArrayListAppendTypedItem((___94), (___2085), float*)
 #define ArrayListAppendDoublePtr(___94, ___2085)    ArrayListAppendTypedItem((___94), (___2085), double*)
 #define ArrayListAppendLgIndexPtr(___94, ___2085)   ArrayListAppendTypedItem((___94), (___2085), ___2226*)
 #define ArrayListAppendEntIndexPtr(___94, ___2085)  ArrayListAppendTypedItem((___94), (___2085), ___1170*)
 #define ArrayListAppendSmIntegerPtr(___94, ___2085) ArrayListAppendTypedItem((___94), (___2085), int32_t*)
 #define ArrayListAppendBooleanPtr(___94, ___2085)   ArrayListAppendTypedItem((___94), (___2085), ___372*)
 #define ArrayListAppendArbParamPtr(___94, ___2085)  ArrayListAppendTypedItem((___94), (___2085), ___90*)
 #define ArrayListAppendVoidPtr(___94, ___2085)      ArrayListAppendTypedItem((___94), (___2085), void*)
 #define ArrayListAppendFunctionPtr(___94, ___2085)  ArrayListAppendTypedItem((___94), (___2085), (**)(void))

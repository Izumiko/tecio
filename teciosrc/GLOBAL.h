 #pragma once
 #define _GLOBAL_H 
 #if !defined _MASTER_H_ && defined TECPLOTKERNEL
 #error "Must include MASTER.h before including GLOBAL.h"
 #endif
#include "ItemAddress.h"
#include "StandardIntegralTypes.h"
 #if defined MSWIN
 #define _USE_MATH_DEFINES 
#include <math.h>         
 #else
#include <cmath> 
 #endif
#include <limits>
 #define EXPORT_DEPRECATED_INTERFACES_TO_ADK_ONLY
 #if defined ___4227
 #undef ___4227
 #endif
 #if defined ___1303
 #undef ___1303
 #endif
 #if defined MIN
 #undef MIN
 #endif
 #if defined MAX
 #undef MAX
 #endif
 #if defined ___3420
 #undef ___3420
 #endif
 #if defined ___3421
 #undef ___3421
 #endif
 #if defined ___4228
 #undef ___4228
 #endif
 #define ___4227  ((___372)1)
 #define ___1303 ((___372)0)
 #if defined MSWIN
 #define STDABSINT64 _abs64
 #else
 #define STDABSINT64 std::abs
 #endif
 #define ___1(X)           ((X) >= 0 ? (X) : -(X))
 #define MAX(X, Y)        ((X) > (Y) ? (X) : (Y))
 #define MIN(X, Y)        ((X) < (Y) ? (X) : (Y))
 #define ___352(X) ((X) == ___4455 ? ___364 : ___4455)
 #define ___3424(X) ((BYTE)((X) + 0.499))
 #define ___3423(X)        ((short)((X) + 0.499))
 #define ROUND32(X)       ((int32_t)((X) + 0.499))
 #define ___3422(X)        ((___2226)((X) + 0.499))
 #define ___3421(X)        ((X) >= 0 ? ((int)((X) + 0.499)) : ((int)((X) - 0.499)))
 #define ___4228(X)         ((short)(X))
 #define ___3268(___3267)  (180. * (___3267) / M_PI)
 #define ___953(___951)  (M_PI * (___951) / 180.)
 #define ___442(C) ((char)(('a' <= (C) && (C) <= 'z') ? ((C) + ('A' - 'a')) : (C))) 
 #define ___2016(S) (((const char*)(S))[0] == '\0')
 #define ___2081(C) ((C == ' ') || (C == '\t') || (C == '\n'))
 #define ___2054(C)  ((C == ' ') || (C == '\t') || (C == ','))
 #define ___486(value, ___2325, ___1829) ((value) < (___2325) ? (___2325) : (value) > (___1829) ? (___1829) : (value))
 #define ___1973(n, d) (((int)(n) + (int)(d) - 1) / (int)(d))
 #define ___1853(___799, ___1831, ___2105, ___2134) ((___1831) + ((___2105) * (___799)->___2810) + ((___2134) * (___799)->___2808))
 #define ___1841(___799, N) ((N) % (___799)->___2810)
 #define ___2111(___799, N) (((N) % (___799)->___2808) / (___799)->___2810)
 #define ___2156(___799, N) ((N) / (___799)->___2808)
 #define ___1926(index, ___3604) ((___3604) == 1 || ((index) % (___3604) == 0))
 #define ___3914(___4237, A, B)                                                                                                     \
 do                                                                                                                         \
 {                                                                                                                          \
 ___4237 T = (A);                                                                                                          \
 (A)    = (B);                                                                                                          \
 (B)    = T;                                                                                                            \
 } while (___1303)
 #define ___3915(A, B) ___3914(double, (A), (B))
 #define ___1480(x)         (___372)((x) > 0)
 #define ___1806(F)     (((F)->___3113 == ___3116))
 #if defined ___4279
 #undef ___4279
 #endif
 #define ___4279(___2972) (void)___2972
 #define ___648(___4299)                                                                                           \
 ((___4299) >= ___3633 ? ((___4299) < ___2179 ? (float)(___4299) : (float)___2179)                                             \
 : ((___4299) <= -___3633 ? ((___4299) > -___2179 ? (float)(___4299) : (float)-___2179) : (float)0.0))
 #define ___487(___4299)                                                                                                      \
 ((___4299) >= ___3629                                                                                                      \
 ? ((___4299) < ___2178 ? (double)(___4299) : (double)___2178)                                                         \
 : ((___4299) <= -___3629 ? ((___4299) > -___2178 ? (double)(___4299) : (double)-___2178) : (double)0.0))
 #define ___650(___4299)                                                                                           \
 ((___4299) >= 1.0 ? ((___4299) < ___2181 ? (int32_t)(___4299) : (int32_t)___2181)                                                \
 : ((___4299) <= -1.0 ? ((___4299) > (int32_t)-___2181 ? (int32_t)(___4299) : (int32_t)-___2181) : (int32_t)0.0))
 #define ___649(___4299)                                                                                           \
 ((___4299) >= 1.0 ? ((___4299) < ___2180 ? (int16_t)(___4299) : (int16_t)___2180)                                                \
 : ((___4299) <= -1.0 ? ((___4299) > (int16_t)-___2180 ? (int16_t)(___4299) : (int16_t)-___2180) : (int16_t)0.0))
 #define CONVERT_DOUBLE_TO_UINT8(___4299) ((___4299) >= 1.0 ? ((___4299) < 255.0 ? (uint8_t)(___4299) : 255) : 0)
 #define ___665(___1121, ___3659)                                                                           \
 do                                                                                                                         \
 {                                                                                                                          \
                                               \
                                                     \
 ((uint8_t*)(___1121))[0] = ((uint8_t*)(___3659))[0];                                                               \
 ((uint8_t*)(___1121))[1] = ((uint8_t*)(___3659))[1];                                                               \
 } while (___1303)
 #define ___668(___1121, ___3659)                                                               \
 do                                                                                                                         \
 {                                                                                                                          \
                                               \
                                                     \
 ((uint8_t*)(___1121))[0] = ((uint8_t*)(___3659))[1];                                                               \
 ((uint8_t*)(___1121))[1] = ((uint8_t*)(___3659))[0];                                                               \
 } while (___1303)
 #define ___666(___1121, ___3659)                                                                           \
 do                                                                                                                         \
 {                                                                                                                          \
                                               \
                                                     \
 ((uint8_t*)(___1121))[0] = ((uint8_t*)(___3659))[0];                                                               \
 ((uint8_t*)(___1121))[1] = ((uint8_t*)(___3659))[1];                                                               \
 ((uint8_t*)(___1121))[2] = ((uint8_t*)(___3659))[2];                                                               \
 ((uint8_t*)(___1121))[3] = ((uint8_t*)(___3659))[3];                                                               \
 } while (___1303)
 #define ___669(___1121, ___3659)                                                               \
 do                                                                                                                         \
 {                                                                                                                          \
                                               \
                                                     \
 ((uint8_t*)(___1121))[0] = ((uint8_t*)(___3659))[3];                                                               \
 ((uint8_t*)(___1121))[1] = ((uint8_t*)(___3659))[2];                                                               \
 ((uint8_t*)(___1121))[2] = ((uint8_t*)(___3659))[1];                                                               \
 ((uint8_t*)(___1121))[3] = ((uint8_t*)(___3659))[0];                                                               \
 } while (___1303)
 #define ___667(___1121, ___3659)                                                                           \
 do                                                                                                                         \
 {                                                                                                                          \
                                               \
                                                     \
 ((uint8_t*)(___1121))[0] = ((uint8_t*)(___3659))[0];                                                               \
 ((uint8_t*)(___1121))[1] = ((uint8_t*)(___3659))[1];                                                               \
 ((uint8_t*)(___1121))[2] = ((uint8_t*)(___3659))[2];                                                               \
 ((uint8_t*)(___1121))[3] = ((uint8_t*)(___3659))[3];                                                               \
 ((uint8_t*)(___1121))[4] = ((uint8_t*)(___3659))[4];                                                               \
 ((uint8_t*)(___1121))[5] = ((uint8_t*)(___3659))[5];                                                               \
 ((uint8_t*)(___1121))[6] = ((uint8_t*)(___3659))[6];                                                               \
 ((uint8_t*)(___1121))[7] = ((uint8_t*)(___3659))[7];                                                               \
 } while (___1303)
 #define ___670(___1121, ___3659)                                                               \
 do                                                                                                                         \
 {                                                                                                                          \
                                               \
                                                     \
 ((uint8_t*)(___1121))[0] = ((uint8_t*)(___3659))[7];                                                               \
 ((uint8_t*)(___1121))[1] = ((uint8_t*)(___3659))[6];                                                               \
 ((uint8_t*)(___1121))[2] = ((uint8_t*)(___3659))[5];                                                               \
 ((uint8_t*)(___1121))[3] = ((uint8_t*)(___3659))[4];                                                               \
 ((uint8_t*)(___1121))[4] = ((uint8_t*)(___3659))[3];                                                               \
 ((uint8_t*)(___1121))[5] = ((uint8_t*)(___3659))[2];                                                               \
 ((uint8_t*)(___1121))[6] = ((uint8_t*)(___3659))[1];                                                               \
 ((uint8_t*)(___1121))[7] = ((uint8_t*)(___3659))[0];                                                               \
 } while (___1303)
 #define ___3366(___417)                                                                                    \
 do                                                                                                                         \
 {                                                                                                                          \
 uint8_t ___423 = ((uint8_t*)(___417))[0];                                                                               \
 ___476(sizeof(*(___417)) == 1 || sizeof(*(___417)) == 2);                                                               \
 ((uint8_t*)(___417))[0] = ((uint8_t*)(___417))[1];                                                                     \
 ((uint8_t*)(___417))[1] = ___423;                                                                                       \
 } while (___1303)
 #define ___3367(___417)                                                                                    \
 do                                                                                                                         \
 {                                                                                                                          \
 uint16_t ___826 = ((uint16_t*)(___417))[0];                                                                         \
 ___476(sizeof(*(___417)) == 1 || sizeof(*(___417)) == 2);                                                               \
 ((uint16_t*)(___417))[0] = (((___826) << 8) | ((___826 & 0xff)));                                                \
 } while (___1303)
 #define ___3365 ___3366
 #define ___3369(___417)                                                                                    \
 do                                                                                                                         \
 {                                                                                                                          \
 uint8_t ___423 = ((uint8_t*)(___417))[0];                                                                               \
 uint8_t ___424 = ((uint8_t*)(___417))[1];                                                                               \
 ___476(sizeof(*(___417)) == 1 || sizeof(*(___417)) == 4);                                                               \
 ((uint8_t*)(___417))[0] = ((uint8_t*)(___417))[3];                                                                     \
 ((uint8_t*)(___417))[1] = ((uint8_t*)(___417))[2];                                                                     \
 ((uint8_t*)(___417))[2] = ___424;                                                                                       \
 ((uint8_t*)(___417))[3] = ___423;                                                                                       \
 } while (___1303)
 #define ___3370(___417)                                                                                    \
 do                                                                                                                         \
 {                                                                                                                          \
 uint32_t ___826 = *((uint32_t*)(___417));                                                                           \
 ___476(sizeof(*(___417)) == 1 || sizeof(*(___417)) == 4);                                                               \
 *((uint32_t*)(___417)) =                                                                                               \
 (((___826) << 24) | ((___826 & 0x0000ff00) << 8) | ((___826 & 0x00ff0000) >> 8) | ((___826) >> 24));   \
 } while (___1303)
 #if defined MSWIN
 #define ___3368 ___3370
 #else
 #define ___3368 ___3369
 #endif
 #define ___3372(___417)                                                                                    \
 do                                                                                                                         \
 {                                                                                                                          \
 uint8_t ___423 = ((uint8_t*)(___417))[0];                                                                               \
 uint8_t ___424 = ((uint8_t*)(___417))[1];                                                                               \
 uint8_t ___425 = ((uint8_t*)(___417))[2];                                                                               \
 uint8_t ___426 = ((uint8_t*)(___417))[3];                                                                               \
 ___476(sizeof(*(___417)) == 1 || sizeof(*(___417)) == 8);                                                               \
 ((uint8_t*)(___417))[0] = ((uint8_t*)(___417))[7];                                                                     \
 ((uint8_t*)(___417))[1] = ((uint8_t*)(___417))[6];                                                                     \
 ((uint8_t*)(___417))[2] = ((uint8_t*)(___417))[5];                                                                     \
 ((uint8_t*)(___417))[3] = ((uint8_t*)(___417))[4];                                                                     \
 ((uint8_t*)(___417))[4] = ___426;                                                                                       \
 ((uint8_t*)(___417))[5] = ___425;                                                                                       \
 ((uint8_t*)(___417))[6] = ___424;                                                                                       \
 ((uint8_t*)(___417))[7] = ___423;                                                                                       \
 } while (___1303)
 #define ___3373(___417)                                                                                    \
 do                                                                                                                         \
 {                                                                                                                          \
 uint16_t ___827 = ((uint16_t*)(___417))[0];                                                                       \
 uint16_t ___828 = ((uint16_t*)(___417))[1];                                                                       \
 uint16_t ___829 = ((uint16_t*)(___417))[2];                                                                       \
 uint16_t ___830 = ((uint16_t*)(___417))[3];                                                                       \
 ___476(sizeof(*(___417)) == 1 || sizeof(*(___417)) == 8);                                                               \
 ((uint16_t*)(___417))[0] = (((___830) << 8) | ((___830 & 0xff)));                                            \
 ((uint16_t*)(___417))[1] = (((___829) << 8) | ((___829 & 0xff)));                                            \
 ((uint16_t*)(___417))[2] = (((___828) << 8) | ((___828 & 0xff)));                                            \
 ((uint16_t*)(___417))[3] = (((___827) << 8) | ((___827 & 0xff)));                                            \
 } while (___1303)
 #define ___3374(___417)                                                                                    \
 do                                                                                                                         \
 {                                                                                                                          \
 uint32_t ___827 = ((uint32_t*)(___417))[0];                                                                       \
 uint32_t ___828 = ((uint32_t*)(___417))[1];                                                                       \
 ___476(sizeof(*(___417)) == 1 || sizeof(*(___417)) == 8);                                                               \
 ((uint32_t*)(___417))[0] =                                                                                             \
 (((___828) << 24) | ((___828 & 0x0000ff00) << 8) | ((___828 & 0x00ff0000) >> 8) |                   \
 ((___828) >> 24));                                                                                           \
 ((uint32_t*)(___417))[1] =                                                                                             \
 (((___827) << 24) | ((___827 & 0x0000ff00) << 8) | ((___827 & 0x00ff0000) >> 8) |                   \
 ((___827) >> 24));                                                                                           \
 } while (___1303)
 #define ___3375(___417)                                                                                    \
 do                                                                                                                         \
 {                                                                                                                          \
 uint64_t ___826 = *((uint64_t*)(___417));                                                                           \
 ___476(sizeof(*(___417)) == 1 || sizeof(*(___417)) == 8);                                                               \
 *((uint64_t*)(___417)) =                                                                                               \
 (((___826) << 56) | ((___826 & 0x000000000000ff00) << 40) | ((___826 & 0x0000000000ff0000) << 24) |       \
 ((___826 & 0x00000000ff000000) << 8) | ((___826 & 0x000000ff00000000) >> 8) |                               \
 ((___826 & 0x0000ff0000000000) >> 24) | ((___826 & 0x00ff000000000000) >> 40) | ((___826) >> 56));       \
 } while (___1303)
 #if defined MSWIN
 #define ___3371 ___3374
 #else
 #define ___3371 ___3372
 #endif
 #define STDCALL 
 #if defined(__cplusplus)
 #define EXTERNC             extern "C"
 #define TP_GLOBAL_NAMESPACE ::
 #else
 #define EXTERNC
 #define TP_GLOBAL_NAMESPACE
 #endif 
 #if defined MAKEARCHIVE
 #define tpsdkbase_API
 #else
#include "tpsdkbase_Exports.h"
 #endif
 #define ___2292 EXTERNC tpsdkbase_API
 #if defined MSWIN
 #define ___1233 EXTERNC _declspec(dllexport)
 #else
 #define ___1233 EXTERNC __attribute__((visibility("default")))
 #endif 
 #define ___1234          ___1233
 #define ___1938           ___1939
 #define ___3970 "InitTecAddOn113"
 #if defined(__cplusplus) && !defined _DEBUG
 #define ___1940 inline
 #else
 #define ___1940 static
 #endif 
 #if defined(MSWIN) || defined(___1984) || defined(LINUX) || defined(___3892) || defined(___532) || defined(DEC) ||   \
 defined(__LITTLE_ENDIAN__)
 #define ___2327
 #endif
 #if defined(___2327)
 #define ___3911(___1976) (!(___1976))
 #else
 #define ___3911(___1976) (___1976)
 #endif
 #if defined DECALPHA || defined LINUXALPHA || defined LINUX64 || defined MAC64 || defined ___1832 || defined ___3887 ||          \
 defined ___1830 || defined ___532
 #define ___2321
 #endif
 #define ___2184 ((size_t)-1)
 #define ___2182 (std::numeric_limits<int64_t>::max() - 1)
 #define ___2181 (std::numeric_limits<int32_t>::max() - 1)
 #define ___2180 (std::numeric_limits<int16_t>::max() - 1)
 #define ___2183  (std::numeric_limits<int8_t>::max() - 1)
 #define ___2192 (std::numeric_limits<uint64_t>::max() - 1)
 #define ___2191 (std::numeric_limits<uint32_t>::max() - 1)
 #define ___2190 (std::numeric_limits<uint16_t>::max() - 1)
 #define ___2193  (std::numeric_limits<uint8_t>::max() - 1)
 #ifdef INDEX_16_BIT
 #define ___2374 ((___2226)___2180)
 #else
 #define ___2374 ((___2226)(___2182 >> 1))
 #endif
 #define ___2392       ((___1170)___2181)
 #define ___2178      1.0e+150
 #define ___3629      1.0e-150
 #define ___2189  150
 #define ___3632 -150
 #define ___3630 ___3629
 #define ___2188  308
 #define ___3631 -307
 #define ___2187          1.0e+308
 #define ___2179             std::numeric_limits<float>::max() 
 #define ___3633             std::numeric_limits<float>::min() 
 #define ___3634          1.0e-307
 #define ___1187                 3
 #define ___2297                 0.69314718055994530942
 #define ___2296                2.30258509299404568402
 #define ___3089             1.57079632679489661923
 #define ___4236               6.28318530717958647692
 #define ___58        1.0e-10
 #define ___2186        (4 * M_PI + ___58)
 #define ___952       57.295779513082323
 #define ___504           2.54
 #define ___3144       72.0
 #define ___1458        192
 #define ___1445    128
 #define ___1456        64
 #define ___333       ((___3494) - 1)
 #define ___334      (static_cast<___1170>(-1))
 #define BAD_ZONE_OFFSET     (static_cast<___1170>(-1))
 #define BAD_FIELDMAP_OFFSET (static_cast<___1170>(-1))
 #define ___2421 (0)
 #define ___2422  (-1)
 #define ___1990   0
 #define VALID_UNIQUEID(uniqueID) ((uniqueID) != ___1990)
 #define NO_EMBEDDED_LPK_IMAGE_NUMBER 0
 #define ___332        ___333
 #define ___3638 0
 #define ___328       (-1.0)
 #define ___2474 4
 #define ___4313(___3787) (0 <= (___3787) && (___3787) < ___2392)
 #define ___3789          (-1)
 #define ___3788         (-2)
 #if defined DEFER_TRANSIENT_OPERATIONS
 #define STRAND_ID_INVALID (-3)
 #endif
 #define INVALID_PART_INDEX (-1)
 #define ___2348    1
 #define ___2349    6
 #define ___1986          -1
 #define ___4302(clipPlane) (0 <= clipPlane && clipPlane < ___2349)
 #define ___2383           ___2392
 #define ___2390                    5
 #define ___2391                    5
 #define ___2372              50
 #define ___2385       720
 #define ___2371                   2048
 #define ___2366          10
 #define ___2370                20000
 #define ___2363        16
 #define ___2384           16
 #define ___2473      12
 #define ___2360      360
 #define ___2389    8
 #define ___2364            8
 #define ___2375         8
 #define ___2376 3
 #define ___2387              8
 #define MaxNumHOESubdivisionLevels  5
 #define ___950 15
 #define ___946        ((int32_t)0)
 #define ___945      ((int32_t)0)
 #define ___949 ((int32_t)0)
 #define ___331             ((int32_t)-1)
 #define ___4280          ((int32_t)0)
 #define ___327          ((int32_t)-1)
 #define ___4308(___1816) (((((int32_t)___1816) >= 0) && (((int32_t)___1816) < ___2375)))
 #define ___4312(___1816)      (((((int32_t)___1816) >= 0) && (((int32_t)___1816) < ___2387)))
 #define ___2350 6
 #define ___2356 256
 #define ___2359      128
 #define ___2357      128
 #define ___2358  128
 #define ___2354 32000
 #define ___2355   1024
 #define ___2382              16
 #define ___2351            5
 #define ___2361 50
 #define ___2386    800
 #define ___2368        100
 #define ___2369     100
 #define ___2362        20
 #define ___2483 0.5
 #define ___2477         0.25
 #define ___2476        0.25
 #define ___2472         0.1
 #define ___329 255
 #define MAX_NODES_PER_CLASSIC_FACE    4
 #define MAX_NODES_PER_CLASSIC_ELEMENT 8
 #define MAX_HOE_FACE_NODES_PER_ELEM   size_t(25)  
 #define MAX_HOE_NODES_PER_ELEM        size_t(125) 
 #define MAX_NODES_PER_ELEM            size_t(125)
 #define MAX_FACE_NODES_PER_ELEM       size_t(25)
 #define ___3869 16
 #define AuxData_Common_Incompressible        "Common.Incompressible"
 #define AuxData_Common_Density               "Common.Density"
 #define AuxData_Common_SpecificHeat          "Common.SpecificHeat"
 #define AuxData_Common_SpecificHeatVar       "Common.SpecificHeatVar"
 #define AuxData_Common_GasConstant           "Common.GasConstant"
 #define AuxData_Common_GasConstantVar        "Common.GasConstantVar"
 #define AuxData_Common_Gamma                 "Common.Gamma"
 #define AuxData_Common_GammaVar              "Common.GammaVar"
 #define AuxData_Common_Viscosity             "Common.Viscosity"
 #define AuxData_Common_ViscosityVar          "Common.ViscosityVar"
 #define AuxData_Common_Conductivity          "Common.Conductivity"
 #define AuxData_Common_ConductivityVar       "Common.ConductivityVar"
 #define AuxData_Common_AngleOfAttack         "Common.AngleOfAttack"
 #define AuxData_Common_SpeedOfSound          "Common.SpeedOfSound"
 #define AuxData_Common_ReferenceU            "Common.ReferenceU"
 #define AuxData_Common_ReferenceV            "Common.ReferenceV"
 #define AuxData_Common_XVar                  "Common.XVar"
 #define AuxData_Common_YVar                  "Common.YVar"
 #define AuxData_Common_ZVar                  "Common.ZVar"
 #define AuxData_Common_CVar                  "Common.CVar"
 #define AuxData_Common_UVar                  "Common.UVar"
 #define AuxData_Common_VVar                  "Common.VVar"
 #define AuxData_Common_WVar                  "Common.WVar"
 #define AuxData_Common_VectorVarsAreVelocity "Common.VectorVarsAreVelocity"
 #define AuxData_Common_PressureVar           "Common.PressureVar"
 #define AuxData_Common_TemperatureVar        "Common.TemperatureVar"
 #define AuxData_Common_DensityVar            "Common.DensityVar"
 #define AuxData_Common_StagnationEnergyVar   "Common.StagnationEnergyVar"
 #define AuxData_Common_MachNumberVar         "Common.MachNumberVar"
 #define AuxData_Common_ReferenceMachNumber   "Common.ReferenceMachNumber"
 #define AuxData_Common_ReferenceW            "Common.ReferenceW"
 #define AuxData_Common_PrandtlNumber         "Common.PrandtlNumber"
 #define AuxData_Common_Axisymmetric          "Common.Axisymmetric"
 #define AuxData_Common_AxisOfSymmetryVarAssignment                                                                             \
 "Common.AxisOfSymmetryVarAssignment"
 #define AuxData_Common_AxisValue                 "Common.AxisValue"
 #define AuxData_Common_SteadyState               "Common.SteadyState"
 #define AuxData_Common_TurbulentKineticEnergyVar "Common.TurbulentKineticEnergyVar"
 #define AuxData_Common_TurbulentDissipationRateVar                                                                             \
 "Common.TurbulentDissipationRateVar"
 #define AuxData_Common_TurbulentDynamicViscosityVar                                                                            \
 "Common.TurbulentDynamicViscosityVar"
 #define AuxData_Common_TurbulentViscosityVar                                                                                   \
 "Common.TurbulentViscosityVar"
 #define AuxData_Common_TurbulentFrequencyVar   "Common.TurbulentFrequencyVar"
 #define AuxData_Common_Gravity                 "Common.Gravity"
 #define AuxData_Common_IsBoundaryZone          "Common.IsBoundaryZone"
 #define AuxData_Common_BoundaryCondition       "Common.BoundaryCondition"
 #define AuxData_Common_Time                    "Common.Time"
 #define AuxData_Common_PartName                "Common.PartName"
 #define AuxData_Common_Mean                    "Common.Mean"
 #define AuxData_Common_Median                  "Common.Median"
 #define AuxData_Common_Variance                "Common.Variance"
 #define AuxData_Common_StdDev                  "Common.StdDev"
 #define AuxData_Common_AvgDev                  "Common.AvgDev"
 #define AuxData_Common_GeoMean                 "Common.GeoMean"
 #define AuxData_Common_ChiSqre                 "Common.ChiSqre"
 #define AuxData_Common_TransientZoneVisibility "Common.TransientZoneVisibility"
 #define frameUniqueIDKey "frame.uniqueID"
 #define ___364  ((___514)0)
 #define ___3302    ((___514)1)
 #define ___1809  ((___514)2)
 #define ___366   ((___514)3)
 #define ___797   ((___514)4)
 #define ___4587 ((___514)5)
 #define ___3257 ((___514)6)
 #define ___4455  ((___514)7)
 #define ___743 ((___514)8)
 #define ___754 ((___514)9)
 #define ___765 ((___514)10)
 #define ___776 ((___514)11)
 #define ___784 ((___514)12)
 #define ___785 ((___514)13)
 #define ___786 ((___514)14)
 #define ___787 ((___514)15)
 #define ___788 ((___514)16)
 #define ___733 ((___514)17)
 #define ___734 ((___514)18)
 #define ___735 ((___514)19)
 #define ___736 ((___514)20)
 #define ___737 ((___514)21)
 #define ___738 ((___514)22)
 #define ___739 ((___514)23)
 #define ___740 ((___514)24)
 #define ___741 ((___514)25)
 #define ___742 ((___514)26)
 #define ___744 ((___514)27)
 #define ___745 ((___514)28)
 #define ___746 ((___514)29)
 #define ___747 ((___514)30)
 #define ___748 ((___514)31)
 #define ___749 ((___514)32)
 #define ___750 ((___514)33)
 #define ___751 ((___514)34)
 #define ___752 ((___514)35)
 #define ___753 ((___514)36)
 #define ___755 ((___514)37)
 #define ___756 ((___514)38)
 #define ___757 ((___514)39)
 #define ___758 ((___514)40)
 #define ___759 ((___514)41)
 #define ___760 ((___514)42)
 #define ___761 ((___514)43)
 #define ___762 ((___514)44)
 #define ___763 ((___514)45)
 #define ___764 ((___514)46)
 #define ___766 ((___514)47)
 #define ___767 ((___514)48)
 #define ___768 ((___514)49)
 #define ___769 ((___514)50)
 #define ___770 ((___514)51)
 #define ___771 ((___514)52)
 #define ___772 ((___514)53)
 #define ___773 ((___514)54)
 #define ___774 ((___514)55)
 #define ___775 ((___514)56)
 #define ___777 ((___514)57)
 #define ___778 ((___514)58)
 #define ___779 ((___514)59)
 #define ___780 ((___514)60)
 #define ___781 ((___514)61)
 #define ___782 ((___514)62)
 #define ___783 ((___514)63)
 #define ___2663   ((___514)(-1))
 #define ___2709      ((___514)(-2))
 #define ___2656  ((___514)(-3))
 #define ___2657  ((___514)(-4))
 #define ___2658  ((___514)(-5))
 #define ___3376     ((___514)(-6))
 #define ___2659  ((___514)(-7))
 #define ___2660  ((___514)(-8))
 #define ___2661  ((___514)(-9))
 #define ___2662  ((___514)(-10))
 #define ___1987 ((___514)(-255))
 #define ___1420 ___743
 #define ___2195  ___783
 #define ___2792  (___2195 - ___1420 + 1)
 #define ___1418 ___364
 #define ___2194  ___2195
 #define ___2767  (___2194 - ___1418 + 1)
 #define ___2873 ((___514)255)
 #define ___1807              (___2194 + 1)
 #define ___813          (___2194 + 2) 
 #define ___4571          (___2194 + 3)
 #define ___1421 ___1807
 #define ___2199  ___4571
 #define ___2809    (___2199 - ___1421 + 1)
 #define ___2789      (___1545.___2242.___2380 + 1)
 #define ___2786 (___2767 + ___2809 + ___2789)
 #define ___342      (0)
 #define ___1980  (___2767)
 #define ___612    (___2767 + ___2809)
 #define ___2141     (short)31
 #define ___2150     (short)13
 #define ___2145        (short)27
 #define ___2140  (short)8
 #define ___2142  (short)127
 #define ___2146  (short)29
 #define ___2151 (short)30
 #define ___2154    (short)11
 #define ___2144  (short)10
 #define ___2148       (short)43
 #define ___2147      (short)45
 #define ___2152 (short)128 
 #define ___2153      (short)19  
 #define ___2149    (short)18  
 #define ___2143   (short)2   
 #define ZoneMarkerFull32Bit 299.0
 #define ZoneMarkerFace64Bit 298.0
 #define ___1615        399.0
 #define ___4113        499.0
 #define ___790 599.0
 #define ___4287     699.0
 #define ___885  799.0
 #define ___4339      899.0
 #define EndHeaderMarker   357.0
 #define ___293        ___787 + 1
 #define ___2335     ___787 + 2
 #define ___2478     ___787 + 3
 #define ___2340  ___787 + 4
 #define ___3798  ___787 + 5
 #define ___513 ___787 + 6
 #define ___392    ___787 + 7
 #define ___2171       ___787 + 8
 #define ___2827 ___787 + 9
 #define ___229 ___787 + 10
 #define ___1989    ___787 + 99
 #define ___1422 ___293
 #define ___2201  ___2171
 #define ___958 0.0001
 #define ___326 NULL
 #ifdef MSWIN
 #define ___1088 "\\"
 #else
 #define ___1088 "/"
 #endif
 #define ___4199  fread
 #define ___4203 fwrite
 #if defined MSWIN
 #if _MSC_VER <= 1800 
 #define snprintf _snprintf
 #endif
 #define ___4197 fflush
 #define ___4196 fclose
 #define ___4207 TP_GLOBAL_NAMESPACE remove
 #define ___4205  TP_GLOBAL_NAMESPACE ___3400
 #define ___4206   TP_GLOBAL_NAMESPACE _stat
 #define ___4204 TP_GLOBAL_NAMESPACE getenv
 #if defined _WIN64
 #define ___4201(___3793, ___2866, whence) TP_GLOBAL_NAMESPACE _fseeki64((___3793), (__int64)(___2866), (whence))
 #define ___4202                         TP_GLOBAL_NAMESPACE _ftelli64
 #else
 #define ___4201(___3793, ___2866, whence) TP_GLOBAL_NAMESPACE fseek((___3793), (long)(___2866), (whence))
 #define ___4202                         TP_GLOBAL_NAMESPACE ftell
 #endif
 #else
 #define FileStat_s struct _stat
 #define ___4205   TP_GLOBAL_NAMESPACE ___3399
 #define ___4207  TP_GLOBAL_NAMESPACE unlink
 #define ___4196  TP_GLOBAL_NAMESPACE fclose
 #define ___4197  TP_GLOBAL_NAMESPACE fflush
 #define ___4201   TP_GLOBAL_NAMESPACE fseeko
 #define ___4202   TP_GLOBAL_NAMESPACE ftello
 #define ___4206    TP_GLOBAL_NAMESPACE stat
 #define _stat                                                                                                              \
 TP_GLOBAL_NAMESPACE stat 
 #define ___4204 TP_GLOBAL_NAMESPACE getenv
 #endif
 #if !defined MSWIN
typedef FILE*    HDC; typedef uint64_t MSG; typedef void* HMODULE; typedef void* LPCWSTR; typedef bool  BOOL;
 #endif
typedef ___2226 ___2733; typedef int64_t ___90; typedef int64_t ___4265; typedef int64_t ___1396; typedef uint64_t ___2406; typedef int32_t ___514; typedef int16_t ___3882; typedef char  ___372; typedef char* ___4654; typedef char* ___4367; typedef char* ___2326; typedef ___2226 ___1824; typedef ___2226 ___3462[___2372]; typedef double    BasicSize_t[___2351]; typedef double*   ___4355; typedef ___2226 ___3494; typedef unsigned long ___3481; typedef ___3481 ___3484; typedef ___3484* ___3482;
 #define ___1311                               (1ULL << 0) 
 #define ___1312                         (1ULL << 1)
 #define ___1310                               (1ULL << 2) 
 #define ___1336                               (1ULL << 3) 
 #define ___1314                        (1ULL << 4)
 #define ___1335                 (1ULL << 5)
 #define FEATURE_NUMBER_OF_FRAMES_GREATER_THAN_1  (1ULL << 6)
 #define FEATURE_NUMBER_OF_ZONES_GREATER_THAN_1   (1ULL << 7)
 #define FEATURE_NUMBER_OF_FRAMES_GREATER_THAN_5  (1ULL << 8)
 #define FEATURE_NUMBER_OF_ZONES_GREATER_THAN_5   (1ULL << 9)
 #define FEATURE_NUMBER_OF_FRAMES_GREATER_THAN_10 (1ULL << 10)
 #define FEATURE_NUMBER_OF_ZONES_GREATER_THAN_10  (1ULL << 11)
 #define FEATURE_READ_NONOEM_TECPLOT_DATA         (1ULL << 12) 
 #define FEATURE_FOREIGN_DATALOADERS              (1ULL << 13) 
 #define ___1316            (1ULL << 14) 
 #define ___1322                     (1ULL << 15) 
 #define ___1327            (1ULL << 16) 
 #define ___1321                 (1ULL << 17) 
 #define ___1332                      (1ULL << 18) 
 #define ___1333                (1ULL << 19) 
 #define ___1319                     (1ULL << 20) 
 #define ___1318                        (1ULL << 21) 
 #define ___1334                          (1ULL << 22) 
 #define FEATURE_FEMIXED                          (1ULL << 23) 
 #define ___1313                          (1ULL << 24) 
 #define FEATURE_DATASETSIZE                      (1ULL << 25) 
 #define FEATURE_RPC                              (1ULL << 26) 
 #define FEATURE_DATALOADERS_EXCEPT_ALLOWED       (1ULL << 27) 
 #define FEATURE_NUMBER_OF_PAGES_GREATER_THAN_1   (1ULL << 28) 
 #define FEATURE_BATCH_MODE                       (1ULL << 29) 
 #define FEATURE_SIMPLEZONECREATION               (1ULL << 30) 
 #define FEATURE_SURFACEFLOWEFFECTS               (1ULL << 31) 
 #define NUM_POSSIBLE_INHIBITED_FEATURES          32
 #define ___2162                                                                                                 \
 (___1311 | ___1312 | ___1310 | ___1336 | ___1314 | ___1335 |                  \
 FEATURE_NUMBER_OF_FRAMES_GREATER_THAN_1 | FEATURE_NUMBER_OF_ZONES_GREATER_THAN_1 |                                        \
 FEATURE_NUMBER_OF_FRAMES_GREATER_THAN_5 | FEATURE_NUMBER_OF_ZONES_GREATER_THAN_5 |                                        \
 FEATURE_NUMBER_OF_FRAMES_GREATER_THAN_10 | FEATURE_NUMBER_OF_ZONES_GREATER_THAN_10 | FEATURE_READ_NONOEM_TECPLOT_DATA |   \
 FEATURE_FOREIGN_DATALOADERS | ___1316 | ___1322 | ___1327 |      \
 ___1321 | ___1332 | ___1333 | ___1319 | ___1318 |   \
 ___1334 | FEATURE_FEMIXED | ___1313 | FEATURE_DATASETSIZE | FEATURE_RPC |                                 \
 FEATURE_DATALOADERS_EXCEPT_ALLOWED | FEATURE_NUMBER_OF_PAGES_GREATER_THAN_1 | FEATURE_BATCH_MODE |                        \
 FEATURE_SIMPLEZONECREATION | FEATURE_SURFACEFLOWEFFECTS)
 #define ___4303(___1309) (((___1309) & ___2162) != 0)
 #define ___4304(___2345)    (((___2345) & ~___2162) == 0)
typedef uint64_t ___1320; typedef uint64_t ___1323;
 #define MAX_UTF8_BYTES 4
 #define ___3917 1 + MAX_UTF8_BYTES + 1
typedef char ___3918[___3917]; typedef int32_t ___1293; typedef int32_t ___1144; typedef int32_t ___1255; typedef enum { Projection_Orthographic, Projection_Perspective, END_Projection_e, Projection_Invalid = ___329 } Projection_e; typedef enum { ___3092, ___3093, ___3094, END_PlacementPlaneOrientation_e, ___3091 = ___329 } PlacementPlaneOrientation_e; typedef enum { ___3850, ___3853, ___3851, END_StringMode_e, ___3852 = ___329 } StringMode_e; typedef enum { ___3596, ___3594, END_SidebarSizing_e, ___3595 = ___329 } SidebarSizing_e; typedef enum { ___3591, ___3592, /**@internal TP_NOTAVAILABLE*/ ___3593, /**@internal TP_NOTAVAILABLE*/ ___3589, /**@internal TP_NOTAVAILABLE*/ END_SidebarLocation_e, ___3590 = ___329 } SidebarLocation_e; typedef enum { ___2416, ___2419, ___2417, ___2418, END_MenuItem_e, ___2415 = ___329 } MenuItem_e; typedef enum { ___3671, ___3670, ___3680, ___3677, ___3674, ___3669, ___3672, ___3681, ___3679, ___3673, ___3668, ___3676, ___3678, END_StandardMenu_e, ___3675 = ___329 } StandardMenu_e; typedef enum { ___1379, ___1376, ___1380, ___1377, END_FieldProbeDialogPage_e, ___1378 = ___329 } FieldProbeDialogPage_e; enum BooleanCache_e { ___367, ___369, ___370, END_BooleanCache_e, ___368 = ___329 }; enum LinePickLocation_e { ___2277, ___2278, ___2276, ___2275, ___2273, END_LinePickLocation_e, ___2274 = ___329 }; enum ViewDest_e { ___4422, ___4424, END_ViewDest_e, ___4423 = ___329 }; enum DataSetReaderOrigin_e { ___899, ___897, END_DataSetReaderOrigin_e, ___898 = ___329 }; enum ExtendedCurveFitOrigin_e { ___1247, ___1245, END_ExtendedCurveFitOrigin_e, ___1246 = ___329 }; enum CollapsedStatus_e { ___511, ___507, ___506, ___508, ___509, END_CollapsedStatus_e, ___510 = ___329 }; typedef enum { ___4245, ___4250, ___4254,
___4246, ___4255, ___4256, ___4252, ___4251, ___4243, ___4244, ___4253, ___4247, ___4249, END_UndoStateCategory_e, ___4248 = ___329 } UndoStateCategory_e; typedef enum { ___2295, ___2293, END_LinkType_e, ___2294 = ___329 } LinkType_e; typedef enum { ___1507, ___1509, END_FrameCollection_e, ___1508 = ___329 } FrameCollection_e; typedef enum { SurfaceGenerationMethod_AllowQuads, SurfaceGenerationMethod_AllTriangles, SurfaceGenerationMethod_AllPolygons, SurfaceGenerationMethod_Auto, END_SurfaceGenerationMethod_e, SurfaceGenerationMethod_Invalid = ___329 } SurfaceGenerationMethod_e; typedef enum { ___2214, ___2215, ___2216, END_LegendProcess_e, ___2217 = ___329 } LegendProcess_e; typedef enum { ___3383, ___3379, ___3378, ___3382, ___3380, ___3377, END_RGBLegendOrientation_e, ___3381 = ___329 } RGBLegendOrientation_e; struct ___3392 { uint8_t ___3266; uint8_t G; uint8_t B; }; typedef ___3392 ___3389[256]; typedef enum { ___3759, ___3758, ___3767, ___3766, ___3740, ___3712, ___3737, ___3750, ___3707, ___3736, ___3700, ___3720, ___3701, ___3727, ___3726, ___3748, ___3765, ___3757, ___3721, ___3719, ___3761, ___3698, ___3702, ___3749, ___3735, ___3733, ___3742, ___3743, ___3744, ___3745, ___3717, ___3754, ___3751, ___3706, ___3705, StateChange_Text, ___3714, ___3708, ___3711, ___3747, ___3746, ___3691, ___3693, ___3692, ___3760, ___3752, ___3715, ___3756, ___3755, ___3741, ___3738, ___3734, ___3713, ___3739, ___3722, ___3690, ___3689,
___3725, ___3724, ___3723, ___3768, ___3718, ___3703, ___3699, StateChange_OpenLayout, StateChange_MacroLoaded, StateChange_PerformingUndoBegin, StateChange_PerformingUndoEnd, StateChange_SolutionTimeChangeBlockEnd, StateChange_SolutionTimeClustering, StateChange_LicenseAvailability, END_StateChange_e, ___3716 = ___329, ___3704            = ___3717, ___3710             = ___3754, ___3709            = ___3751, ___3763            = ___3720, ___3764                  = ___3721, ___3762    = ___3719, StateChange_SolutiontimeChangeBlockEnd = StateChange_SolutionTimeChangeBlockEnd } StateChange_e; typedef enum { VarParseReturnCode_Ok, VarParseReturnCode_InvalidInteger, VarParseReturnCode_InvalidVariableName, VarParseReturnCode_VariableNotInDataSet, END_VarParseReturnCode_e, VarParseReturnCode_Invalid = ___329 } VarParseReturnCode_e; typedef enum { AnimationType_LineMap, AnimationType_Time, AnimationType_Zone, AnimationType_IJKBlanking, AnimationType_IJKPlanes, AnimationType_IsoSurfaces, AnimationType_Slices, AnimationType_ContourLevels, AnimationType_Streamtraces, END_AnimationType_e, AnimationType_Invalid = ___329 } AnimationType_e; typedef enum { ___3731, ___3732, ___3729, ___3730, END_StateChangeMode_e, ___3728 = ___329 } StateChangeMode_e; typedef enum { ___3696, ___3694, ___3695, END_StateChangeCallbackAPI_e, ___3697 = ___329 } StateChangeCallbackAPI_e; typedef enum { ___86, ___84, ___87, END_AppMode_e, ___85 = ___329 } AppMode_e; typedef enum { ___2208, ___2210, ___2207, END_LayoutPackageObject_e, ___2209 = ___329 } LayoutPackageObject_e; typedef enum { ___4356, ___4357, END_VarLoadMode_e, ___4358 = ___329 } VarLoadMode_e; typedef enum { ___1902, ___1903, END_ImageSelection_e, ___1901 = ___329 } ImageSelection_e; typedef enum { ___2231, ___2234, ___2233, END_LibraryType_e, ___2232 = ___329 } LibraryType_e; /**@internal TP_NOPYTHON*/ typedef enum { ___220, ___223, ___222, ___224, ___219, ___215, ___216, ___218, ___217, END_AssignOp_e,
___221 = ___329 } AssignOp_e; typedef enum { ___979, ___998, ___1030, ___1086, ___1048, ___1049, ___1080, ___1045, ___1046, ___1034, ___1035, ___1055, ___1056, ___1027, ___1085, ___1043, ___1017, ___999, ___1028, ___1029, ___977, ___1066, ___1050, ___1069, ___1071, ___1067, ___1020, ___1064, ___981, ___1082, ___1084, ___1081, ___1083, ___1061, ___1059, ___1060, ___1052, ___1051, ___1025, ___1016, ___994, ___1023, ___976, ___1079, ___1041, ___990, ___1068, ___1065, ___1076, ___1053, ___983, ___985, ___984, ___996, ___1032, ___986, ___987, ___992, ___993, ___1000, ___1002, ___1003, ___1007, ___1006, ___1008, ___1009, ___1001, ___1005, ___1004, ___1024, ___1019, ___1021, ___1078, ___989, ___988, ___991, ___1038, ___1037, ___1054, ___1073, ___1072, ___1077, ___1044, ___980, ___1033, ___1063, ___1058, ___1057, ___1026, ___1014, ___1013, ___1047, ___997, ___982, ___1070, ___1074, ___1039, ___1015, ___1011, ___978, Dialog_FourierTransform, Dialog_RotateData, Dialog_AxialDuplicate, END_Dialog_e, ___1018 = ___329, ___1040 = ___1086 } Dialog_e; /**@internal TP_NOPYTHON*/ typedef enum { ___49, ___48, ___50, ___46, ___45, ___47, ___42, ___41, ___43, END_AnchorAlignment_e, ___44 = ___329 } AnchorAlignment_e; enum PositionAtAnchor_e { ___3166, ___3167, ___3164, END_PositionAtAnchor_e, ___3165 = ___329
}; struct ___1042 { AnchorAlignment_e  ___40; ___372          ___51; ___372          ___55; int32_t            ___2484; ___2226          ___1992; ___2226          ___2125; PositionAtAnchor_e ___3163; ___372          ___1818; };
 #if defined EXPORT_DEPRECATED_INTERFACES_TO_ADK_ONLY
typedef enum { ___3223, ___3224, ___3225, ___3226, ___3227, ___3228, ___3229, ___3230, ___3231, ___3232, ___3233, END_ProcessXYMode_e, ___3222 = ___329 } ProcessXYMode_e;
 #endif
typedef enum { ___717, ___720, ___719, END_CurveInfoMode_e, ___718 = ___329 } CurveInfoMode_e; enum ProcessLineMapMode_e { ___3207, ___3216, ___3208, ___3215, ___3205, ___3211, ___3210, ___3213, ___3209, ___3214, ___3206, ___3219, ___3221, ___3217, ___3212, ___3220, END_ProcessLineMapMode_e, ___3218 = ___329 }; typedef enum { ___3865, ___3864, END_StyleBase_e, ___3866 = ___329 } StyleBase_e; typedef enum { ___3283, ___3281, ___3285,
 #if defined ENABLE_ORPHANED_DATASETS
___3284,
 #endif
END_ReadDataOption_e, ___3282 = ___329 } ReadDataOption_e;
 #if defined EXPORT_DEPRECATED_INTERFACES_TO_ADK_ONLY
typedef enum { ___2720, ___2722, ___2723, END_NodeLabel_e, ___2721 = ___329 } NodeLabel_e;
 #endif
typedef enum { ___2174, ___2176, ___2177, END_LabelType_e, ___2175 = ___329 } LabelType_e;
 #if defined EXPORT_DEPRECATED_INTERFACES_TO_ADK_ONLY
typedef enum { ___3876, ___3874, ___3878, ___3875, END_SubBoundaryEditOption_e, ___3877 = ___329 } SubBoundaryEditOption_e;
 #endif
typedef enum { ___374, ___373, ___377, ___375, END_BorderAction_e, ___376 = ___329 } BorderAction_e; typedef enum { ___3131, ___3132, ___3133, ___3124, ___3134, ___3135, ___3136, ___3140, ___3141, ___3127, ___3129, ___3130, ___3137, ___3125, ___3138, ___3139, ___3128, END_PointerStyle_e, ___3126 = ___329 } PointerStyle_e; typedef enum { ___709, ___707, ___693, ___694, ___706, ___714, ___701, ___711, ___712, ___698, ___702, ___703, ___705, ___695, ___708, ___710, ___699, ___713, ___700, ___704, ___696, END_CursorStyle_e, ___697 = ___329 } CursorStyle_e; typedef enum { ___3077, ___3086, ___3078, ___3083, ___3085, ___3087, ___3088, ___3080, ___3081, ___3079, ___3084, END_PickSubPosition_e, ___3082 = ___329 } PickSubPosition_e; typedef enum { ___3965, ___3964, ___3963, ___3961, END_TecEngInitReturnCode_e, ___3962 = ___329 } TecEngInitReturnCode_e; typedef enum { ___1791, ___1792, ___1793, ___1788, ___1789, END_GetValueReturnCode_e, ___1790 = ___329, ___1786              = ___1791, ___1787 = ___1792, ___1794     = ___1793, ___1781    = ___1788, ___1783 = ___1789, ___1784         = ___1790 } GetValueReturnCode_e; typedef enum { ___3536, ___3525, ___3531, ___3533, ___3534, ___3535, ___3538, ___3539, ___3522, ___3532, ___3528, ___3523,
___3524, ___3537, ___3526, ___3529, END_SetValueReturnCode_e, ___3527 = ___3525, ___3530 = ___329, ___3520                       = ___3536, ___3510           = ___3525, ___3515     = ___3531, ___3517   = ___3533, ___3518     = ___3534, ___3519  = ___3535, ___3540          = ___3538, ___3541         = ___3539, ___3506            = ___3522, ___3516         = ___3532, ___3513      = ___3528, ___3508            = ___3523, ___3509            = ___3524, ___3521 = ___3537, ___3511      = ___3526, ___3512 = ___3527, ___3514 = ___3530 } SetValueReturnCode_e; typedef enum { ___815, ___816, END_DataAlterMode_e, ___817 = ___329 } DataAlterMode_e; typedef enum { ___825, ___823, ___824, ___821, ___822, ___820, ___818, END_DataAlterReturnCode_e, ___819 = ___329 } DataAlterReturnCode_e; typedef enum { ___2855, ___2856, ___2853, ___2857, ___2852, END_ObjectAlign_e, ___2854 = ___329 } ObjectAlign_e; typedef enum { ___2166, ___2165, ___2168, END_LabelAlignment_e, ___2167 = ___329 } LabelAlignment_e; typedef enum { ___4425, ___4421, ___4415, ___4433, ___4419, ___4437, ___4438, ___4428, ___4420, ___4431, ___4432, ___4434, ___4430, ___4417, ___4429, ___4416, ___4418, ___4426, END_View_e, ___4427 = ___329 } View_e; typedef enum { ___4470, ___4468, ___4469, ___4473, ___4472, ___4476, ___4474, ___4475, END_WorkspaceView_e, ___4471 = ___329
} WorkspaceView_e; typedef enum { ___192, ___189, ___190, END_ArrowheadStyle_e, ___191 = ___329, ___186   = ___192, ___183  = ___189, ___184  = ___190, ___185 = ___191 } ArrowheadStyle_e; typedef enum { ___181, ___177, ___179, ___178, END_ArrowheadAttachment_e, ___180 = ___329, ___182        = ___181, ___172 = ___177, ___174       = ___179, ___173  = ___178, ___175     = ___180 } ArrowheadAttachment_e; typedef enum { ___496, ___495, END_Clipping_e, ___497 = ___329 } Clipping_e; typedef enum { ___3772, ___3773, ___3774, ___3777, ___3776, END_StatusInfo_e, ___3775 = ___329 } StatusInfo_e;
 #if defined EXPORT_DEPRECATED_INTERFACES_TO_ADK_ONLY
typedef enum { ___1513, ___1516, ___1517, ___1518, ___1515, END_FrameMode_e, ___1514 = ___329, ___1510   = ___1513, ___1524  = ___1516, ___1525    = ___1517, ___1526      = ___1518, ___1523  = ___1515, ___1512 = ___1514 } FrameMode_e;
 #endif
typedef enum { ___3114, ___3116, ___3115, ___3122, ___3119, ___3118, END_PlotType_e, ___3117 = ___329 } PlotType_e;
 #define ___4311(___3113)           (VALID_ENUM((___3113), PlotType_e) && ((___3113) != ___3114))
 #define ___4309(___3113)  ((___3113) == ___3122 || (___3113) == ___3118)
 #define ___4306(___3113) ((___3113) == ___3115 || (___3113) == ___3116)
 #define ___3120(___3113) ___4306((___3113))
 #define ___3121(___3113)   ___4309((___3113))
 #define ___4314(___3113)                                                                                            \
 ((___3113) == ___3119 || (___3113) == ___3122 || (___3113) == ___3115 ||                   \
 (___3113) == ___3116)
typedef enum { ___553, ___554, END_ContLineCreateMode_e, ___552 = ___329 } ContLineCreateMode_e; typedef enum { ___3056, ___3049, ___3044, ___3067, ___3050, ___3066, ___3048, ___3047, ___3061, ___3054, ___3059, ___3058, ___3064, ___3065, ___3057, ___3072, ___3071, ___3063, ___3062, ___3052, ___3060, ___3055, ___3045, END_PickObjects_e, ___3051 = ___329, ___3039                   = ___3056, ___3033                  = ___3049, ___3030                   = ___3044, ___3029      = ___3067, ___3034                   = ___3050, ___3073                   = ___3066, ___3032          = ___3048, ___3031           = ___3047, ___3046          = ___3061, ___3037             = ___3054, ___3074               = ___3054, ___3042        = ___3059, ___3041 = ___3058, ___3069    = ___3064, ___3070    = ___3065, ___3040                  = ___3057, ___3076                   = ___3072, ___3075              = ___3071, ___3068         = ___3063, ___3053               = ___3062, ___3036          = ___3052, ___3043              = ___3060, ___3038            = ___3055, ___3035                = ___3051 } PickObjects_e; enum SingleEditState_e { ___3599, ___3598, ___3600, END_SingleEditState_e, ___1141 = ___329 }; enum AxisSubPosition_e { ___307, ___306, ___309, ___305, ___310, ___311, END_AxisSubPosition_e, ___308    = ___329, ___304    = ___307, ___303      = ___309, ___313 = ___307, ___312   = ___311
}; typedef enum { ___300, ___299, ___302, END_AxisSubObject_e, ___301 = ___329 } AxisSubObject_e; typedef enum { ___2512, ___2513, ___2511, END_MouseButtonClick_e, ___2510 = ___329 } MouseButtonClick_e; typedef enum { ___2515, ___2536, ___2527, ___2535, ___2526, ___2516, ___2525, ___2531, ___2533, ___2538, ___2529, ___2537, ___2528, ___2517, ___2524, ___2532, ___2534, ___2539, ___2530, ___2521, ___2523, ___2520, ___2522, END_MouseButtonDrag_e, ___2514 = ___329, ___2519  = ___2525, ___2518 = ___2524 } MouseButtonDrag_e; struct ___2509 { MouseButtonClick_e ___421; MouseButtonDrag_e  ___3597; MouseButtonDrag_e  ___644; MouseButtonDrag_e  ___31; MouseButtonDrag_e  ___3558; MouseButtonDrag_e  ___642; MouseButtonDrag_e  ___647; MouseButtonDrag_e  ___35; MouseButtonDrag_e  ___643; }; struct ___2507 { ___2509 ___2469; ___2509 ___3395; };
 #define ___2752   0
 #define ___2213   1
 #define ___2470 2
 #define ___3397  3
typedef enum { ___33, ___34, END_AltMouseButtonMode_e, ___32 = ___329 } AltMouseButtonMode_e; typedef enum { ___2558, ___2569, ___2540, ___2579, ___2574, ___2559, ___2573, ___2552, ___2555, ___2550, ___2553, ___2551, ___2554, ___2546, ___2564, ___2560, ___2565, ___2566, ___2567, ___2568, ___2544, ___2542, ___2543, ___2572, ___2571, ___2549, ___2548, ___2547, ___2545, ___2570, ___2557, ___2575, ___2576, ___2577, ___2578, ___2562, ___2563, ___2541, END_MouseButtonMode_e, ___2556 = ___329, ___2561 = ___2564, ___2596                    = ___2558, ___2604                    = ___2569, ___2508                    = ___2540, ___2614                      = ___2579, ___2609                 = ___2574, ___2597                     = ___2559, ___2608                      = ___2573, ___2591              = ___2552, ___2594                = ___2555, ___2589                = ___2550, ___2592             = ___2553, ___2590               = ___2551, ___2593                = ___2554, ___2585               = ___2546, ___2599           = ___2564, ___2598          = ___2560, ___2600               = ___2565, ___2601               = ___2566, ___2602               = ___2567, ___2603               = ___2568, ___2583              = ___2544, ___2581                = ___2542, ___2582             = ___2543, ___2607              = ___2572, ___2606             = ___2571, ___2588             = ___2549,
___2587               = ___2548, ___2586     = ___2547, ___2584        = ___2545, ___2605                     = ___2570, ___2610                     = ___2575, ___2611                     = ___2576, ___2612                     = ___2577, ___2613                     = ___2578, ___2595                   = ___2556 } MouseButtonMode_e; typedef enum { ___974, ___973, ___975, END_DetailsButtonState_e, ___972 = ___329 } DetailsButtonState_e; typedef enum { ___1191, ___1192, ___1190, ___1196, ___1193, ___1195, Event_KeyRelease, END_Event_e, ___1194 = ___329 } Event_e; typedef enum { ___2858, ___2860, ___2862, ___2861, END_ObjectDrawMode_e, ___2859 = ___329 } ObjectDrawMode_e; typedef enum { ___4164, ___4166, END_ThreeDViewChangeDrawLevel_e, ___4165 = ___329 } ThreeDViewChangeDrawLevel_e; typedef enum { ___2747, ___2749, END_NonCurrentFrameRedrawLevel_e, ___2748 = ___329 } NonCurrentFrameRedrawLevel_e; typedef enum { ___3313, ___3316, ___3314, ___3317, ___3306, ___3307, ___3308, ___3304, ___3305, ___3312, ___3311, ___3310, END_RedrawReason_e, ___3309                   = ___329, ___3315 = ___3313, ___3318  = ___3316 } RedrawReason_e; typedef enum { ___3419, ___3418, ___3417, END_RotationMode_e, ___3416 = ___329 } RotationMode_e; typedef enum { ___3410, ___3411, ___3412, ___3406, ___3407, ___3402, ___3408, ___3409, ___3404, ___3401, ___3403, /**@internal TP_NOTAVAILABLE*/ END_RotateAxis_e, ___3405 = ___329 } RotateAxis_e; typedef enum { ___3413, ___3415, END_RotateOriginLocation_e, ___3414 = ___329 } RotateOriginLocation_e; typedef enum { ___2886, ___2888, END_OriginResetLocation_e,
___2887 = ___329 } OriginResetLocation_e; typedef enum { ___3615, ___3616, ___3614, ___3613, END_SliceSource_e, ___3612 = ___329 } SliceSource_e; typedef enum { ___1949, ___1948, ___1945, ___1944, ___1941, ___1947, ___1952, ___1942, END_Input_e, ___1946 = ___329 } Input_e; typedef enum { ___3253, ___3255, ___3256, END_PtSelection_e, ___3254 = ___329 } PtSelection_e; typedef enum { ___1117, ___1116, ___1118, END_Drift_e, ___1115 = ___329 } Drift_e; typedef enum { ___964, ___965, ___969, ___968, ___967, END_DerivPos_e, ___966 = ___329 } DerivPos_e; typedef enum { ___2243, ___2245, END_LinearInterpMode_e, ___2244 = ___329 } LinearInterpMode_e; typedef enum { ___4442, ___4443, END_VolumeCellInterpolationMode_e, ___4441 = ___329 } VolumeCellInterpolationMode_e; typedef enum { ___3157, ___3155, END_PolyCellInterpolationMode_e, ___3156 = ___329 } PolyCellInterpolationMode_e; typedef enum { ___547, ___546, END_ConstraintOp2Mode_e, ___545 = ___329 } ConstraintOp2Mode_e; typedef enum { ___875, ___877, END_DataProbeVarLoadMode_e, ___876 = ___329 } DataProbeVarLoadMode_e; typedef enum { ___3937, ___3935, END_SZLSubzoneLoadModeForStreams_e, ___3936 = ___329 } SZLSubzoneLoadModeForStreams_e; typedef enum { ___4316, ___4317, ___4320, END_ValueBlankCellMode_e, ___4318 = ___329, ___4319 = ___4320 } ValueBlankCellMode_e; typedef enum { ___4321, ___4324, ___4322, END_ValueBlankMode_e, ___4323 = ___329 } ValueBlankMode_e; typedef enum { ___452, ___453, ___450, ___454, END_CellBlankedCond_e, ___451 = ___329 } CellBlankedCond_e; typedef enum { ___3332, ___3329, ___3331, ___3328, ___3327, ___3333, END_RelOp_e, ___3330 = ___329 } RelOp_e; typedef enum { ___1845, ___1844, END_IJKBlankMode_e, ___1846 = ___329
} IJKBlankMode_e; typedef enum { ___3110, ___3112, ___3109, END_PlotApproximationMode_e, ___3111 = ___329 } PlotApproximationMode_e; typedef enum { ___3653, ___3654, ___3651, SphereScatterRenderQuality_Fast, END_SphereScatterRenderQuality_e, ___3652 = ___329 } SphereScatterRenderQuality_e; typedef enum { ExtractMode_SingleZone, ExtractMode_OneZonePerConnectedRegion, ExtractMode_OneZonePerSourceZone, END_ExtractMode_e, ExtractMode_Invalid = ___329 } ExtractMode_e; typedef enum { Resulting1DZoneType_IOrderedIfPossible, Resulting1DZoneType_FELineSegment, Resulting1DZoneType_Unused, END_Resulting1DZoneType_e, ResultingDZoneType_Invalid = ___329 } Resulting1DZoneType_e; typedef enum { ___2991, ___2989, ___2990, ___2985, END_FillPat_e, ___2986 = ___329 } FillPat_e; typedef enum { ___4225, ___4223, ___4224, ___4221, END_Translucency_e, ___4222 = ___329 } Translucency_e; typedef enum { ___3890, ___3891, ___3888, END_SunRaster_e, ___3889 = ___329 } SunRaster_e; typedef enum { ___384, ___387, ___386, END_BoundaryCondition_e, ___385 = ___329 } BoundaryCondition_e; typedef enum { ___289, ___292, ___291, END_AxisMode_e, ___290 = ___329 } AxisMode_e; typedef enum { ___3264, ___3262, ___3265, END_QuickColorMode_e, ___3263 = ___329 } QuickColorMode_e; typedef enum { ___1412, ___1415, ___1414, ___1413, END_FillMode_e, ___1411 = ___329 } FillMode_e; typedef enum { ___2272, ___2268, ___2266, ___2269, ___2271, ___2267, END_LinePattern_e, ___2270 = ___329 } LinePattern_e; typedef enum { ___2128, ___2129, ___2126, END_LineJoin_e, ___2127 = ___329 } LineJoin_e; typedef enum { ___440, ___443, ___444, END_LineCap_e, ___441 = ___329 } LineCap_e; typedef enum { ___1585, ___1587, ___1588, ___1581, ___1582, ___1586, ___1583, END_GeomForm_e, ___1584 = ___329, GeomType_LineSegs   = ___1585, GeomType_Rectangle  = ___1587, GeomType_Square     = ___1588, GeomType_Circle     = ___1581, GeomType_Ellipse    = ___1582, GeomType_LineSegs3D = ___1586, GeomType_Image      = ___1583, END_GeomType_e      = END_GeomForm_e, GeomType_Invalid    = ___1584
} GeomForm_e; typedef GeomForm_e GeomType_e; typedef enum { ___4348, ___4347, END_VariableDerivationMethod_e, ___4349 = ___329 } VariableDerivationMethod_e; typedef enum { ___270, END_AuxDataType_e, ___269 = ___329 } AuxDataType_e; typedef enum { ___259, ___253, ___254, ___258, ___256, ___257, AuxDataLocation_Layout, END_AuxDataLocation_e, ___255 = ___329 } AuxDataLocation_e; typedef enum { ___4704, ___4702, ___4700, ___4701, ___4695, ___4696, ___4698, ___4699, ZoneType_FEMixed, END_ZoneType_e, ___4703 = ___329, ___4697 = ZoneType_FEMixed } ZoneType_e; typedef enum { FECellShape_Bar, FECellShape_Triangle, FECellShape_Quadrilateral, FECellShape_Tetrahedron, FECellShape_Hexahedron, FECellShape_Pyramid, FECellShape_Prism, END_FECellShape_e, FECellShape_Invalid = ___329 } FECellShape_e; typedef uint32_t FEGridOrder_t; typedef enum { FECellBasisFunction_Lagrangian, END_FECellBasisFunction_e, FECellBasisFunction_Invalid = ___329 } FECellBasisFunction_e; typedef enum { ___4659, ___4664, ___4666, ___4660, ___4662, ___4665, ___4661, END_ZoneOrder_e, ___4663 = ___329 } ZoneOrder_e; typedef enum { ___851, ___852, ___849, ___850, END_DataFormat_e, ___853 = ___329 } DataFormat_e; typedef enum { ___872, ___874, END_DataPacking_e, ___873 = ___329 } DataPacking_e; typedef enum { ProbeObject_None, ProbeObject_Streamtrace, ProbeObject_StreamtraceMarker, ProbeObject_Slice, ProbeObject_IsoSurface, ProbeObject_FieldZone, END_ProbeObject_e, ProbeObject_First   = ProbeObject_Streamtrace, ProbeObject_Last    = ProbeObject_FieldZone, ProbeObject_Invalid = ___329 } ProbeObject_e; typedef enum { ProbeNearest_Position, ProbeNearest_Node, END_ProbeNearest_e, ProbeNearest_Invalid = ___329 } ProbeNearest_e; typedef enum { ___2993, ___2994, ___2997, ___2996, ___2992, ___2998, ___2999, ___3000, END_PrinterDriver_e, ___2995 = ___329 } PrinterDriver_e; typedef enum { ___1887, ___1904, ___1882, ___1884, END_EPSPreviewImage_e, ___1886 = ___329 } EPSPreviewImage_e; typedef enum { ___4173, ___4175, END_TIFFByteOrder_e, ___4174 = ___329 } TIFFByteOrder_e; typedef enum { ___2132, ___2131, END_JPEGEncoding_e, ___2130 = ___329 } JPEGEncoding_e; typedef enum { ___1431, ___1430, ___1428, END_FlashImageType_e, ___1429 = ___329, ___1427 = ___1428 } FlashImageType_e;
typedef enum { ___1424, ___1426, END_FlashCompressionType_e, ___1425 = ___329 } FlashCompressionType_e; typedef enum { ___1223, ___1227, ___1224, ___1225, ___1231, ___1222, ___1214, ___1215, ___1221, ___1211, ___1218, ___1228, ___1209, ___1220, ___1208, ___1210, /**@internal TP_NOTAVAILABLE*/ ___1217, ___1212, ___1230, ___1226, ___1213, ___1219, ___1229, END_ExportFormat_e, ___1216 = ___329 } ExportFormat_e; typedef enum { ___275, ___277, ___278, END_AVICompression_e, ___276 = ___329 } AVICompression_e; typedef enum { ___65, ___59, ___64, ___60, ___61, ___63, ___66, END_AnimationDest_e, ___62 = ___329 } AnimationDest_e; typedef enum { ___69, ___67, ___71, ___68, END_AnimationOperation_e, ___70 = ___329 } AnimationOperation_e; typedef enum { ___73, ___78, ___72, ___79, ___75, ___77, ___76, END_AnimationStep_e, ___74 = ___329 } AnimationStep_e; typedef enum { ___4605, ___4603, ___4606, END_ZoneAnimationMode_e, ___4604 = ___329 } ZoneAnimationMode_e;
 #if defined EXPORT_DEPRECATED_INTERFACES_TO_ADK_ONLY
typedef enum { ___361, ___360, ___363, END_BitDumpRegion_e, ___362 = ___329 } BitDumpRegion_e;
 #endif
typedef enum { ___1237, ___1236, ___1239, END_ExportRegion_e, ___1238 = ___329 } ExportRegion_e; typedef enum { ___2957, ___2955, ___2952, ___2951, ___2953, ___2954, END_PaperSize_e, ___2956 = ___329, ___2950  = ___2957, ___2948  = ___2955, ___2945      = ___2952, ___2944      = ___2951, ___2946 = ___2953, ___2947 = ___2954, ___2949 = ___2956 } PaperSize_e; typedef enum { ___2959, ___2962, ___2971, ___2966, ___2960, ___2963, ___2968, ___2970, ___2969, ___2958, ___2967, ___2965, ___2964, END_PaperUnitSpacing_e, ___2961 = ___329 } PaperUnitSpacing_e; typedef enum { ___2921, ___2922, ___2919, END_Palette_e, ___2920 = ___329 } Palette_e; typedef enum { ___3192, ___3190, END_PrintRenderType_e, ___3191 = ___329 } PrintRenderType_e; typedef enum { ___4270, ___4269, ___4272, ___4273, ___4268, END_Units_e, ___4271 = ___329 } Units_e; typedef enum { ___657, ___658, END_CoordScale_e, ___656 = ___329, ___3437  = ___657, ___3438     = ___658, ___3436 = ___656 } CoordScale_e;
 #define ___1752(___3266) (((___3266) < ___3629) ? ___3632 : (((___3266) > ___2178) ? ___2189 : ___2317((___3266))))
typedef enum { CoordSys_Grid, CoordSys_Frame, ___659, ___662, ___663, ___660, CoordSys_Grid3D, ___664, END_CoordSys_e, ___661 = ___329 } CoordSys_e; typedef enum { ___3445, ___3447, END_Scope_e, ___3446 = ___329 } Scope_e; typedef enum { ___4051, ___4046, ___4056, ___4053, ___4052, ___4054, ___4048, ___4047, ___4049, ___4055, END_TextAnchor_e, ___4050 = ___329 } TextAnchor_e; typedef enum { TextType_Regular, TextType_LaTeX, END_TextType_e, TextType_Invalid = ___329 } TextType_e; typedef enum { ___4076, ___4064, ___4070, END_TextBox_e, ___4071 = ___329 } TextBox_e; typedef enum { ___1646, ___1635, ___1637, ___1644, ___1639, ___1636, ___1633, ___1634, ___1645, ___1640, ___1643, ___1641, GeomShape_LineArt, ___1642, END_GeomShape_e, ___1638 = ___329 } GeomShape_e; typedef enum { ___348, ___347, ___346, ___345, ___343, END_BasicSize_e, ___344 = ___329 } BasicSize_e; typedef enum { ___2250, ___2247, ___2248, ___2252, ___2253, ___2251, END_LineForm_e, ___2249 = ___329 } LineForm_e; typedef enum { ___727, ___729, ___724, ___730, ___731, ___728, ___725, END_CurveType_e, ___726 = ___329, ___723 = ___729 } CurveType_e; typedef enum { ___3456, ___3458, ___3457, END_Script_e, ___3455 = ___329 } Script_e; typedef enum { ___1452, ___1453, ___1447, ___1457, ___1468, ___1464, ___1466, ___1465, ___1467, ___1443, ___1444, ___1446, Font_HelveticaItalic, Font_HelveticaItalicBold, Font_CourierItalic, Font_CourierItalicBold, END_Font_e, ___1454 = ___329 } Font_e; typedef enum { ___1463, ___1462, ___1459, ___1460, END_FontStyle_e, ___1461 = ___329 } FontStyle_e; typedef enum { ___4234, ___4233, END_TwoDDrawOrder_e, ___4235 = ___329 } TwoDDrawOrder_e; typedef enum { ___1112, ___1113, END_DrawOrder_e, ___1114 = ___329 } DrawOrder_e; typedef enum { ___3807, ___3808, ___3810, ___3811, ___3812, ___3809, END_Streamtrace_e, ___3805 = ___329 } Streamtrace_e; typedef enum { ___3795, ___3797, ___3794, END_StreamDir_e, ___3796 = ___329
} StreamDir_e; typedef enum { ___1090, ___1091, ___1092, ___1093, DistributionRegion_SurfacesOfSuppliedZones, END_DistributionRegion_e, ___1089 = ___329 } DistributionRegion_e; typedef enum { ___2044, ___2046, ___2048, ___2047, END_IsoSurfaceSelection_e, ___2045 = ___329 } IsoSurfaceSelection_e; typedef enum { ___4328, ___4330, END_ValueLocation_e, ___4329 = ___329 } ValueLocation_e; typedef enum { OffsetDataType_32Bit, OffsetDataType_64Bit, END_OffsetDataType_e, OffsetDataType_Invalid = ___329 } OffsetDataType_e;
 #define VALID_32OR64BIT_OFFSET_TYPE(t) ((t) == OffsetDataType_32Bit || (t) == OffsetDataType_64Bit)
typedef enum { ___1369, /**@internal TP_NOTAVAILABLE*/ FieldDataType_Float, FieldDataType_Double, FieldDataType_Int32, FieldDataType_Int16, FieldDataType_Byte, ___1363, END_FieldDataType_e, ___1364, /**@internal TP_NOTAVAILABLE*/ ___1366, /**@internal TP_NOTAVAILABLE*/ ___1368  = FieldDataType_Int32, ___1371 = FieldDataType_Int16, ___1367  = ___329 } FieldDataType_e;
 #define VALID_FIELD_DATA_TYPE(___1362)                                                                                   \
 (VALID_ENUM((___1362), FieldDataType_e) && (___1362) != ___1369)
 #if defined EXPORT_DEPRECATED_INTERFACES_TO_ADK_ONLY
typedef enum { ___2432, ___2427, ___2425, END_MeshPlotType_e, ___2426 = ___329 } MeshPlotType_e;
 #endif
typedef enum { ___2431, ___2430, ___2428, END_MeshType_e, ___2429 = ___329 } MeshType_e;
 #if defined EXPORT_DEPRECATED_INTERFACES_TO_ADK_ONLY
typedef enum { ___634, ___614, ___635, ___555, ___613, END_ContourPlotType_e, ___615 = ___329 } ContourPlotType_e;
 #endif
typedef enum { ___639, ___637, ___640, ___636, ___641, END_ContourType_e, ___638 = ___329 } ContourType_e; typedef enum { ___565, ___556, ___557, ___558, ___559, ___560, ___561, ___562, ___563, END_ContourColoring_e, ___564 = ___329 } ContourColoring_e;
 #if defined EXPORT_DEPRECATED_INTERFACES_TO_ADK_ONLY
typedef enum { ___4400, ___4396, ___4399, ___4397, END_VectorPlotType_e, ___4398 = ___329 } VectorPlotType_e;
 #endif
typedef enum { ___4405, ___4401, ___4404, ___4402, END_VectorType_e, ___4403 = ___329 } VectorType_e; typedef enum { ___3548, ___3547, ___3545, ___3544, ___3543, END_ShadePlotType_e, ___3546 = ___329 } ShadePlotType_e; typedef enum { ___2238, ___2240, ___2237, ___2239, END_LightingEffect_e, ___2235 = ___2240, ___2236 = ___329 } LightingEffect_e; typedef enum { SurfaceFlowEffect_None, SurfaceFlowEffect_LIC, SurfaceFlowEffect_WindMap, END_SurfaceFlowEffect_e, SurfaceFlowEffect_Invalid = ___329 } SurfaceFlowEffect_e; typedef enum { LICColorMode_Multiply = 0, LICColorMode_Blend    = 1, LICColorMode_Overlay  = 2, LICColorMode_Invert   = 3, END_LICColorMode_e, LICColorMode_Invalid = ___329 } LICColorMode_e; enum IJKLines_e { ___1856, ___1858, ___1859, END_IJKLines_e, ___1857 = ___329, ___2284       = ___1856, ___2286       = ___1858, ___2287       = ___1859, ___2285 = ___1857 }; typedef enum { ___1849, ___1847, ___1850, END_IJKCellType_e, ___1848 = ___329 } IJKCellType_e; typedef enum { ___1866, ___1871, ___1873, ___1865, ___1867, ___1872, ___1869, ___1868, ___1875, ___1874, END_IJKPlanes_e, ___1870 = ___329, ___3099       = ___1866, ___3104       = ___1871, ___3106       = ___1873, ___3100      = ___1867, ___3105      = ___1872, ___3102      = ___1869, ___3101     = ___1868, ___3098    = ___1865, ___3108  = ___1875, ___3107  = ___1874, ___3103 = ___1870 } IJKPlanes_e; typedef enum { ___3899, ___3900, ___3905, ___3907, ___3908, ___3902, ___3906, ___3903, ___3901, ___3898, ___3909, END_SurfacesToPlot_e, ___3904 = ___329 } SurfacesToPlot_e; typedef enum { ___3151, ___3148, ___3150, ___3146, ___3147, END_PointsToPlot_e, ___3152 = ___3151, ___3145          = ___3148, ___3149      = ___329 } PointsToPlot_e; typedef enum { ___3623, ___3625, ___3627, ___3620, ___3621, ___3622, ___3618, ___3617, END_SliceSurface_e, ___3619 = ___329 } SliceSurface_e; /* pytecplot defines this separately with CVar removed. */ typedef enum { ___501,
___499, ___498, END_ClipPlane_e, ___500 = ___329 } ClipPlane_e; typedef enum { ___3607, ___3606, END_SkipMode_e, ___3608 = ___329 } SkipMode_e; typedef enum { ___1137, ___1139, ___1138, END_EdgeType_e, ___1140 = ___329 } EdgeType_e;
 #if defined EXPORT_DEPRECATED_INTERFACES_TO_ADK_ONLY
typedef enum { ___391, ___390, ___389, ___383, END_BoundPlotType_e, ___388 = ___329 } BoundPlotType_e;
 #endif
typedef enum { ___397, ___396, ___395, ___393, END_BoundaryType_e, ___394 = ___329 } BoundaryType_e; typedef enum { ___382, ___381, ___380, ___378, END_BorderLocation_e, ___379 = ___329 } BorderLocation_e; typedef enum { ___608, ___579, ___582, ___576, ___611, ___610, ___609, ___590, ___567, ___568, ___566, ___569, ___570, ___571, ___573, ___574, ___575, ___577, ___580, ___572, ___581, ___583, ___584, ___585, ___586, ___587, ___588, ___589, ___591, ___592, ___593, ___595, ___594, ___596, ___597, ___598, ___602, ___599, ___600, ___601, ___603, ___604, ___605, ___606, ___607, END_ContourColorMap_e, ___578 = ___329, ___528  = ___608, ___525  = ___579, ___526     = ___582, ___523  = ___576, ___531       = ___611, ___530    = ___610, ___529   = ___609, ___527 = ___590, ___524    = ___578 } ContourColorMap_e; typedef enum { ___1182, ___1177, ___1180, ___1181, ___1178, ___1183, ___1176, END_ErrorBar_e, ___1179 = ___329 } ErrorBar_e; typedef enum { ___633, ___632, ___630, END_ContourLineMode_e, ___631 = ___329 } ContourLineMode_e; enum Panel_e { ___2923, ___2924, ___2943, ___2934, ___2929, ___2925, ___2927, ___2933, ___2926, ___2940, ___2941, ___2939, ___2931, Panel_IsoSurfaceVector, ___2932, ___2935, ___2938, ___2937, ___2936, ___2928, ___2942, END_Panel_e, ___2930 = ___329 }; typedef enum { ___2444, ___2448, ___2445, ___2447, /**@internal TP_NOPYTHON*/
___2450, ___2451, ___2449, END_MessageBoxType_e, ___2446 = ___329, ___2434           = ___2444, ___2452         = ___2448, ___2435     = ___2445, ___2437        = ___2447, ___2454           = ___2450, ___2455     = ___2451, ___2453 = ___2449, ___2436         = ___2446 } MessageBoxType_e; typedef enum { ___2442, ___2440, ___2438, ___2441, END_MessageBoxReply_e, ___2439 = ___329 } MessageBoxReply_e; typedef enum { ___2773, ___2772, ___2771, ___2768, ___2777, ___2769, ___2775, ___2776, ___2770, ___2778, END_NumberFormat_e, ___2774 = ___329 } NumberFormat_e; typedef NumberFormat_e ValueFormat_e; typedef enum { ___324, ___325, ___323, END_BackingStoreMode_e, ___322 = ___329 } BackingStoreMode_e; typedef enum { ___4169, ___4171, ___4168, END_TickDirection_e, ___4170 = ___329 } TickDirection_e; typedef enum { ___320, ___318, ___321, END_AxisTitlePosition_e, ___319 = ___329 } AxisTitlePosition_e; typedef enum { ___315, ___317, ___316, END_AxisTitleMode_e, ___314 = ___329 } AxisTitleMode_e; typedef enum { ___288, ___286, ___285, ___284, AxisAlignment_WithSpecificAngle, ___283, ___280, ___281, ___282, END_AxisAlignment_e, ___279 = ___329 } AxisAlignment_e; typedef enum { ___1537, ___1538, END_FunctionDependency_e, ___1534          = ___329, ___1536 = ___1537, ___1535     = ___1538 } FunctionDependency_e; typedef enum { LegendShow_Always, LegendShow_Never, ___2218, END_LegendShow_e, ___2219 = ___329, ___2221 = LegendShow_Always, ___2220  = LegendShow_Never } LegendShow_e; typedef enum { ___2260, LineMapSort_ByIndependentVar, LineMapSort_ByDependentVar, LineMapSort_BySpecificVar, END_LineMapSort_e, ___2259 = ___329, ___2258 = LineMapSort_ByIndependentVar, ___2257   = LineMapSort_ByDependentVar,
___2261    = LineMapSort_BySpecificVar, } LineMapSort_e; typedef enum { ___549, ___550, ___548, END_ContLegendLabelLocation_e, ___551 = ___329 } ContLegendLabelLocation_e; typedef enum { ___4145, ___4147, ___4144, END_ThetaMode_e, ___4146 = ___329 } ThetaMode_e; typedef enum { ___4214, ___4217, ___4215, ___4216, END_Transform_e, ___4213 = ___329 } Transform_e; typedef enum { ___4464, ___4465, ___4462, ___4461, END_WindowFunction_e, ___4463 = ___329 } WindowFunction_e; typedef enum { ___2204, ___2205, ___2203, END_LaunchDialogMode_e, ___2202 = ___329 } LaunchDialogMode_e; typedef enum { ___3469, ___3468, ___3466, ___3472, ___3471, END_SelectFileOption_e, ___3467 = ___329 } SelectFileOption_e; typedef enum { ___356, ___357, ___358, BinaryFileVersion_Tecplot2019, ___354 = BinaryFileVersion_Tecplot2019, END_BinaryFileVersion_e, ___355 = ___329 } BinaryFileVersion_e; typedef enum { ___4414, ___4412, ___4411, END_ViewActionDrawMode_e, ___4413 = ___329 } ViewActionDrawMode_e; typedef enum { ___2899, ___2900, ___2898, ___2905, ___2906, ___2902, ___2904, ___2903, END_PageAction_e, ___2901 = ___329 } PageAction_e; typedef enum { ___1505, ___1501, ___1499, ___1488, ___1490, ___1503, ___1500, ___1504, ___1487, ___1485, ___1486, ___1482, ___1483, ___1484, ___1495, ___1496, ___1497, ___1492, ___1493, ___1494, ___1506, FrameAction_DeleteByNumber, FrameAction_Reset, END_FrameAction_e, ___1491   = ___329, ___1498       = ___1501, ___1502      = ___1504, ___1489 = ___1488 } FrameAction_e; typedef enum { ___3011, ___3005, ___3006,
___3016, ___3014, ___3013, ___3012, ___3019, ___3020, ___3024, ___3018, ___3022, ___3021, ___3023, ___3015, ___3010, ___3009, ___3008, ___3007, END_PickAction_e, ___3017 = ___329 } PickAction_e; typedef enum { ___627, ___626, ___629, END_ContourLevelsInitializationMode_e, ___628 = ___329 } ContourLevelsInitializationMode_e; typedef enum { ___619, ___623, ___621, ___624, ___625, ___620, END_ContourLevelAction_e, ___622 = ___329 } ContourLevelAction_e; typedef enum { ___616, ___617, END_ContourLabelAction_e, ___618 = ___329 } ContourLabelAction_e; typedef enum { ___3799, ___3800, ___3801, ___3804, ___3803, END_StreamtraceAction_e, ___3802 = ___329 } StreamtraceAction_e; typedef enum { ___517, ___515, ___518, END_ColorMapControlAction_e, ___516 = ___329 } ColorMapControlAction_e; typedef enum { ___520, ___519, END_ColorMapDistribution_e, ___521 = ___329 } ColorMapDistribution_e; typedef enum { ___3388, ___3387, ___3386, ___3385, END_RGBMode_e, ___3384 = ___329 } RGBMode_e; typedef enum { TransientZoneVisibility_ZonesAtOrBeforeSolutionTime, TransientZoneVisibility_ZonesAtSolutionTime, END_TransientZoneVisibility_e, TransientZoneVisibility_Invalid = ___329 } TransientZoneVisibility_e; typedef enum { TimeScaling_Linear, TimeScaling_Logarithmic, END_TimeScaling_e, TimeScaling_Invalid = ___329 } TimeScaling_e; typedef enum { FEDerivativeMethod_GreenGauss, FEDerivativeMethod_MovingLeastSquares, END_FEDerivativeMethod_e, FEDerivativeMethod_Invalid = ___329 } FEDerivativeMethod_e; typedef enum { TransientOperationMode_SingleSolutionTime, TransientOperationMode_AllSolutionTimes, TransientOperationMode_AllSolutionTimesDeferred, END_TransientOperationMode_e, TransientOperationMode_Invalid = ___329 } TransientOperationMode_e; typedef enum { ExtractionStrandIDAssignment_DoNotAssignStrandIDs, ExtractionStrandIDAssignment_Auto, ExtractionStrandIDAssignment_OneStrandPerGroup, ExtractionStrandIDAssignment_OneStrandPerSubExtraction, END_ExtractionStrandIDAssignment_e, ExtractionStrandIDAssignment_Invalid = ___329
} ExtractionStrandIDAssignment_e; typedef enum { ___4038, ___4039, END_TecUtilErr_e, ___4037 = ___329 } TecUtilErr_e; enum AxisShape_e { ___298, ___296, ___297, ___294, END_AxisShape_e, ___295 = ___329 }; enum RunMode_e { ___3427, ___3428, ___3429, END_RunMode_e, ___3430 = ___329 }; typedef enum { ___1206, ___1202, ___1207, ___1201, ___1200, ___1205, ___1204, END_ExportCustReturnCode_e, ___1203 = ___329 } ExportCustReturnCode_e; typedef enum { ___806, ___805, ___808, ___809, ___811, ___812, ___810, END_CZType_e, ___807 = ___329 } CZType_e; typedef enum { ___1288, ___1287, ___1285, ___1284, END_FaceNeighborMode_e, ___1286 = ___329 } FaceNeighborMode_e; typedef enum { ___2915, PageRenderDest_WorkArea, PageRenderDest_AnnotateWorkArea, ___2916, ___2913, END_PageRenderDest_e, ___2914 = ___329 } PageRenderDest_e; enum RenderDest_e { ___3349, RenderDest_AnnotateWorkArea, ___3342, ___3341, ___3340, ___3339, ___3347, ___3344, END_RenderDest_e, ___3345 = ___329, ___3343 = ___3349, ___3346  = ___3339 }; typedef enum { ___3782, ___3783, ___3785, END_Stipple_e, ___3784 = ___329 } Stipple_e; typedef enum { ___843, ___844, ___846, END_DataFileType_e, ___845 = ___329 } DataFileType_e; typedef enum { ___538, ___539, END_ConditionAwakeReason_e, ___537 = ___329 } ConditionAwakeReason_e; typedef enum { ___3201, ___3202, ___3199, END_ProbeStatus_e, ___3200 = ___329 } ProbeStatus_e; typedef enum { ___1521, ___1522, END_FrameSizePosUnits_e, ___1520 = ___329 } FrameSizePosUnits_e; typedef enum { ___1813, ___1815, ___1814, END_Gridline_e, ___1812 = ___329 } Gridline_e; typedef enum { ___3171, ___3169, END_PositionMarkerBy_e, ___3170 = ___329 } PositionMarkerBy_e; typedef enum { ___2299, ___2300, ___2301,
END_LoaderCallbackVersion_e, ___2298 = ___329 } LoaderCallbackVersion_e; typedef enum { LoaderAdvancedOptions_NotAvailable, LoaderAdvancedOptions_Allow, LoaderAdvancedOptions_ForceLaunch, END_LoaderAdvancedOptions_e, LoaderAdvancedOptions_Invalid = ___329 } LoaderAdvancedOptions_e; typedef enum { ___3026, ___3028, ___3025, PickCollectMode_HomogeneousAdd, END_PickCollectMode_e, ___3027 = ___329 } PickCollectMode_e; typedef enum { ___398, ___400, END_BoundingBoxMode_e, ___399 = ___329 } BoundingBoxMode_e; typedef enum { ImageRenderingStrategy_Auto, ImageRenderingStrategy_OpenGL, ImageRenderingStrategy_OSMesa, END_ImageRenderingStrategy_e, ImageRenderingStrategy_Mesa    = ImageRenderingStrategy_OSMesa, ImageRenderingStrategy_Invalid = ___329 } ImageRenderingStrategy_e; typedef enum { PreTranslateData_Auto, PreTranslateData_On, PreTranslateData_Off, END_PreTranslateData_e, PreTranslateData_Invalid = ___329 } PreTranslateData_e; struct MinMax_s { double minValue; double maxValue; }; typedef struct ___2666* ___2665; typedef void* (*___4152)(___90 ___4151); typedef struct ___541* ___540; typedef struct ___2121* ___2119; typedef void (*___4161)(___90 ___2123); typedef struct StringList_s* ___3840; typedef struct Menu_s*       ___2420; typedef struct ___135* ___134; typedef struct LineSegmentProbeResult_s* ___2283; typedef enum { ___1899, ___1891, ___1896, ___1897, ___1900, ___1890, ___1892, ___1893, ___1898, ___1894, END_ImageResizeFilter_e, ___1895 = ___329 } ImageResizeFilter_e; typedef enum { ___4379, ___4374, ___4377, ___4375, ___4378, END_VarStatus_e, ___4376 = ___329 } VarStatus_e; typedef enum { ElementOrientation_Standard, ElementOrientation_Reversed, ElementOrientation_Arbitrary, END_ElementOrientation_e, ElementOrientation_Invalid = ___329 } ElementOrientation_e; typedef struct ___3503* ___3502; struct ___4579 { double X; double Y; }; struct ___4582 { double X; double Y; double Z;
 #if defined __cplusplus
bool operator==(___4582 const& ___2889) const { return (X == ___2889.X) && (Y == ___2889.Y) && (Z == ___2889.Z); }
 #endif
}; struct ___3251 { double ___3249; double ___4142; double ___30; }; namespace tecplot { class ___4238; } struct ___1548 { double ___4293; double ___4295; double ___4297; }; struct ___4150 { double ___4142; double ___3266; }; union ___54 { ___1548 ___1546; ___4582         ___4580; ___4150      ___4148; }; struct ___839 { char*                  ___3184; char*                  ___4041; DataFileType_e         ___1406; ___1396           ___840; ___3840          ___4363; ___1170             ___2848; ___1170             NumVars; double                 ___3640; struct ___839* ___2704; }; struct ___3873 { ___372 ___1918; ___372 ___1913; ___372 ___1921; ___372 ___1920; ___372 ___1915; ___372 ___1916; ___372 ___1910; ___372 ___1919; ___372 ___1911; ___372 UpdateInvalidContourLevels; ___372 ___1912; ___372 ___535; ___372 ___2424; ___372 ___1914; ___372 ___4285; }; struct ___2043 { ___372 ___3564; ___372 ___3578; ___372 ___3567; ___372 ___3587; ___372 ___3584; ___372 ___4284; ___372 ___4288; }; struct ___3611 { ___372 ___3564; ___372 ___3578; ___372 ___3567; ___372 ___3587; ___372 ___3584; ___372 ___3570; ___372 ___4284; ___372 ___4288; }; struct ___3806 { ___372 ___3564; ___372 ___3579; ___372 ___3568; ___372 ___3565; ___372 ___3578; ___372 ___3567; ___372 ___3584; ___372 ___3577; ___372 ___4284; ___372 ___4288; }; struct ___1372 {
 #if 0 
___372       ___3564;
 #endif
TwoDDrawOrder_e ___4232; ___372       ___3578; ___372       ___3567; ___372       ___3587; ___372       ___3583; ___372       ___3584; ___372       ___3570; ___372       ___4284; ___372       ___4288; ___372       UseSurfaceFlowEffect; }; struct ___2280 {
 #if 0 
___372       ___3564;
 #endif
___372 ___3576; ___372 ___3586; ___372 ___3566; ___372 ___3574; }; union ___1979 { double    ___3435; ___2226 ___3556; }; typedef ___372 (*___3886)(TP_IN_OUT double* ___4315, const char* ___3884); struct ___1950 { Input_e           ___4237; double            ___2471; double            ___2347; ___1979 ___1977; ___3886 ___3885; }; struct ___3391 { ___514 ___3266; ___514 G; ___514 B; bool operator==(___3391 const& ___3393) const { return ___3266 == ___3393.___3266 && G == ___3393.G && B == ___3393.B; } }; struct ___646 { double ___522; ___3391  ___2211; ___3391  ___4212; bool operator==(___646 const& ___3393) const { return ___522 == ___3393.___522 && ___2211 == ___3393.___2211 && ___4212 == ___3393.___4212; } }; struct ___1189 { int       ___1831; int       ___2105; int       ___2196; int       ___2200; int       ___337; int       ___338; int       ___422; Event_e   ___1188; ___372 ___2056; ___372 ___1998; ___372 ___2010; ___372 ___4450; ___372 ___4448; ___372 ___4449; }; struct ___2330 { ___2326          ___2333; struct ___2330* ___2703; }; struct ___1975 { ___2226 ___4567; ___2226 ___4584; ___2226 ___4568; ___2226 ___4585; }; struct ___3300 { double ___4567; double ___4584; double ___4568; double ___4585; bool operator==(___3300 const& ___2889) const { return ___4567 == ___2889.___4567 && ___4584 == ___2889.___4584 && ___4568 == ___2889.___4568 && ___4585 == ___2889.___4585; } bool operator!=(___3300 const& ___2889) const { return !operator==(___2889); } }; struct ___1878 { ___2226 ___1831; ___2226 ___2105; ___2226 ___2134; }; struct ___1172 { ___1170 ___2471; ___1170 ___2347; ___1170 ___3605; }; struct ___1928 { ___2226 ___2471; ___2226 ___2347; ___2226 ___3605; }; struct ___4124 { Font_e ___1442; double  ___1826; Units_e ___3602; }; struct ___205 { ___372 ___4283; Font_e fontOverride; ___3918 ___470; }; struct ___3920 { GeomShape_e  ___1632; ___372    ___2002; ___205 ___201; };
 #ifdef NOT_USED
struct AddOnList_s { int ___1127; };
 #endif
typedef struct AddOnList_s* ___11; struct ZoneMetrics; typedef ZoneMetrics* ZoneMetrics_pa; namespace tecplot { class ElemToNodeMap; } typedef tecplot::ElemToNodeMap* ___2728; typedef struct ___3871*   ___3870; typedef struct ___832*  ___831; typedef struct ___3868* ___3867; typedef struct ___2756*       ___2755; typedef struct ___832* ElementOrientation_pa;
 #define ___1988 (-1)
 #define ___2750 (-1)
 #define ___2751    (-1)
 #define ___4274                                                                                                  \
 (___2750 - 2) 
typedef struct ___1291* ___1290; typedef struct ___1270* ___1269; typedef struct ___1150* ___1149; namespace tecplot { class NodeToElemMap; } typedef tecplot::NodeToElemMap* ___2743; enum RecordingLanguage_e { RecordingLanguage_TecplotMacro, RecordingLanguage_Python, END_RecordingLanguage_e, RecordingLanguage_Invalid = ___329 }; enum FaceNeighborMemberArray_e { ___1280, ___1278, ___1276, ___1277, ___1275, FaceNeighborMemberArray_BndryConnectZoneUniqueIds, END_FaceNeighborMemberArray_e, ___1281 = ___329 }; int const ___1289 = (int)END_FaceNeighborMemberArray_e; enum FaceMapMemberArray_e { ___1264, ___1265, ___1263, ___1266, ___1262, ___1260, FaceMapMemberArray_FaceBndryItemElemZoneUniqueIds, END_FaceMapMemberArray_e, ___1267 = ___329 }; int const ___1268 = (int)END_FaceMapMemberArray_e; enum ElemToFaceMapMemberArray_e { ___1145, ___1146, END_ElemToFaceMapMemberArray_e, ___1147 = ___329 }; int const ___1148 = (int)END_ElemToFaceMapMemberArray_e; enum NodeToElemMapMemberArray_e { ___2740, ___2741, END_NodeToElemMapMemberArray_e, ___2739 = ___329 }; int const ___2742 = (int)END_NodeToElemMapMemberArray_e; typedef struct ___1360* ___1359; typedef struct AuxData_s* ___264; typedef class LayoutReadDataInfo_s* LayoutReadDataInfo_pa; typedef enum { ___927, ___928, ___929, ___931 = ___929, END_DataValueStructure_e, ___930 = ___329 } DataValueStructure_e; typedef enum { ___869, ___870, END_DataNodeStructure_e, ___871 = ___329 } DataNodeStructure_e; typedef enum { ___4361, ___4359, END_VarLockMode_e, ___4360 = ___329 } VarLockMode_e; typedef enum { ___1374, ___1375, END_FieldMapMode_e, ___1373 = ___329 } FieldMapMode_e; typedef enum { ___4275, ___4278, ___4277, END_UnloadStrategy_e, ___4276 = ___329 } UnloadStrategy_e; struct ___4648 { ___514 ___3175; ___372    ___2026; }; struct ___4683 { std::string ___2686; ___1170  ___2976; ___1170  ___3787;
double      ___3642; ___2226 ___2831; ___2226 ___2832; ___2226 ___2833; ___2226 ___2806; ___2226 ___2800; ___2226 ___2801; ZoneType_e     ___4237; ___372      ___2063; ___4648 ___4647; ___264     ___230; ___372      ___419; FaceNeighborMode_e ___1438; ___372          ___228; short tecplotFileZoneVersion; ___4683(ZoneType_e ___4692); ___4683(___4683 const& ___2889); ___4683& operator=(___4683 const& ___3393); ~___4683(); void      setType(ZoneType_e ___4692); ___2226 numIPts() const; ___2226 numJPts() const; ___2226 numKPts() const; ___2226 numNodesPerFace() const; ___2226 ___2805() const; ___2226 numFaceBndryFaces() const; ___2226 numFaceBndryItems() const; void      assignMetrics(___2226 numIPts, ___2226 numJPts, ___2226 numKPts); void      assignMetrics( ___2226 numIPts, ___2226 numJPts, ___2226 numKPts, ___2226 ___2805, ___2226 numFaceBndryFaces, ___2226 numFaceBndryItems); }; struct ___4078 { TextBox_e    ___411; double       ___2339; double       ___2291; ___514 ___351; ___514 ___1408; }; struct ___4119 { ___4265 ___4264; ___54  ___52; CoordSys_e   ___3168; ___1170   ___4600; ___372    ___227; ___514 ___351; ___4124  ___4122; ___4078    ___401; double       ___57; TextAnchor_e ___39; double       ___2289; Scope_e      ___3444; std::string  ___2332; Clipping_e   ___494; std::string  Text; TextType_e   TextType; struct ___4119* ___2706; struct ___4119* ___3183; }; struct ___1550 { ___1359 ___4294; ___1359 ___4296; ___1359 ___4298; }; struct ___3154 { ___1359 ___4143; ___1359 ___3276; }; struct ___446 { ___1359 ___4569; ___1359 ___4586; ___1359 ___4595; }; union ___1573 { ___1550   ___1546; ___446 ___4580; ___3154     ___4148; }; struct ___1630 { ___1630(); struct GeomAnchor { public: GeomAnchor( ); double XOrTheta() const; void   setXOrTheta(double value); double YOrR() const; void   setYOrR(double); double Z() const; void   setZ(double); ___54 anchorPosition() const; bool        operator==(GeomAnchor const&) const; bool        operator!=(GeomAnchor const&) const; GeomAnchor& operator=(GeomAnchor const&); private: double         m_XOrTheta; double         m_YOrR; mutable double m_Z; mutable bool   m_zPosHasBeenAssigned; }; ___4265            ___4264; GeomType_e            ___1651; CoordSys_e            ___3168; GeomAnchor            position; ___372             ___227; ___1170            ___4600; ___514          ___351; ___372             ___2022; ___514          ___1408; LinePattern_e         ___2265; double                ___2988; double                ___2291; Scope_e               ___3444; DrawOrder_e           ___1111; Clipping_e            ___494; FieldDataType_e       ___905;
char*                 ___2332; ArrowheadStyle_e      ___188; ArrowheadAttachment_e ___176; double                ___187; double                ___171; int32_t               ___2795; char*                 ___1883; char*                 WorldFileName; ___2226             EmbeddedLpkImageNumber; ___372             ___2334; double                ___3090; int32_t               ___2837; ___3462         ___2839; ___1573            ___1571; ImageResizeFilter_e   ___1889; struct ___1630* ___2705; struct ___1630* ___3177; double _WorldFileAssignedWidth; double _WorldFileAssignedHeight; double _WorldFileAssignedXPos; double _WorldFileAssignedYPos; }; typedef struct ___4119* ___4115; typedef struct ___1630* ___1622; typedef enum { MarchingCubeAlgorithm_Classic, MarchingCubeAlgorithm_ClassicPlus, MarchingCubeAlgorithm_MC33, END_MarchingCubeAlgorithm_e, MarchingCubeAlgorithm_Invalid = ___329 } MarchingCubeAlgorithm_e; typedef enum { DataStoreStrategy_Auto, DataStoreStrategy_Heap, END_DataStoreStrategy_e, DataStoreStrategy_Invalid = ___329 } DataStoreStrategy_e; typedef enum { ArgListArgType_ArbParamPtr, ArgListArgType_DoublePtr, ArgListArgType_ArbParam, ArgListArgType_Array, ArgListArgType_Double, ArgListArgType_Function, ArgListArgType_Int, ArgListArgType_Set, ArgListArgType_String, ArgListArgType_StringList, ArgListArgType_StringPtr, ArgListArgType_Int64Array, END_ArgListArgType_e, ArgListArgType_Invalid = ___329 } ArgListArgType_e; typedef enum { StateModernizationLevel_Latest, StateModernizationLevel_LatestFocus, StateModernizationLevel_2006, StateModernizationLevel_2012, StateModernizationLevel_2012Focus, StateModernizationLevel_2013, StateModernizationLevel_2013Focus, StateModernizationLevel_2014, StateModernizationLevel_2014Focus, StateModernizationLevel_2016R1, StateModernizationLevel_2016R1Focus, StateModernizationLevel_2018R3, StateModernizationLevel_2018R3Focus, StateModernizationLevel_2025R2, StateModernizationLevel_2025R2Focus, END_StateModernizationLevel_e, StateModernizationLevel_Invalid = ___329 } StateModernizationLevel_e; typedef ___372 (*___2909)(___3840 ___2908, ___90 ___3326); typedef void (*___2910)(___90 ___2907, ___90 ___3326); typedef void (*___2911)(___90 ___2907, ___90 ___3326); typedef ___372 (*___2863)( int32_t                  ___4459, int32_t                  ___1826, ExportRegion_e           ___1235, ImageRenderingStrategy_e imageRenderingStrategy, ___90               ___3326, TP_OUT ___90*       ___1885); typedef void (*___2864)(___90 ___1885, ___90 ___3326); typedef uint8_t const* (*OffscreenImageGetRGBADataCallback_pf)(___90 ___1885, ___90 ___3326);
typedef ___372 (*___4467)( HDC ___3189, ___90 ___1885, Palette_e ___2918, ___90 ___3326); typedef HDC (*___4466)(___90 ___3326); typedef ___372 (*___3337)( PageRenderDest_e ___2912, ___90 ___3338, ___90 ___3326); typedef ___372 (*___3351)(___90 ___2907, ___90 ___3326); typedef void (*___3348)( ___90 ___2907, ___90 ___3326, TP_OUT int32_t* ___4459, TP_OUT int32_t* ___1826); typedef void (*___3910)(___90 ___2907, ___90 ___3326); typedef void (*___2155)( ___90        ___3326, TP_OUT ___372* ___2057, TP_OUT ___372* ___1999, TP_OUT ___372* ___2009); typedef ___372 (*___2580)(int ___420, ___90 ___3326); typedef void (*___4445)(___372 ___2, ___90 ___3326); typedef void (*___335)( CursorStyle_e ___692, ___90 ___3350, ___90 ___3326); typedef void (*___3473)( double ___4567, double ___4584, double ___4568, double ___4585, ___372 ___512, ___90 ___3326); typedef void (*___3203)(___90 ___3326); typedef void (*___1166)(___90 ___3326); typedef ___372 (*___1022)(___90 ___3326); typedef void (*___995)(___90 ___3326); typedef void (*___1099)(___90 ___3326, TP_OUT double* ___1837, TP_OUT double* ___2109); typedef ___372 (*___1012)( const char* ___1958, char** ___4331, ___372 ___3174, ___90 ___3325); typedef MessageBoxReply_e (*___1031)( const char* ___2457, MessageBoxType_e ___2443, ___90 ___3326); typedef ___372 (*___1062)( SelectFileOption_e ___1036, const char*        ___1075, const char*        ___948, const char*        ___947, TP_GIVES char**    ___3364, ___90         ___3326); typedef void (*___3778)(const char* ___3781, ___90 ___3326); typedef void (*___3582)( const char* ___1419, const char* ___3459, ___90 ___3326); typedef void (*___3244)(int ___3247, ___90 ___3326); typedef void (*___3246)( ___372 ___3581, ___372 ___2028, ___90 ___3326); typedef void (*___3245)(___90 ___3326); typedef void (*___2619)(
const char* ___2206, ___372 operationSucceeded, ___90 ___3326); typedef void (*___2411)(___90 ___3326); typedef ___372 (*___2413)(___90 ___3326); typedef ___372 (*___2414)(___90 ___3326); typedef void (*___3194)(___372 ___2033); typedef void (*___3195)(___372 ___4451, ___372 ___2033, ___90 ___492); typedef ___372 (*___1110)(RedrawReason_e ___3303, ___90 ___492); typedef ___372 (*WriteLayoutPreWriteCallback_pf)(___3502 PageList, ___90 ___492); typedef int (*___3845)(const char* ___3815, const char* ___3816, ___90 ___492); typedef ___372 (*DeferredZoneMetricsLoad_pf)(___90 clientData, ZoneMetrics_pa zoneMetrics); typedef void (*DeferredZoneMetricsCleanup_pf)(___90 clientData); typedef double (*___1381)(___1359 ___1307, ___2226 ___3250); typedef void (*___1382)(___1359 ___1307, ___2226 ___3250, double ___4299); typedef ___372 (*___2312)(___1359 ___1350); typedef ___372 (*___2313)(___1359 ___1350); typedef void (*___2311)(___1359 ___1350); typedef ___2733 (*NodeMapGetValue_pf)(___2728 ___2724, ___2226 nodeOffset); typedef void (*NodeMapSetValue_pf)(___2728 ___2724, ___2226 nodeOffset, ___2733 nodeValue); typedef ___372 (*___2309)(___2728 ___2725); typedef ___372 (*___2310)(___2728 ___2725); typedef void (*___2308)(___2728 ___2725); typedef ___372 (*___2306)(___1290 ___1273); typedef ___372 (*___2307)(___1290 ___1273); typedef void (*___2305)(___1290 ___1273); typedef ___372 (*___2303)(___1269 ___1258); typedef ___372 (*___2304)(___1269 ___1258); typedef void (*___2302)(___1269 ___1258); typedef ___372 (*LoadOnDemandElemToFaceMapLoad_pf)(___1149 EFM); typedef ___372 (*LoadOnDemandElemToFaceMapUnload_pf)(___1149 EFM); typedef void (*LoadOnDemandElemToFaceMapCleanup_pf)(___1149 EFM); typedef void (*___1248)(___2226 ___2830, double* ___4577, double* ___4594); typedef void (*___651)( const char* ___3178, const char* ___3179, ___3502 ___3180); typedef ___372 (*___886)(char* ___848, char* ___4042, TP_GIVES char** ___2457); typedef ___372 (*___896)(___3840 ___1959); typedef ___372 (*___859)(___3840 ___1959, ___90 ___492); typedef void (*___860)(); typedef void (*___861)(
___3840 ___3464, ___372 ___21, ___372 ___82, ___90 ___492); typedef void (*___862)( ___3840 ___3464, ___372 ___21, ___90 ___492); typedef ___372 (*___895)(___3840 ___1959); typedef ___372 (*___858)(___3840 ___1959, ___90 ___492); typedef ___372 (*___932)(const char* ___3463, ___90 ___492); typedef void (*___1663)(___3502 ___2256, ___3840 ___3465); typedef void (*___1659)( ___1170 ___2254, char* ___722, TP_GIVES char** ___0); typedef ___372 (*___1662)( ___1359    ___3275, ___1359    ___3274, CoordScale_e    ___1929, CoordScale_e    ___961, ___2226       ___2834, ___1170      ___2254, char*           ___722, TP_GIVES char** ___721); typedef ___372 (*___1751)( ___1359   ___3275, ___1359   ___3274, CoordScale_e   ___1929, CoordScale_e   ___961, ___2226      ___2834, ___2226      ___2791, ___1170     ___2254, char*          ___722, TP_OUT double* ___1924, TP_OUT double* ___960); typedef ___372 (*___1769)( ___1359   ___3275, ___1359   ___3274, CoordScale_e   ___1929, CoordScale_e   ___961, ___2226      ___2834, ___2226      ___2791, ___1170     ___2255, char*          ___722, double         ___3196, TP_OUT double* ___3193); typedef ___372 (*___3176)(MSG* ___3123); typedef ___372 (*___1134)(double ___4315, ___90 ___492, TP_GIVES char** ___2173); typedef void (*___2875)(___90 ___492); typedef ___372 (*___3453)(const char* ___3454, ___90 ___492); typedef ___372 (*___2282)( ___2226        ___4452, ___1170       ___4600, ___2226        ___448, ___2226        ___1250, TP_GIVES double* ___3162, ___90       ___492); typedef ___372 (*___4241)(const uint32_t* ___2212, const uint32_t* ___3396, ___90 ___492); typedef ___372 (*___4242)(const uint64_t* ___2212, const uint64_t* ___3396, ___90 ___492); typedef void (*TUAbort_pf)(const char* error_message); typedef ___3840 (*MatchVariablesCallback_pf)( ___3840        existingVariables, ___3840 const* incomingVariableLists, ___2226            numIncomingVariableLists, ___90           clientData);
 #define ___1476          0
 #define ___1475          1
 #define ___1478              2
 #define ___1477 3
typedef struct ViewState_s* ___3433; typedef struct ViewState_s* ___4436; typedef struct ProbeInfo_s* ___3198; static const char* const ___4032 = "support@tecplot.com";
 #define ___4036 0 
 #define TECUTIL_DEFAULT_TEXT_ID -1
typedef ___90 TextID_t; typedef ___90 GeomID_t;

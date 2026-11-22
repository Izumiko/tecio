 #pragma once
#include "ItemAddress.h"
 #define UNINITIALIZED_REF ((void*)0x11111111)
 #define INVALID_FN_REF    ((void*)NULL)
 #define VALID_HANDLE(handle) ((handle) != 0)
 #define VALID_FN_REF_OR_NULL(___3252) IMPLICATION((___3252) != NULL, VALID_FN_REF(___3252))
 #define VALID_TRANSLATED_STRING(___4229) (!(___4229).___2034())
struct ___800; bool VALID_FE_CLASSIC_CELL_INDEX(___800 const* ___798, ___2226 ___460); bool VALID_FE_CELL_INDEX(___800 const* ___798, ___2226 ___460); bool VALID_FE_CELL_INDEX(___800 const* ___798, tecplot::ItemAddress64 const& ___449);
 #define VALID_IPLANE_CELL_INDEX(___799, ___461)                                                                             \
 (                                                                                                 \
 (___461) >= 0 && ___1841((___799), ___461) <= MAX((___799)->___2812, 1) &&                                         \
 ___2111((___799), ___461) < MAX((___799)->___2817, 1) && ___2156((___799), ___461) < MAX((___799)->___2820, 1))
 #define VALID_JPLANE_CELL_INDEX(___799, ___461)                                                                             \
 (                                                                                                 \
 (___461) >= 0 && ___1841((___799), ___461) < MAX((___799)->___2812, 1) &&                                          \
 ___2111((___799), ___461) <= MAX((___799)->___2817, 1) && ___2156((___799), ___461) < MAX((___799)->___2820, 1))
 #define VALID_KPLANE_CELL_INDEX(___799, ___461)                                                                             \
 (                                                                                                 \
 (___461) >= 0 && ___1841((___799), ___461) < MAX((___799)->___2812, 1) &&                                          \
 ___2111((___799), ___461) < MAX((___799)->___2817, 1) && ___2156((___799), ___461) <= MAX((___799)->___2820, 1))
 #define VALID_ORDERED_CELL_INDEX(___799, ___461, ___3096)                                                                     \
 (                                                                                                  \
 ((IJKPlanes_e)(___3096) == ___1866 || (IJKPlanes_e)(___3096) == ___1871 || (IJKPlanes_e)(___3096) == ___1873 ||     \
 (IJKPlanes_e)(___3096) == ___1875) &&                                                                             \
 \
                                                                                                  \
 (IMPLICATION(                                                                                                             \
 ((IJKPlanes_e)(___3096) == ___1866 || (IJKPlanes_e)(___3096) == ___1875),                                   \
 VALID_IPLANE_CELL_INDEX((___799), ___461)) &&                                                                     \
 IMPLICATION(                                                                                                             \
 ((IJKPlanes_e)(___3096) == ___1871 || (IJKPlanes_e)(___3096) == ___1875),                                   \
 VALID_JPLANE_CELL_INDEX((___799), ___461)) &&                                                                     \
 IMPLICATION(                                                                                                             \
 ((IJKPlanes_e)(___3096) == ___1873 || (IJKPlanes_e)(___3096) == ___1875),                                   \
 VALID_KPLANE_CELL_INDEX((___799), ___461))))
bool VALID_CELL_INDEX(___800 const* ___798, ___2226 ___460, IJKPlanes_e ___1864); bool VALID_CELL_INDEX(___800 const* ___798, tecplot::ItemAddress64 const& ___449, IJKPlanes_e ___1864);
 #define VALID_DATASET(___880, ___482) (((___880) != NULL) && IMPLICATION((___482), (___880)->___2848 >= 1))
 #define VALID_SET_INDEX(___3493) (((___3494)___3493) >= (___3494)1)
 #define VALID_FILE_HANDLE(___3793) ((___3793) != NULL)
 #define VALID_BASIC_COLOR(___351) (___1418 <= (___351) && (___351) <= ___2194)
 #define VALID_CONTOUR_COLOR(Color)                                                                                             \
 (___612 <= (Color) && (Color) < ___612 + ___1545.___2242.___2380 + 1)
 #define VALID_PLOTTING_COLOR(Color)            (VALID_BASIC_COLOR(Color) || VALID_CONTOUR_COLOR(Color))
 #define VALID_INTERFACE_SPECIFIC_COLOR(___351) (___1421 <= (___351) && (___351) <= ___2199)
 #define VALID_INTERFACE_COLOR(Color)           (VALID_PLOTTING_COLOR(Color) || VALID_INTERFACE_SPECIFIC_COLOR(Color))
 #define VALID_MULTICOLOR_COLOR(Color)                                                                                          \
 (((Color) == ___2663) || ((Color) == ___2656) || ((Color) == ___2657) || ((Color) == ___2658) ||    \
 ((Color) == ___2659) || ((Color) == ___2660) || ((Color) == ___2661) || ((Color) == ___2662))
 #define VALID_RGB_COLOR(Color)                 ((Color) == ___3376)
 #define VALID_ASSIGNABLE_COLOR(C)              (VALID_BASIC_COLOR(C) || VALID_MULTICOLOR_COLOR(C) || VALID_RGB_COLOR(C))
 #define VALID_PEN_OFFSET(___3001)            (___364 <= (___3001) && (___3001) <= ___2827)
 #define VALID_PEN_OFFSET_FOR_OBJECT(___3001) (___1422 <= (___3001) && (___3001) <= ___2201)
 #define VALID_NAME(___2687, ___2377)                                                                                            \
 (VALID_REF(___2687) &&                                                                                                        \
 (___2016(___2687) || (!tecplot::isspace((___2687)[0]) && !tecplot::isspace((___2687)[strlen(___2687) - 1]))) &&                 \
 strlen(___2687) <= (___2377))
 #define VALID_ZONE_NAME(___2687) VALID_NAME((___2687), ___2359)
 #define VALID_VAR_NAME(___2687)  VALID_NAME((___2687), ___2357)
 #define VALID_LIGHTINGEFFECT(___2164)                                                                                                \
 (((___2164) == ___2238) || ((___2164) == ___2239) || ((___2164) == ___2240))
 #if defined NO_ASSERTS
 #if !defined NOT_IMPLEMENTED
 #if defined ___1839
 #define NOT_IMPLEMENTED() ___476(___1303)
 #else
 #if defined MSWIN
 #define NOT_IMPLEMENTED(x) ASSERT(!("Not Implemented"))
 #elif defined UNIXX
 #define NOT_IMPLEMENTED() not ___1906 
 #endif
 #endif
 #endif
 #else
 #if defined NICE_NOT_IMPLEMENTED
 #define NOT_IMPLEMENTED() ___2707()
 #else
 #define NOT_IMPLEMENTED() ASSERT(!("Not Implemented"))
 #endif
 #endif
 #if defined NICE_NOT_IMPLEMENTED
extern void ___2707();
 #endif

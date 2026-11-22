 #pragma once
#include "ThirdPartyHeadersBegin.h"
#include <functional>
#include <memory>
#include <string>
#include <utility>
#include <vector>
#include "ThirdPartyHeadersEnd.h"
 #define _TEXT_H_INCLUDED
 #define VALID_TEXT_COORDSYS(___3921) (((___3921) == CoordSys_Frame) || ((___3921) == CoordSys_Grid) || ((___3921) == CoordSys_Grid3D))
 #define VALID_TEXT_UNITS(___4267)  (((___4267) == ___4270) || ((___4267) == ___4269) || ((___4267) == ___4272))
 #define VALID_TEXT_COORDSYS_AND_UNITS(___3172, ___3603)                                                                     \
 (VALID_TEXT_COORDSYS((___3172)) && VALID_TEXT_UNITS((___3603)) &&                                                       \
 !((___3172) == CoordSys_Frame && (___3603) == ___4270))
 #define VALID_FONT_SIZEUNITS(___4267)                                                                                            \
 (((___4267) == ___4270) || ((___4267) == ___4269) || ((___4267) == ___4272) || (___4267) == ___4268)

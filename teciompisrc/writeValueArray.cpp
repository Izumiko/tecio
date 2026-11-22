#include "writeValueArray.h"
#include "ThirdPartyHeadersBegin.h"
#include <utility>
#include "ThirdPartyHeadersEnd.h"
#include "SzlFileLoader.h"
#include "AsciiOutputInfo.h"
namespace tecplot { namespace ___3934 {
 #if defined ASCII_ANNOTATE_TYPES
template <typename T> struct AsciiTypeString; template <> struct AsciiTypeString<char> { static char const* typeString; }; template <> struct AsciiTypeString<uint8_t> { static char const* typeString; }; template <> struct AsciiTypeString<int16_t> { static char const* typeString; }; template <> struct AsciiTypeString<uint16_t> { static char const* typeString; }; template <> struct AsciiTypeString<int32_t> { static char const* typeString; }; template <> struct AsciiTypeString<uint32_t> { static char const* typeString; }; template <> struct AsciiTypeString<uint64_t> { static char const* typeString; }; template <> struct AsciiTypeString<int64_t> { static char const* typeString; }; template <> struct AsciiTypeString<float> { static char const* typeString; }; template <> struct AsciiTypeString<double> { static char const* typeString; }; template <> struct AsciiTypeString<StdPairUInt8> { static char const* typeString; }; template <> struct AsciiTypeString<StdPairInt16> { static char const* typeString; }; template <> struct AsciiTypeString<StdPairInt32> { static char const* typeString; }; template <> struct AsciiTypeString<StdPairFloat> { static char const* typeString; }; template <> struct AsciiTypeString<StdPairDouble> { static char const* typeString; }; char const* AsciiTypeString<char>::typeString          = "char"; char const* AsciiTypeString<uint8_t>::typeString       = "uint8_t"; char const* AsciiTypeString<int16_t>::typeString       = "int16_t"; char const* AsciiTypeString<uint16_t>::typeString      = "uint16_t"; char const* AsciiTypeString<int32_t>::typeString       = "int32_t"; char const* AsciiTypeString<uint32_t>::typeString      = "uint32_t"; char const* AsciiTypeString<uint64_t>::typeString      = "uint64_t"; char const* AsciiTypeString<int64_t>::typeString       = "int64_t"; char const* AsciiTypeString<float>::typeString         = "float"; char const* AsciiTypeString<double>::typeString        = "double"; char const* AsciiTypeString<StdPairUInt8>::typeString  = "2*uint8_t"; char const* AsciiTypeString<StdPairInt16>::typeString  = "2*int16_t"; char const* AsciiTypeString<StdPairInt32>::typeString  = "2*int32_t"; char const* AsciiTypeString<StdPairFloat>::typeString  = "2*float"; char const* AsciiTypeString<StdPairDouble>::typeString = "2*double";
 #endif
template ___372 encodeAsciiValue<uint32_t, false, 0>(char* str, int ___418, uint32_t const& ___4299);
 #define SPECIALIZE_MIN_MAX_ENCODING_FOR_TYPE(T)                                                                                \
 template <>                                                                                                                \
 ___372 encodeAsciiValue<std::pair<T, T>, false, 0>(char* str, int ___418, std::pair<T, T> const& minMax)            \
 {                                                                                                                          \
 REQUIRE(VALID_REF(str));                                                                                               \
 REQUIRE(___418 > 0);                                                                                               \
 REQUIRE(minMax.first == minMax.first);                                                                                 \
 REQUIRE(minMax.second == minMax.second);                                                                               \
 std::string ___1472 =                                                                                          \
 std::string(___199<T, false>::___1472) + " " + ___199<T, false>::___1472;        \
 int nChars = snprintf(                                                                                                 \
 str,                                                                                                               \
 ___418,                                                                                                        \
 ___1472.c_str(),                                                                                           \
 -___199<T, false>::size,                                                                                  \
 minMax.first,                                                                                                      \
 -___199<T, false>::size,                                                                                  \
 minMax.second);                                                                                                    \
 ___372 ___2038 = (nChars > 0 && nChars < ___418);                                                                  \
 ENSURE(VALID_BOOLEAN(___2038));                                                                                           \
 return ___2038;                                                                                                           \
 }
SPECIALIZE_MIN_MAX_ENCODING_FOR_TYPE(uint8_t) SPECIALIZE_MIN_MAX_ENCODING_FOR_TYPE(int16_t) SPECIALIZE_MIN_MAX_ENCODING_FOR_TYPE(int32_t) SPECIALIZE_MIN_MAX_ENCODING_FOR_TYPE(float) SPECIALIZE_MIN_MAX_ENCODING_FOR_TYPE(double) template <typename T, bool ___2024, int base> ___372 ___4563( FileWriterInterface& file, char const*          ___970, ___81           ___1249, size_t               ___2798, T const*             ___4300, size_t               ___4334  ) { ___372 ___2038 = ___4227; REQUIRE(file.___2040()); REQUIRE(VALID_DESCRIPTION(___970)); REQUIRE("extraID could have any value. NO_EXTRA_ID show only the description"); REQUIRE(VALID_REF(___4300)); if (___2798 > 0) { if (file.___2001()) { ASSERT_ONLY(___1391 beginningLocation = file.fileLoc()); std::string ___1416 = ___970; if (___1249 != ___2746) ___1416 += ___4188(___1249 + 1);
 #if defined ASCII_ANNOTATE_TYPES
___1416.append(1, ' ').append(AsciiTypeString<T>::typeString);
 #endif
if (___2798 == 1) file.fprintf( "%*s  ", -___206, ___1416.c_str()); else file.fprintf("%*s\r\n", -___206, ___1416.c_str()); const int buffSize = 100; char      buff[buffSize]; std::string outputBuffer; for (size_t pos = 1; pos <= ___2798; ++pos) { ___2038 = ___2038 && encodeAsciiValue<T, ___2024, base>(buff, buffSize, ___4300[pos - 1]); outputBuffer.append(buff); if ((pos % ___4334) == 0 || (pos == ___2798)) outputBuffer.append("\r\n"); else outputBuffer.append("  "); } file.fwrite(outputBuffer.c_str(), sizeof(char), outputBuffer.size()); ASSERT_ONLY(___1391 endingLocation = file.fileLoc()); ASSERT_ONLY(___1391 outputSize = (___1391)___206 + 2 + outputBuffer.size()); ___476(endingLocation - beginningLocation == outputSize); } else { file.fwrite(___4300, sizeof(T), ___2798); } } ENSURE(VALID_BOOLEAN(___2038)); return ___2038; } template <typename OutType> ___372 ___4528( FileWriterInterface& file, char const*          ___970, ___81           ___1249, size_t               ___2798, ___2480 const*        ___4300, size_t               ___4334  ) { ___372 ___2038 = ___4227; if (___2798 > 0) { ___2241<std::pair<OutType, OutType>> outputArray; ___2038 = outputArray.alloc(___2798); if (___2038) { for (size_t i = 0; i < ___2798; ++i) { outputArray[i].first  = static_cast<OutType>(___4300[i].minValue()); outputArray[i].second = static_cast<OutType>(___4300[i].maxValue()); } ___2038 = ___4563<std::pair<OutType, OutType>, false, 0>( file, ___970, ___1249, ___2798, outputArray.data(), ___4334); } } return ___2038; } template <typename T, bool ___2024> uint64_t arrayValueSizeInFile(bool ___2001) { if (___2001) return ___199<T, ___2024>::size + ASCII_SPACING_LEN; return sizeof(T); } template <typename T, bool ___2024> uint64_t arraySizeInFile(size_t ___2798, bool ___2001) { uint64_t charsPerNumber = arrayValueSizeInFile<T, ___2024>(___2001); ___476(charsPerNumber > 0); uint64_t ___3359 = static_cast<uint64_t>(___2798) * charsPerNumber; if (___2001 && ___2798 > 0) ___3359 += static_cast<uint64_t>(___206) + ASCII_SPACING_LEN; return ___3359; } template <typename T, bool ___2024> uint64_t valueSizeInFile(bool ___2001) { return arraySizeInFile<T, ___2024>(1, ___2001); }
 #define INSTANTIATE_FOR_TYPE(T, ___2024)                                                                                         \
 template ___372 ___4563<T, ___2024, 0>(                                                                           \
 FileWriterInterface & file,                                                                                            \
 char const* ___970,                                                                                               \
 ___81  ___1249,                                                                                                   \
 size_t      ___2798,                                                                                         \
 T const*    ___4300,                                                                                                  \
 size_t      ___4334);                                                                                            \
 template uint64_t arrayValueSizeInFile<T, ___2024>(bool ___2001);                                                            \
 template uint64_t valueSizeInFile<T, ___2024>(bool ___2001);                                                                 \
 template uint64_t arraySizeInFile<T, ___2024>(size_t ___2798, bool ___2001);
INSTANTIATE_FOR_TYPE(char, false) INSTANTIATE_FOR_TYPE(uint8_t, false) INSTANTIATE_FOR_TYPE(uint8_t, true) INSTANTIATE_FOR_TYPE(int16_t, false) INSTANTIATE_FOR_TYPE(uint16_t, false) INSTANTIATE_FOR_TYPE(uint16_t, true) INSTANTIATE_FOR_TYPE(int32_t, false) INSTANTIATE_FOR_TYPE(uint32_t, false) INSTANTIATE_FOR_TYPE(uint64_t, false) INSTANTIATE_FOR_TYPE(uint64_t, true) INSTANTIATE_FOR_TYPE(int64_t, false) INSTANTIATE_FOR_TYPE(int64_t, true) INSTANTIATE_FOR_TYPE(float, false) INSTANTIATE_FOR_TYPE(double, false) INSTANTIATE_FOR_TYPE(StdPairFloat, false) INSTANTIATE_FOR_TYPE(StdPairDouble, false) INSTANTIATE_FOR_TYPE(StdPairInt32, false) INSTANTIATE_FOR_TYPE(StdPairInt16, false) INSTANTIATE_FOR_TYPE(StdPairUInt8, false) template ___372 ___4563<uint32_t, false, 1>( FileWriterInterface& file, char const*          ___970, ___81           ___1249, size_t               ___2798, uint32_t const*      ___4300, size_t               ___4334);
 #define INSTANTIATE_MIN_MAX_OUTPUT_FOR_TYPE(T)                                                                                 \
 template ___372 ___4528<T>(                                                                                    \
 FileWriterInterface & file,                                                                                            \
 char const*   ___970,                                                                                             \
 ___81    ___1249,                                                                                                 \
 size_t        ___2798,                                                                                       \
 ___2480 const* ___4300,                                                                                                \
 size_t        ___4334);
INSTANTIATE_MIN_MAX_OUTPUT_FOR_TYPE(uint8_t) INSTANTIATE_MIN_MAX_OUTPUT_FOR_TYPE(int16_t) INSTANTIATE_MIN_MAX_OUTPUT_FOR_TYPE(int32_t) INSTANTIATE_MIN_MAX_OUTPUT_FOR_TYPE(float) INSTANTIATE_MIN_MAX_OUTPUT_FOR_TYPE(double) }}

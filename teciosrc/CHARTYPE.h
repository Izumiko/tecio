 #ifndef TECPLOT_CHARTYPE
 #define TECPLOT_CHARTYPE
#include <cctype>
#include <locale>
 #if defined EXTERN
 #undef EXTERN
 #endif
 #if defined ___475
 #define EXTERN
 #else
 #define EXTERN extern
 #endif
#include "CodeContract.h"
namespace tecplot { template <typename CHAR_TYPE> inline bool isspace(CHAR_TYPE ch, std::locale const& ___2314 = std::locale::classic()) {
 #if defined ___3894
REQUIRE(___2314 == std::locale::classic()); return ::isspace(static_cast<int>(ch));
 #else
REQUIRE(std::has_facet<std::ctype<wchar_t>>(___2314)); return std::use_facet<std::ctype<wchar_t>>(___2314).is(std::ctype_base::space, static_cast<wchar_t>(ch));
 #endif
} template <typename CHAR_TYPE> inline bool ___2049(CHAR_TYPE ch, std::locale const& ___2314 = std::locale::classic()) {
 #if defined ___3894
REQUIRE(___2314 == std::locale::classic()); return ::___2049(static_cast<int>(ch));
 #else
REQUIRE(std::has_facet<std::ctype<wchar_t>>(___2314)); return std::use_facet<std::ctype<wchar_t>>(___2314).is(std::ctype_base::print, static_cast<wchar_t>(ch));
 #endif
} template <typename CHAR_TYPE> inline bool ___2008(CHAR_TYPE ch, std::locale const& ___2314 = std::locale::classic()) {
 #if defined ___3894
REQUIRE(___2314 == std::locale::classic()); return ::___2008(static_cast<int>(ch));
 #else
REQUIRE(std::has_facet<std::ctype<wchar_t>>(___2314)); return std::use_facet<std::ctype<wchar_t>>(___2314).is(std::ctype_base::cntrl, static_cast<wchar_t>(ch));
 #endif
} template <typename CHAR_TYPE> inline bool isupper(CHAR_TYPE ch, std::locale const& ___2314 = std::locale::classic()) {
 #if defined ___3894
REQUIRE(___2314 == std::locale::classic()); return ::isupper(static_cast<int>(ch));
 #else
REQUIRE(std::has_facet<std::ctype<wchar_t>>(___2314)); return std::use_facet<std::ctype<wchar_t>>(___2314).is(std::ctype_base::upper, static_cast<wchar_t>(ch));
 #endif
} template <typename CHAR_TYPE> inline bool ___2031(CHAR_TYPE ch, std::locale const& ___2314 = std::locale::classic()) {
 #if defined ___3894
REQUIRE(___2314 == std::locale::classic()); return ::___2031(static_cast<int>(ch));
 #else
REQUIRE(std::has_facet<std::ctype<wchar_t>>(___2314)); return std::use_facet<std::ctype<wchar_t>>(___2314).is(std::ctype_base::lower, static_cast<wchar_t>(ch));
 #endif
} template <typename CHAR_TYPE> inline bool ___1997(CHAR_TYPE ch, std::locale const& ___2314 = std::locale::classic()) {
 #if defined ___3894
REQUIRE(___2314 == std::locale::classic()); return ::___1997(static_cast<int>(ch));
 #else
REQUIRE(std::has_facet<std::ctype<wchar_t>>(___2314)); return std::use_facet<std::ctype<wchar_t>>(___2314).is(std::ctype_base::alpha, static_cast<wchar_t>(ch));
 #endif
} template <typename CHAR_TYPE> inline bool ___2011(CHAR_TYPE ch, std::locale const& ___2314 = std::locale::classic()) {
 #if defined ___3894
REQUIRE(___2314 == std::locale::classic()); return ::___2011(static_cast<int>(ch));
 #else
REQUIRE(std::has_facet<std::ctype<wchar_t>>(___2314)); return std::use_facet<std::ctype<wchar_t>>(___2314).is(std::ctype_base::digit, static_cast<wchar_t>(ch));
 #endif
} template <typename CHAR_TYPE> inline bool ___2051(CHAR_TYPE ch, std::locale const& ___2314 = std::locale::classic()) {
 #if defined ___3894
REQUIRE(___2314 == std::locale::classic()); return ::___2051(static_cast<int>(ch));
 #else
REQUIRE(std::has_facet<std::ctype<wchar_t>>(___2314)); return std::use_facet<std::ctype<wchar_t>>(___2314).is(std::ctype_base::punct, static_cast<wchar_t>(ch));
 #endif
} template <typename CHAR_TYPE> inline bool ___2083(CHAR_TYPE ch, std::locale const& ___2314 = std::locale::classic()) {
 #if defined ___3894
REQUIRE(___2314 == std::locale::classic()); return ::___2083(static_cast<int>(ch));
 #else
REQUIRE(std::has_facet<std::ctype<wchar_t>>(___2314)); return std::use_facet<std::ctype<wchar_t>>(___2314).is(std::ctype_base::xdigit, static_cast<wchar_t>(ch));
 #endif
} template <typename CHAR_TYPE> inline bool ___1996(CHAR_TYPE ch, std::locale const& ___2314 = std::locale::classic()) {
 #if defined ___3894
REQUIRE(___2314 == std::locale::classic()); return ::___1996(static_cast<int>(ch));
 #else
REQUIRE(std::has_facet<std::ctype<wchar_t>>(___2314)); return std::use_facet<std::ctype<wchar_t>>(___2314).is(std::ctype_base::alnum, static_cast<wchar_t>(ch));
 #endif
} template <typename CHAR_TYPE> inline bool ___2023(CHAR_TYPE ch, std::locale const& ___2314 = std::locale::classic()) {
 #if defined ___3894
REQUIRE(___2314 == std::locale::classic()); return ::___2023(static_cast<int>(ch));
 #else
REQUIRE(std::has_facet<std::ctype<wchar_t>>(___2314)); return std::use_facet<std::ctype<wchar_t>>(___2314).is(std::ctype_base::graph, static_cast<wchar_t>(ch));
 #endif
} template <typename CHAR_TYPE> inline CHAR_TYPE toupper(CHAR_TYPE ch, std::locale const& ___2314 = std::locale::classic()) {
 #if defined ___3894
REQUIRE(___2314 == std::locale::classic()); return static_cast<CHAR_TYPE>(::toupper(static_cast<int>(ch)));
 #else
REQUIRE(std::has_facet<std::ctype<wchar_t>>(___2314)); return static_cast<CHAR_TYPE>(std::use_facet<std::ctype<wchar_t>>(___2314).toupper(static_cast<wchar_t>(ch)));
 #endif
} template <typename CHAR_TYPE> inline CHAR_TYPE tolower(CHAR_TYPE ch, std::locale const& ___2314 = std::locale::classic()) {
 #if defined ___3894
REQUIRE(___2314 == std::locale::classic()); return static_cast<CHAR_TYPE>(::tolower(static_cast<int>(ch)));
 #else
REQUIRE(std::has_facet<std::ctype<wchar_t>>(___2314)); return static_cast<CHAR_TYPE>(std::use_facet<std::ctype<wchar_t>>(___2314).tolower(static_cast<wchar_t>(ch)));
 #endif
} }
 #endif

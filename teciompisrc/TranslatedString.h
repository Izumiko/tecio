 #ifndef TECPLOT_STRUTIL_TRANSLATEDSTRING
 #define TECPLOT_STRUTIL_TRANSLATEDSTRING
#include "ThirdPartyHeadersBegin.h"
#include <string>
#include "ThirdPartyHeadersEnd.h"
 #if defined MSWIN
 #pragma warning(disable : 4181)
 #endif
namespace tecplot { class ___4219 { public: typedef enum { ___1096, ___1102 } ___2506; ___4219(); static ___4219 ___2766(); static ___4219 ___4218(char const* str, char const* ___4220 = NULL); static ___4219 ___1095(char const* str); virtual ~___4219(); virtual bool ___2034() const; virtual bool ___2035() const; virtual char const* c_str() const;
 #if defined MSWIN && !defined MAKEARCHIVE
virtual wchar_t const* ___796() const;
 #endif
virtual operator std::string();
 #if defined MSWIN && !defined MAKEARCHIVE
virtual operator std::wstring();
 #endif
virtual ___4219& operator=(___4219 const& ___2889); ___4219(___4219 const& ___2889);
 #if !defined NO_ASSERTS
virtual bool ___2066() const;
 #endif 
private: ___4219(___4219::___2506 ___2505, char const* str, char const* ___4220); void ___1931(___4219::___2506 ___2505, char const* str, char const* ___4220); ___4219::___2506 ___2494; bool                   ___2488; std::string            ___2624; mutable std::string*   ___2667;
 #if defined MSWIN
mutable std::wstring* ___2676;
 #endif
}; inline ___4219 ___4218(char const* str, char const* ___4220 = NULL) { return ___4219::___4218(str, ___4220); } inline ___4219 ___1095(char const* str) { return ___4219::___1095(str); } inline ___4219 ___1095(std::string const& str) { return ___4219::___1095(str.c_str()); } }
 #endif

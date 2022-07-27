#if defined(_MSC_VER)
#define NOMINMAX // Prevent windows.h from defining min and max macros.
#include <Windows.h>
#endif

#include <cstdint>
#include <PrivateHeaders/JavaScriptCore/JSExportMacros.h>

#include <PrivateHeaders/JavaScriptCore/APICast.h>
#include <PrivateHeaders/JavaScriptCore/ConsoleClient.h>
#include <PrivateHeaders/JavaScriptCore/JSCJSValue.h>
#include <PrivateHeaders/JavaScriptCore/JSGlobalObject.h>
#include <PrivateHeaders/JavaScriptCore/ScriptArguments.h>
#include <PrivateHeaders/JavaScriptCore/ScriptValue.h>
#include <wtf/text/StringImpl.h>
#include <wtf/Vector.h>

typedef struct WTFStringImpl WTFStringImpl;

struct WTFString
{
  WTFStringImpl *inner;
  bool is_utf8;
  const unsigned char *characters8;
  const char16_t *characters16;
  uint32_t length;
};

extern "C"
{
  WTFString jsc_value_to_string_for_console(JSContextRef ctx, JSValueRef value);
  void jsc_wtf_string_release(WTFStringImpl *inner);
}

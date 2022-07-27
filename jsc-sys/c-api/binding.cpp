#include "binding.hpp"

extern "C"
{
  WTFString jsc_value_to_string_for_console(JSContextRef ctx, JSValueRef value)
  {
    auto js_value = toJS(value);
    auto js_global = toJS(ctx);
    auto console_client = js_global->consoleClient();
    auto wtf_string = Inspector::toInspectorValue(js_global, js_value)->toJSONString();
    auto impl = wtf_string.releaseImpl().leakRef();
    auto is_utf8 = wtf_string.is8Bit();
    auto characters8 = is_utf8 ? impl->characters8() : nullptr;
    auto characters16 = is_utf8 ? nullptr : impl->characters16();
    auto length = impl->length();
    auto inner = reinterpret_cast<WTFStringImpl *>(impl);
    WTFString result = {
        inner,
        is_utf8,
        characters8,
        characters16,
        length,
    };
    return result;
  }

  void jsc_wtf_string_release(WTFStringImpl *inner)
  {
    WTF::StringImpl::destroy(reinterpret_cast<WTF::StringImpl *>(inner));
  }
}

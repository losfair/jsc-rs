use std::slice;

use jsc::sys::{
  jsc_value_to_string_for_console, JSContextRef, JSObjectRef, JSValueMakeUndefined, JSValueRef,
};

pub unsafe extern "C" fn console_log(
  ctx: JSContextRef,
  _function: JSObjectRef,
  _this: JSObjectRef,
  argument_count: usize,
  arguments: *const JSValueRef,
  _exception: *mut JSValueRef,
) -> JSValueRef {
  let args = slice::from_raw_parts(arguments, argument_count);
  args.iter().for_each(|arg| {
    let wtf_string = jsc_value_to_string_for_console(ctx, *arg);
    println!("{wtf_string}");
  });
  JSValueMakeUndefined(ctx)
}

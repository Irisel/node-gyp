// add.cc
#include <node.h>

namespace demo {

using v8::Exception;
using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Number;
using v8::Object;
using v8::String;
using v8::Value;

// 这是 "add" 方法的实现。
// 输入参数使用 const FunctionCallbackInfo<Value>& args 结构传入。
void Add(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

  // 检查传入的参数的个数。
  if (args.Length() < 2) {
    // 抛出一个错误并传回到 JavaScript。
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate,
                            "参数的数量错误").ToLocalChecked()));
    return;
  }

  // 检查参数的类型。
  if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate,
                            "参数错误").ToLocalChecked()));
    return;
  }

  // 执行操作
  double value =
      args[0].As<Number>()->Value() + args[1].As<Number>()->Value();
  Local<Number> num = Number::New(isolate, value);

  // 设置返回值 (使用传入的 FunctionCallbackInfo<Value>&)。
  args.GetReturnValue().Set(num);
}

}  // namespace demo
// addon.cc
#include <node.h>
#include "myobject.h"
#include "add.h"

namespace demo {

using v8::Exception;
using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Number;
using v8::Object;
using v8::String;
using v8::Value;

void CreateObject(const FunctionCallbackInfo<Value>& args) {
  MyObject::NewInstance(args);
}

void InitAll(Local<Object> exports, Local<Object> module) {
  MyObject::Init(exports->GetIsolate());

  //NODE_SET_METHOD(module, "exports", CreateObject);
  NODE_SET_METHOD(exports, "CreateObject", CreateObject);
  NODE_SET_METHOD(exports, "Add", Add);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, InitAll)

}  // namespace demo
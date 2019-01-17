//-- constructor RF24(_cepin, _cspin)
#pragma XOD require "https://github.com/nRF24/RF24"

// Include C++ library:
{{#global}}
#include <RF24.h>
{{/global}}

// Our namespace should be: rf24_ll__rf24
// Reserve the space for the object.
struct State {
  uint8_t mem[sizeof(RF24)];
  };
using Type = RF24*; // 'Type' is assumed by xod code-generator

{{ GENERATED_CODE }}

void evaluate(Context ctx) {

  if (isSettingUp()){ // FIXME: relax this?
  auto state = getState(ctx);
 // var names are valid c++ because we got them from the arglist of the c++ constructor
  auto _cepin = (int)getValue<input__cepin>(ctx); // int
  auto _cspin = (int)getValue<input__cspin>(ctx); // int
  Type object = new (state->mem) RF24( _cepin, _cspin );
  emitValue<output_rf24>(ctx, object);
      return;}

  if (isInputDirty<input_trigger>(ctx)) {
    auto state = getState(ctx);
    auto object = reinterpret_cast<RF24*>(state->mem);
      object->begin();
      emitValue<output_done>(ctx, 1);
  }
}

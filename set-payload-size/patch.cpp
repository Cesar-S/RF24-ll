//-- void RF24::setPayloadSize(size)
// Our constructor namespace should be: rf24_ll__rf24
struct State {
  // not used
  };

{{ GENERATED_CODE }}

void evaluate(Context ctx) {

  // only act on trigger, inputs not relevant for this
  if ( !isInputDirty<input_trigger>(ctx) ) return;

  // var names are valid c++ because we got them from the arglist of the c++ method
  auto size = static_cast<int> (getValue<input_size>(ctx)); // int
  

  auto object  = getValue<input_rf24>(ctx); // RF24

  object->setPayloadSize( size ); // void
  
  emitValue<output_dev>(ctx, object); // for chaining

  
  emitValue<output_done>(ctx, 1); // pulse
}

//-- void RF24::maskIRQ(tx_ok, tx_fail, rx_ready)
// Our constructor namespace should be: rf24_ll__rf24
struct State {
  // not used
  };

{{ GENERATED_CODE }}

void evaluate(Context ctx) {

  // only act on trigger, inputs not relevant for this
  if ( !isInputDirty<input_trigger>(ctx) ) return;

  // var names are valid c++ because we got them from the arglist of the c++ method
  auto tx_ok = static_cast<bool> (getValue<input_tx_ok>(ctx)); // bool
  auto tx_fail = static_cast<bool> (getValue<input_tx_fail>(ctx)); // bool
  auto rx_ready = static_cast<bool> (getValue<input_rx_ready>(ctx)); // bool
  

  auto object  = getValue<input_rf24>(ctx); // RF24

  object->maskIRQ( tx_ok, tx_fail, rx_ready ); // void
  
  emitValue<output_dev>(ctx, object); // for chaining

  
  emitValue<output_done>(ctx, 1); // pulse
}

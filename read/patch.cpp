
struct State {
};

{{ GENERATED_CODE }}


void evaluate(Context ctx) {

    // only act on trigger, other inputs not relevant for "dirty" for impure operations
    if ( isInputDirty<input_trigger>(ctx) ) return;

    auto _object = getValue<input_rf24>(ctx); // to "always emit", need it always

    // `auto` should work to get the struct (doesn't matter what the library is actually called)
    auto buffer1 = getValue<input_buffer1>(ctx);

    // Do nothing on bad buffer
    if ( ! buffer1 || ! buffer1->buffer ) {
        DEBUG_SERIAL.print(F("rf24-ll/read")); DEBUG_SERIAL.print(F("saw unallocated buffer1\n"));
        // Emit nothing else
        // Could emit ERR, but then multiple cases cause ERR
        // But do fall through to emit the object
    }

    else {

        auto count = getValue<input_count>(ctx);;  // used as uint8_t
        size_t buffer_length = buffer1->len;

        if (count < 0 || count > buffer_length) {
            emitValue<output_ERR>(ctx, 1);
        }

        else {
            char* byte_buffer = (char*) (buffer1->buffer);

            _object->read(byte_buffer, count); // void(void*, uint8_t)

            emitValue<output_done>(ctx, 1); // did it
        }
    }

    // always
    emitValue<output_dev>(ctx, _object); // convenience
}

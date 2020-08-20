#include "simpleserial.h"

nBlock_SimpleSerial::nBlock_SimpleSerial(PinName pinTX, PinName pinRX): _ser(pinTX, pinRX) {
    return;
}
void nBlock_SimpleSerial::triggerInput(nBlocks_Message message) { // inputNumber is ignored
    _ser.putc(message.intValue);
}
void nBlock_SimpleSerial::endFrame(void) {
    if (_ser.readable()) {
        output[0] = _ser.getc();
        available[0] = 1;
    }
    return;
}


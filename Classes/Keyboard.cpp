#include "Keyboard.h"

USING_NS_CC;

Keyboard::Keyboard() {
    
}

Keyboard::~Keyboard() {
    
}

void Keyboard::onKeyUp(EventKeyboard::KeyCode keyCode, Event* event) {
        log("Key with keycode %d pressed", keyCode);
}

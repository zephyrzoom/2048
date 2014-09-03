/* 
 * File:   Keyboard.h
 * Author: zephyr
 *
 * Created on August 17, 2014, 1:05 AM
 */

#ifndef KEYBOARD_H
#define	KEYBOARD_H

class Keyboard {
public:
    Keyboard();
    ~Keyboard();
    void onKeyUp(EventKeyboard::KeyCode keyCode, Event* event);
};

#endif	/* KEYBOARD_H */


#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "types.h"

void keyboard_init(void);
char keyboard_read_char(void);
int keyboard_has_input(void);

#endif

#ifndef __DS4_H__
#define __DS4_H__

#include <stdio.h>
#include <stdlib.h>


typedef struct ds4_t DS4;
typedef struct button_t BUTTON;
typedef struct joystick_t JOYSTICK;
typedef struct trigger_t TRIGGER;

DS4 *init_DS4();
int get_ds4_key(DS4 *);
void print_ds4_debug_key(DS4 *);
#endif

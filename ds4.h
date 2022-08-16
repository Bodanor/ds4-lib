#ifndef __DS4_H__
#define __DS4_H__

#include <stdio.h>
#include <stdlib.h>

#include "ansi-colors-code.h"

#define CROSS_PRESSED 0
#define CROSS_RELEASED 1
#define CIRCLE_PRESSED 2
#define CIRCLE_RELEASED 3
#define TRIANGLE_PRESSED 4
#define TRIANGLE_RELEASED 5
#define SQUARE_PRESSED 6
#define SQUARE_RELEASED 7
#define L1_PRESSED 8
#define L1_RELEASED 9
#define R1_PRESSED 10
#define R1_RELEASED 11
#define LEFT_ARROW__PRESSED 12
#define LEFT_ARROW_RELEASED 13
#define UP_ARROW__PRESSED 14
#define UP_ARROW_RELEASED 15
#define RIGHT_ARROW__PRESSED 16
#define RIGHT_ARROW_RELEASED 17
#define DOWN_ARROW__PRESSED 18
#define DOWN_ARROW_RELEASED 19
#define SHARE_PRESSED 20
#define SHARE_RELEASED 21
#define OPTION_PRESSED 22
#define OPTION_RELEASED 23
#define PS_PRESSED 24
#define PS_RELEASED 25
#define L3_PRESSED 26
#define L3_RELEASED 27
#define R3_PRESSED 28
#define R3_RELEASED 29
#define LEFT_JOYSTICK 30
#define RIGHT_JOYSTICK 31

typedef struct ds4_t DS4;
typedef struct button_t BUTTON;
typedef struct joystick_t JOYSTICK;
typedef struct trigger_t TRIGGER;

DS4 *init_DS4();
int get_ds4_key(DS4 *);
void print_ds4_debug_all_keys(DS4 *);
void print_updated_key(int key);
#endif

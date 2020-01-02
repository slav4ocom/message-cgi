#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include "parser.h"

#define rxbuflen 128 // dyljina na bufera

FILE *html_file;
FILE *forum_file;
char Rxbuf[rxbuflen + 1];
int i;
int bytes_cnt;
//static unsigned int Rxind = 0;
char cmd_param_string[24];
//unsigned char cmd_param_cnt = 0; // broqcha na zwezdichkite w komandata
//bool console_active = true;
bool console_active;

#endif // MAIN_H_INCLUDED

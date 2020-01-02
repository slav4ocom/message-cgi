#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include <stdbool.h>

#define number_of_commands 4

static const char * cmdtable[32] = {"\0",
                        "<beep>",                // 1
                        "<?test?>",         // 2
                        "<start>",        // 3
                        "<stop>",   // 4
                        "1,CLOSED\r\n",         // 5
                        "1,CONNECT\r\n",        // 6
                        "1,CONNECT FAIL\r\n",   // 7
                        "2,CLOSED\r\n",         // 8
                        "2,CONNECT\r\n",        // 9
                        "2,CONNECT FAIL\r\n",   // 10
                        "3,CLOSED\r\n",         // 11
                        "3,CONNECT\r\n",        // 12
                        "3,CONNECT FAIL\r\n",   // 13
                        "4,CLOSED\r\n",         // 14
                        "4,CONNECT\r\n",        // 15
                        "4,CONNECT FAIL\r\n",   // 16
                        ">",                    // 17
                        "busy s...\r\n",        // 18
                        "Cookie: token=",       // 19
                        "GET",                  // 20
                        "OK\r\n",               // 21
                        "WIFI DISCONNECT\r\n",  // 22
                        "WIFI GOT IP\r\n",      // 23
                        "SEND OK\r\n",          // 24
                        "SEND FAIL\r\n",        // 25
                        "+IPD,*,****",          // 26
                        "03402432094",          // 27
                        "postdata=",            // 28
                        "pass=",                // 29
                        "hgdgg",                // 30
                        "POST"                  // 31
                    };

static unsigned char min = 1;
static unsigned char max = number_of_commands;
static unsigned char cmd_cnt = 0;
static unsigned char command = 0;
//unsigned int parseind = 0;

void Parse(char ** table, char parse_char);
void DecodeATCommand(void);


#endif // PARSER_H_INCLUDED

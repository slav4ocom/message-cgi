#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "main.h"

void Parse(char ** table , char parse_char)
{
    unsigned char c;
    bool found = false;


    for (c = min; c <= max; c++) {
        if (table[c][cmd_cnt] == parse_char) {
            if (!found)
                min = c;
            found = true;
        } else {
            if (found)
                max = c - 1;
        }

    }


    if (found) { // ako ima otkrit simwol
        cmd_cnt++;
    } else { // ako nqma simwol
        cmd_cnt = 0;
        min = 1;
        max = number_of_commands;
    }

    if (min == max) { // otsqta e samo edna komanda
        if (table[min][cmd_cnt] == '\0') { // prowerka dali sme prowerili wsicki simwolii
            cmd_cnt = 0; // nulirame indeksa na stringa
            command = min; // zadawame nomer na komandata
            min = 1; // wyzstanowqwame interwala
            max = number_of_commands; // na wyzmojnite komandi
            //cmd_param_string[cmd_param_cnt] = '\0'; // terminirame stringa s parametrite na komandite
            //ipd_len.word = StrToInt(&cmd_param_string[1]);
        }

    }


    if(command){
        //printf("\a");
        //console_active = false;
        DecodeATCommand();
    }

    //console_active = false;

}


void DecodeATCommand(void)
{
    switch (command){

        case 0:
            break;

        case 1: // <beep>
            //printf("\a");
            break;

        case 2:
            printf("vlojka");
            break;

        case 3: //  <start>
            //printf("\a");
            console_active = false;
            break;

        case 4: //  <stop>
            //printf("\a");
            console_active = true;
            break;

        default:
            //Beep();
            break;
    }
    command = 0;

}


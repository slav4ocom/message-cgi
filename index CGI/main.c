#include "main.h"
#include "parser.h"

#define buflen 128 // dyljina na bufera


int ReadFile(FILE *in_file, char * out_buffer, char end_char)
{
    char data;

    //*out_buffer = '-';
    //out_buffer++;

    for(i = 0 ;i < buflen; i++){

        data = getc(in_file);
        if(!console_active){
            *out_buffer = '*';
            //*out_buffer = data;
        }
        else{
            *out_buffer = data;
        }
        Parse(cmdtable,data);
        if(data == end_char){
            //out_buffer--;
            break;
        }
        //if(console_active)
        out_buffer++;

    }
    return i;
}

int main()
{
    console_active = true;

    html_file = fopen("c:/xampp/htdocs/index.txt","r");
    while(1){
        bytes_cnt = ReadFile(html_file,Rxbuf,'$');
        Rxbuf[bytes_cnt] = '\0';
        printf(Rxbuf);
        if(bytes_cnt != buflen)
            break;

    }

    forum_file = fopen("c:/xampp/htdocs/forum.txt","r");
    while(1){
        bytes_cnt = ReadFile(forum_file,Rxbuf,EOF);
        Rxbuf[bytes_cnt] = '\0';
        printf(Rxbuf);
        if(bytes_cnt != buflen)
            break;
    }

    fclose(forum_file);

    while(1){
        bytes_cnt = ReadFile(html_file,Rxbuf,EOF);
        Rxbuf[bytes_cnt] = '\0';
        printf(Rxbuf);
        if(bytes_cnt != buflen)
            break;
    }
    fclose(html_file);
    //printf("\a");
    return 0;
}

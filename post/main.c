#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *ofp;
char filename[] = "c:/xampp/htdocs/forum.txt"; // forum file that collects and contains message data
char str[750];
char cyr_str[250];
char file_buf[250];
unsigned int i;
unsigned int c;
unsigned char cnt;
fpos_t pos = 0;
char buffer[20];



char Decode1251(char high, char low)
{
    unsigned char data = 0x00;

    switch(high){
        case '0':
            data = 0x00;
            break;
        case '1':
            data = 0x10;
            break;
        case '2':
            data = 0x20;
            break;
        case '3':
            data = 0x30;
            break;
        case '4':
            data = 0x40;
            break;
        case '5':
            data = 0x50;
            break;
        case '6':
            data = 0x60;
            break;
        case '7':
            data = 0x70;
            break;
        case '8':
            data = 0x80;
            break;
        case '9':
            data = 0x90;
            break;
        case 'A':
            data = 0xA0;
            break;
        case 'B':
            data = 0xB0;
            break;
        case 'C':
            data = 0xC0;
            break;
        case 'D':
            data = 0xD0;
            break;
        case 'E':
            data = 0xE0;
            break;
        case 'F':
            data = 0xF0;
            break;
        default:
            data = 0xF0;
            break;
    }

    switch(low){
        case '0':
            data = data + 0x00;
            break;
        case '1':
            data = data + 0x01;
            break;
        case '2':
            data = data + 0x02;
            break;
        case '3':
            data = data + 0x03;
            break;
        case '4':
            data = data + 0x04;
            break;
        case '5':
            data = data + 0x05;
            break;
        case '6':
            data = data + 0x06;
            break;
        case '7':
            data = data + 0x07;
            break;
        case '8':
            data = data + 0x08;
            break;
        case '9':
            data = data + 0x09;
            break;
        case 'A':
            data = data + 0x0A;
            break;
        case 'B':
            data = data + 0x0B;
            break;
        case 'C':
            data = data + 0x0C;
            break;
        case 'D':
            data = data + 0x0D;
            break;
        case 'E':
            data = data + 0x0E;
            break;
        case 'F':
            data = data + 0x0F;
            break;
        default:
            data = data + 0x0F;
            break;
    }

    if(data == 0xFF)
        data = 0xDF;
    return data;
}

void Translate(void)
{
    c = 0;

    for(i=0; str[i]!= '\0' ; i++){

        if(str[i] == '%'){
            cyr_str[c] = Decode1251(str[i + 1], str[i + 2]);
            i++;
            i++;
        }
        else{
            cyr_str[c] = str[i];
        }
        c++;
    }
    cyr_str[c] = '\0';

}

void DecodePost(void)
{
    i = 0;
    c = 0;

    while(cyr_str[i] != '&'){ // find "&"
        i++;
    }
    i++;

    if(memcmp(&cyr_str[i],"name",sizeof("name")-1) == 0){

        i = i + sizeof("name");
        while(cyr_str[i] != '\0'){
            if(cyr_str[i] == '\n')
                file_buf[c] = ' ';
            else if(cyr_str[i] == '+')
                file_buf[c] = ' ';
            else
                file_buf[c] = cyr_str[i];
            i++;
            c++;
        }
    }

    file_buf[c] = ':';
    c++;
    for(cnt=0;cnt<5;cnt++){
        file_buf[c] = ' ';
        c++;
    }
    i = 0;


    if(memcmp(&cyr_str[i],"comment",sizeof("comment")-1) == 0){

        while(c < 20){
            file_buf[c] = ' ';
            c++;
        }

        i = i + sizeof("comment");
        while(cyr_str[i] != '&'){
            if(cyr_str[i] == '\n')
                file_buf[c] = ' ';
            else if(cyr_str[i] == '+')
                file_buf[c] = ' ';
            else
                file_buf[c] = cyr_str[i];
                i++;
                c++;
        }
    }

    file_buf[c] = '\0';

}


int main(int argc, char *argv[])
{
    i = 0;
    do{
        str[i] = getchar();
        i++;
        if(i == 630)
            break;
    }while(str[i-1] != 'я' && str[i-1] != '\n');
    str[i-1] = '\0';

    Translate();
    DecodePost();

    ofp = fopen(filename,"a");


    if (ofp == NULL){
        fprintf(stderr, "Can't open output file %s!\n",
                filename);
        exit(1);
    }
    else{
        fprintf(ofp,file_buf);

        fprintf(ofp,"\n");
        fclose(ofp);
    }

    printf("Content-type: text/html;\n\n");
    printf(""
           "<html>"
           "<meta http-equiv='refresh' content='5; URL=/'>"
           "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=windows-1251\" /> "
           "<title>CGI test page</title>"
           "<body>"
           "<center><font face=\"Arial\" size=\"5\">"
           "CGI test web page </center>"
           "<font size=\"4\" color=\"blue\">"

          );


    printf("<br>");
    printf(cyr_str);
    printf(""
           "<form action=\"/\">"
           "<center><input type=\"submit\" value=\"начало\">"
           "</form>"
           "</body></html>"
           "");

    return 0;
}

#include<stdlib.h>
#include<stdio.h>
#define MAX_LINE_LENGTH 250

static FILE* infile = NULL;
static FILE* outfile = NULL;

char sbuf[MAX_LINE_LENGTH+1];
char* ch;

void handle_c_comment(void) {
    while(1) {
        if(*ch == '\0'){
            if(fgets(sbuf, MAX_LINE_LENGTH, infile) == NULL){
                fprintf(stderr, "Error: Probably syntax error becase reach EOF before the end of comment\n");
                exit(1);
            }
            ch = sbuf;
        }
        while(*ch != '/' && *ch != '\0'){
            fputc(*ch, outfile);
            ++ch;
        }
        if(*ch == '\0') continue;
        else{
            fputc('/',outfile);
            if(*(ch-1) == '*'){
                ++ch;
                break;
            }else{
                ++ch;
            }
        }
    }
}


void handle_cpp_comment(void) {
    fputc('*',outfile);
    ++ch;
    while(1){
        if( *ch == '\0'){
            if(fgets(sbuf, MAX_LINE_LENGTH, infile) == NULL){
                fputs("*/",outfile);
                exit(0);
            }else {
                ch = sbuf;
            }
        }
        while(*ch != '\n' && *ch != '\0' && *ch != '/'){
            fputc(*ch,outfile);
            ++ch;
        }
        if(*ch == '\n'){
            fputs("*/\n",outfile);
            ++ch;
            break;
        }else if (*ch == '/'){
            if(*(ch-1) == '*' ){
                fputs(" /",outfile);
            }else{
                fputc('/', outfile);
            }
            ++ch;
        }
    }
}

void handle_string(void) {
    fputc('\"', outfile);
    ++ch;
    while(1){
        if(*ch == '\0'){
            if(fgets(sbuf, MAX_LINE_LENGTH, infile) == NULL) {
                fprintf(stderr, "Error: Probably syntax error becase reach EOF before the end of string\n");
                exit(2);
            }
            ch = sbuf;
        }
        while(*ch != '\"' && *ch != '\0') {
                fputc(*ch, outfile);
                ++ch;
        }
        if(*ch == '\0') continue;
        else if(*ch == '\"') {
            fputc('\"', outfile);
            ++ch;
            break;
        }
    }
}


void close_opened_files(void )
{
    fclose(outfile);
    fclose(infile);
}

int main(int argc, char * argv[])
{
    if(argc != 3){
        fprintf(stderr, "Usage: %s <in_file> <out_file>\n",argv[0] );
        exit(3);
    }

    infile  = fopen(argv[1], "r");
    outfile = fopen(argv[2] ,"w");
    atexit(&close_opened_files);    //进程结束时调用的函数

    while(fgets(sbuf,MAX_LINE_LENGTH,infile)){
        ch = sbuf;
        while(*ch != '\0') {
            switch(*ch){
                case '/':
                    fputc(*ch, outfile);
                    ++ch;
                    if(*ch == '*') {
                        handle_c_comment();
                    } else if (*ch == '/'){
                        handle_cpp_comment();
                    } else {
                        fputc(*ch,outfile);
                        ++ch;
                    }
                    break;
                case '\"':
                    handle_string();
                    break;
                default:
                    fputc(*ch,outfile);
                    ++ch;
                    break;
            }
        }
    }
    exit(0);
}



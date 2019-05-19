#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>//输出文件信息


#define MAX_LINE_LENGTH 250
FILE* infile = NULL;
FILE* outfile = NULL;
char sbuf[MAX_LINE_LENGTH+1];
char* ch;


/****************文件处理****************/

void handle_c_comment(void) {
    while(1) {
        if(*ch == '\0'){
            if(fgets(sbuf, MAX_LINE_LENGTH, infile) == NULL){
                fprintf(stderr, "该文件的注释可能有问题，没有配对的 /* */\n");
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
    fputc('*',outfile);     //前面可不用加空格
    //fputs("* ",outfile);    //加个空格
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
            fputs(" */\n",outfile); //加个空格
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

void process_file(char *file_source_path, char *file_destination_path){
    infile  = fopen(file_source_path, "r");
    outfile = fopen(file_destination_path, "w");
    while(fgets(sbuf,MAX_LINE_LENGTH,infile)){
        ch = sbuf;
        while(*ch != '\0') {
            switch(*ch){
                case '/':
                    fputc(*ch, outfile);
                    ++ch;
                    if(*ch == '*') {
                        handle_c_comment(); // 跳过 /* */中的//
                    } else if (*ch == '/'){
                        // 打印要处理的行
                        //puts(sbuf);
                        printf("%s", sbuf);
                        handle_cpp_comment();
                    } else {
                        fputc(*ch,outfile);
                        ++ch;
                    }
                    break;
                case '\"':
                    handle_string();    //跳过 "" 中的//
                    break;
                default:
                    fputc(*ch,outfile);
                    ++ch;
                    break;
            }
        }
    }
    return;
}


/*****************目录处理******************/


char* str_contact(char* str1,char* str2){//字符串连接
	char* result;
	result=(char*)malloc(strlen(str1)+strlen(str2)+1);//str1的长度+str2的长度+\0;
	if(!result){//如果内存动态分配失败
		printf("malloc error\n");
		exit(1);
	}
	strcat(result,str1);
	strcat(result,str2);//字符串拼接
	return result;
}

int is_dir(char* path){//判断是否是目录
	struct stat st;
	stat(path,&st);
	if(S_ISDIR(st.st_mode)){
		return 1;
	}
	else{
		return 0;
	}
}

/*字符串处理函数*/
int endwith(char* s,char c){//用于判断字符串结尾是否为“/”
	if(s[strlen(s)-1]==c){
		return 1;
	}
	else{
		return 0;
	}
}

/*复制函数*/
void copy_file(char* source_path,char *destination_path){//复制文件
	char buffer[1024];
	FILE *in,*out;//定义两个文件流，分别用于文件的读取和写入int len;
	if((in=fopen(source_path,"r"))==NULL){//打开源文件的文件流
		printf("fopen source_path error\n");
		exit(1);
	}
	if((out=fopen(destination_path,"w"))==NULL){//打开目标文件的文件流
		printf("fopen destination_path error\n");
		exit(1);
	}
	int len;//len为fread读到的字节长
	while((len=fread(buffer,1,1024,in))>0){//从源文件中读取数据并放到缓冲区中，第二个参数1也可以写成sizeof(char)
		fwrite(buffer,1,len,out);//将缓冲区的数据写到目标文件中
	}
	fclose(out);
	fclose(in);
}

void process_dir(char *source_path, char *destination_path){
    struct dirent* filename;
    DIR* dp=opendir(source_path);//用DIR指针指向这个文件夹

    // 创建目标文件夹
    if(!opendir(destination_path)){
        if(mkdir(destination_path, 0777) == -1){
            perror("mkdir");
            return;
        }
    }
    while(filename=readdir(dp)){//遍历DIR指针指向的文件夹，也就是文件数组。
        char *file_source_path, *file_destination_path;
        file_source_path = (char*)malloc(512);
        file_destination_path = (char*)malloc(512);
        //取文件名与当前文件夹拼接成一个完整的路径
        file_source_path=str_contact(file_source_path,source_path);
        file_source_path=str_contact(source_path,"/");
        file_source_path=str_contact(file_source_path,filename->d_name);
        file_destination_path=str_contact(file_destination_path,destination_path);
        file_destination_path=str_contact(destination_path,"/");
        file_destination_path=str_contact(file_destination_path,filename->d_name);

        if(is_dir(file_source_path)){ //如果是目录
            if(endwith(file_source_path,'.')){//同时并不以.结尾，因为Linux在所有文件夹都有一个.文件夹用于连接上一级目录，必须剔除，否则进行递归的话，后果无法相像
                continue;
            }
            process_dir(file_source_path,file_destination_path);//进行递归调用，相当于进入这个文件夹进行复制～
        }
        else{
            process_file(file_source_path,file_destination_path);//否则按照单一文件的复制方法进行复制。
        }
    }
}

int main(int argc, char * argv[])
{
    if(argc != 3){
        fprintf(stderr, "Usage: %s <in_dir> <out_dir>\n",argv[0] );
        exit(3);
    }

    char *source_path = argv[1];        //源路径
    char* destination_path=argv[2];     //目标路径

    DIR* source=opendir(source_path);
    DIR* destination=opendir(destination_path);
    if(!source){
        printf("source is not a directory\n");
        return -1;
    }

    if(destination){
        printf("destination already exists\n");
        return -1;
    }

    process_dir(source_path, destination_path);

    return 0;
}


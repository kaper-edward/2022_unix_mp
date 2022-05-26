#include "../include/textfilewriter.h"
#include <stdlib.h>
#include <string.h>

void create_music_titles(FILE* stream){
    //플레이 리스트를 생성합니다.(표준 입출력이나 파일 IO(파일 입출력)로 부터
}

void read_file(char* file_name){
    FILE *fp;
    char buffer[MAX_TITLE_SIZE + 1];
 
    if ((fp = fopen(file_name, "r+")) != NULL) {
        memset(buffer, 0, sizeof(buffer));
        while (fread(buffer, 1, MAX_TITLE_SIZE, fp) != 0)
            printf("%s\n", buffer);
        fclose(fp);
    }
}

void write_file(char* file_name){
    FILE* fp;
    char buffer[MAX_TITLE_SIZE+1];

    if( (fp=fopen(file_name, "a")) != NULL){
        memset(buffer,0,sizeof(buffer));        //0으로 초기화 시킨후 입력 : 문자열 마지막 0때문에
        scanf("%s" , buffer);

        fwrite(buffer,1,strlen(buffer),fp);
        fclose(fp);
    }
}
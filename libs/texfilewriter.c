#include "../include/textfilewriter.h"
#include <stdlib.h>
#include "linkedlist.c"

void create_music_titles(FILE* stream){
    //플레이 리스트를 생성합니다.(표준 입출력이나 파일 IO(파일 입출력)로 부터
    //이거 대신 read_file을 씀.
}

void read_file(char* file_name){
    Node* it = _cur_node;   //현재 노드를 기준으로 왼쪽에 입력
    FILE* fp;
    char buffer[MAX_TITLE_SIZE+1];

    if ((fp=fopen(file_name,"r")) != NULL){
        while (fgets(buffer,MAX_TITLE_SIZE,fp ) != 0){
            //append_left(글자수,버퍼);
            it = append_left(MAX_TITLE_SIZE,buffer);
        }
        fclose(fp);
    }
}

void write_file(char* file_name){
    Node* it = _head;       //재생순서 : head부터 tail까지
    FILE* fp;
    //char buffer[MAX_TITLE_SIZE+1];

    if( (fp=fopen(file_name, "a")) != NULL){    //혹시 모르니까 덧붙이기로
        //memset(buffer,0,sizeof(buffer));        //0으로 초기화 시킨후 입력 : 문자열 마지막 0때문에
        while(it == NULL){
            char* buffer = (char*)malloc(sizeof(char*)*(MAX_TITLE_SIZE+1));
            char c[2] = "\n";
            buffer = strcat(it->data,c);
            fputs(it->data,fp);
            it = it->next;
        }
    }
}
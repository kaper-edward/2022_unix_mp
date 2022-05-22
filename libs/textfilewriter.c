#include "../include/textfilewriter.h"
#include <stdlib.h>
#include <string.h>

void create_music_titles(FILE* stream){

}

void read_file(char* file_name){
    FILE *fp;
    char buffer[MAX_TITLE_SIZE + 1];
 
    if ((fp = fopen(file_name, "r+")) != NULL) {
        memset(buffer, 0, sizeof(buffer));              // 문자열 마지막 null위해 0채우기
        while (fread(buffer, 1, MAX_TITLE_SIZE, fp) != 0)
            printf("%s\n", buffer);
        fclose(fp);
    }
}

void write_file(char* file_name){
    FILE *fp;
    char buffer[MAX_TITLE_SIZE + 1];
     
    if ((fp = fopen(file_name, "a"))!=NULL) {
        memset(buffer, 0, sizeof(buffer));
        scanf("%s", buffer);
 
        fwrite(buffer, 1, strlen(buffer), fp);
        fclose(fp);
    }    
}


#include "../include/textfilewriter.h"
#include "../include/linkedlist.h"
#include <stdlib.h>

void create_music_titles(FILE* fp){
    char title[MAX_TITLE_SIZE+1];
    clear();
    while (fgets(title, MAX_TITLE_SIZE, fp) != NULL)
        append_left(MAX_TITLE_SIZE, title);
}

void read_file(char* file_name) {
    FILE* fp = fopen(file_name,"r");
    if(fp != NULL) create_music_titles(fp);
    fclose(fp);
}

void write_file(char* file_name) {
    FILE* fp = fopen(file_name, "a");

    if (fp != NULL) {
        Node* it = first();
        Node* before;
        do{
            fputs(it->data, fp);
            fputc('\n', stdout);
            before = it;
            it = next();
        }while(it != before);
    }

    fclose(fp);
}
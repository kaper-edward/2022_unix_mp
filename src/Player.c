#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/linkedlist.h"
#include "../include/textfilewriter.h"

int main() {
  //처음 곡 songNum개 연결리스트에 입력
  int song_num;
  scanf("%d", &song_num);
  
  for (int i=0; i<song_num; i++) {
    char* song_name = (char*)malloc(sizeof(char)*MAX_TITLE_SIZE);  //공간 넉넉하게 잡고
    scanf("%s",song_name);
    append_left(MAX_TITLE_SIZE,song_name);
  }
  
  //명령어 별 처리
  char command[50];						//명령어 n번 입력받기
  int n;
  scanf("%d", &n);
  

  char* file_name = "term.txt";
  int num; 
  
  Node* it;

  for (int i=0; i<n; i++) {
  	scanf("%s", command);
  	
  	if (!strcmp(command, "add")) {		//add
      char* song;
      song=(char*)malloc(sizeof(char)*MAX_TITLE_SIZE);
  		scanf("%s", song);
      append_left(sizeof(song),song);
  		printf("Added %s\n", song);
    }
    else if (!strcmp(command, "del")) { //del
      char* song;
      song=(char*)malloc(sizeof(char)*MAX_TITLE_SIZE);
      delete_by_data(song);
      printf("Deleted %s\n", song);
    }
    else if (!strcmp(command, "list")) { //list
      print();
    }
    else if (!strcmp(command,"next")) {
      printf("Next\n");
    }
    else if (!strcmp(command,"prev")) {
      printf("Prev\n");
    }
    else if (!strcmp(command,"move")) {
      scanf("%s",num);
      printf("Moved %d\n");
    }
    else if (!strcmp(command,"play")) {
      printf("Play\n");
    }
    else if (!strcmp(command,"clear")) {
      clear();
      printf("LinkedList is cleared!");
    }
    else if (!strcmp(command,"quit")) {
      clear();
      printf("LinkedList is cleared!");
      printf("quit!");
      return 0;
    }
    else if (!strcmp(command,"load")) {
      scanf("%s",file);
      printf("Created playlist\n");
    }
    else if (!strcmp(command,"save")) {
      scanf("%s",file);
      printf("Saved songs to file\n");
    }
  }
}

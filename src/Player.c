#include <stdio.h>
#include "linkedlist.h"
#include "textfilewriter.h"

int main() {
  int n;					//곡 n개 입력받기 
  scanf("%d", &n);
  char songlist[n][50];
  for (int i=0; i<n; i++) {
    scanf("%s", songlist[i]);
    
  char command[50];						//명령어 n번 입력받기
  scanf("%d", &n);
  
  char song[50];	//***동적할당 사용하여 다시 구현
  char file[1000];
  int num; 
  
  for (int i=0; i<n; i++) {
  	scanf("%s", command);
  	
  	if (!strcmp(command, "add")) {		//명령어별 처리 
  		scanf("%s", song);
  		printf("Added %s\n", song);
    }
    else if (!strcmp(command, "del")) {
      scanf("%s", song);
      printf("Deleted %s\n", song);
    }
    else if (!strcmp(command, "list")) {
      printf("List\n");
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
      printf("Clear\n");
    }
    else if (!strcmp(command,"quit")) {
      printf("Quit\n");
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

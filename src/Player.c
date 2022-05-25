#include <stdio.h>
#include "linkedlist.h"
#include "textfilewriter.h"

int main() {
  int n;					//곡 n개 입력받기 
  scanf("%d", &n);
  char songlist[n][50];
  for (int i=0; i<n; i++) {
    scanf("%s", songlist[i]);
  }
}

#include <stdio.h>
#include <string.h>

void printRLE(char str[]){

  int length = 1;
  char prevChar;

  for (int i = 1; i < strlen(str) ; i++){
    prevChar = str[i-1];
    char currChar = str[i];

    if ((prevChar != currChar) || (length == 9)){
      printf("%d%c", length, prevChar);
      length = 0;
    }

    length += 1;
  }

  //need to print the last character also 
  printf("%d%c", length, str[strlen(str)-1]);

}

int main(void) {
  
  printRLE("AAAAAAAAAABBBBBBBBBBBBCCCCDE");

  return 0;
}

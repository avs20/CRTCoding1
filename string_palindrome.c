#include <stdio.h>
#include <string.h>


void isPalindrome(char str[]){
  // 0 if not palindrome
  // 1 if palindrome

  //create reverse string
  int len = strlen(str);
  char reversed[len+1];
  for (int i = len-1, j =0 ; i >= 0 ; i--, j++){
      reversed[j] = str[i];
  }

  reversed[len] = '\0';


  //compare them
  int result = strcmp(str, reversed);
  if (result == 0){
    printf("String is PALINDROME");
  }else{
    printf("STRING IS NOT PALINDROME");
  }
}


void isPalindrome2(char str[]){

    int left = 0;
    int right = strlen(str) -1;

    while (left < right){
      if (str[left] != str[right]){
        printf("STRING IS NOT PALINDROME");
        return;
      }

      left++;
      right--;
    }

    printf("STRING IS PALINDROME");
}


int main(void) {
  isPalindrome("ABCDCBA");
  printf("\n");
  isPalindrome("Palindrome");
  printf("\n");
    isPalindrome2("Palindrome");
  printf("\n");
  isPalindrome2("ABCDCBA");


  return 0;
}

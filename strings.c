#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

  //pointer notation string initialized is not mofifiable.
  // char *ptr = "here";
  // ptr[3] = 'g';
  // printf("%s", ptr);

  // char str[] = "hello\0world";
  // char var = 'a';
  // printf("Size of char is %d \n", (int)sizeof('b'));
  // printf("size of character is %d\n", (int) sizeof(var));
  // printf("%d\n", (int)sizeof(str));
  // printf("%s", str);

  // char a = 'E';
  // printf(" char as num %d\n", a);
  // printf(" num as char %c", 97);


  char input[] = "All the best 2021";
  int key = 3;
  char result[strlen(input) + 1];

  for (int i = 0 ; i < strlen(input) ; i++){

    //extract each character from the string
    //find whether it's digit, lowercase or uppercase
    if (input[i] >=48 && input[i] <= 57){
      //this is a digit
      int nC = input[i] + key;
      if (nC > 57){
        nC = 47 + nC % 57;
      }

      result[i] = nC;

    }
    else if(input[i] >= 65 && input[i] <= 90){
      //its a uppercase letter
      int nC = input[i] + key;
      if (nC > 90){
        nC = 64 + nC % 90;
      }

      result[i] = nC;
    }
    else if(input[i] >= 97 && input[i] <= 122){
      //it's a lowercase letter
      int nC = input[i] + key;
      if (nC > 122){
        nC = 96 + nC % 122;
      }

      result[i] = nC; 
    }else{
      result[i] = input[i];
    }
    


  }

  printf("Result is : %s", result);

  

}

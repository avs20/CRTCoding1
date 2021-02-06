#include <stdio.h>



int * find2SumForLoop(int nums[], int numSize, int target, int result[]){

    for (int i = 0 ; i  < numSize ; i++){

        int firstNum = nums[i];

        for (int j = i + 1 ; j < numSize ; j++){

            int secondNum = nums[j];

            if (firstNum + secondNum == target){
              result[0] = firstNum;
              result[1] = secondNum;
              return result;
            }

        }

    }
    return result;

}


int * find2SumBest(int nums[], int numSize, int target, int result[]){

    for (int i = 0 ; i  < numSize ; i++){

        int firstNum = nums[i];

        for (int j = i + 1 ; j < numSize ; j++){

            int secondNum = nums[j];

            if (firstNum + secondNum == target){
              result[0] = firstNum;
              result[1] = secondNum;
              return result;
            }

        }

    }
    return result;

}


int main(void) {

    int nums[7] = {2, 7, 11, 15, 3, 8, 14};
    int numSize = 7;
    int target = 14;

    int result[2];

    //find the numbers using for loop 
    find2SumForLoop(nums,numSize, target, result);

    for (int i = 0 ; i < 2 ; i++){
      printf("%d \t", result[i]);
    }


}

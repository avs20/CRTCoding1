#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> find2Sum(vector<int> nums, int numSize, int target){

      //better solution

      //1. Sort the array 
      sort(nums.begin(), nums.end());

      //Take 2 pointers
      int left = 0 ; 
      int right = nums.size() - 1; 

      while ( left < right ){

        //calculate currentSum 
        int currentSum = nums[left] + nums[right];

        if (currentSum == target){
          return {nums[left], nums[right]};
        } else if (currentSum < target){
            left++;
        }else if (currentSum > target){
            right--;
        }



      }

      return {};



}


int main() {
  


    vector<int> nums = {0, 2, 7, 11, 15, 3, 8, 14};
    int numSize = 7;
    int target = 14;


    //find the numbers using for loop 
    vector<int> result = find2Sum(nums,numSize, target);

    for (int i = 0 ; i < 2 ; i++){
      printf("%d \t", result[i]);
    }

}

#include <iostream>
#include <vector>
using namespace std;


// Time : O(N3) | Space O(N)
// //check palindrom e | O(N)
// bool isPalindrome(string str){
//   int leftIdx = 0;
//   int rightIdx = str.length()-1;

//   while(leftIdx < rightIdx){
//     if (str[leftIdx] != str[rightIdx]){
//       return false;
//     }
//     leftIdx++;
//     rightIdx--;
//   }

//   return true;
// }

// //find all the substrings and check if they are palindrome or not 
// string longestPalindromeSubstring(string str){
//   string longest ="";

//   for (int i = 0 ; i < str.length() ;  i++ ){
//     for (int j = i ; j < str.length() ; j++){
//       string substring = str.substr(i, j + 1 - i);
//       if(substring.length() > longest.length() && isPalindrome(substring) ){
//         longest = substring;
//       }
//     }
//   }

//   return longest;
// }

//===========================================================================================

vector<int> getLongestPalindrome(string str, int leftIdx, int rightIdx);


// Time O(N^2) | Space O(n)
string longestPalindromeSubstring2(string str){
    //substring, strart from 1st value, ends at last value/
    //abax - a 
    vector<int> currentLongest{0,1};

    //go from left to right
    for (int i = 1 ; i < str.length(); i++){

      //find the index of longestPalindrome with odd # of characters
      vector<int> odd = getLongestPalindrome(str, i-1, i+1);
      vector<int> even = getLongestPalindrome(str, i-1, i);

      vector<int> longest;
      if ((even[1]-even[0]) > (odd[1] - odd[0])){
        longest = even;
      }else{
        longest = odd;
      }

      //compare with the currentLongest
      currentLongest = currentLongest[1] - currentLongest[0] >= longest[1]-longest[0] ? currentLongest : longest;
   }

   return str.substr(currentLongest[0], currentLongest[1] - currentLongest[0]);
}

vector<int> getLongestPalindrome(string str, int leftIdx, int rightIdx){
  while (leftIdx >= 0 && rightIdx < str.length()){
    if (str[leftIdx] != str[rightIdx]){
      break;
    }
    leftIdx--;
    rightIdx++;
  }
  return vector<int>{leftIdx+1, rightIdx};
}




int main() {
  string result = longestPalindromeSubstring2("abaxyzzyxf");
  cout << result;
}

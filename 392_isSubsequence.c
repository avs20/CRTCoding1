
//Leetcode 392
https://leetcode.com/problems/is-subsequence/submissions/

// Time O(n) | Space O(1)
bool isSubsequence(char * s, char * t){
    
    //1. Create the pointers 
    int tIdx = 0 ;
    int sIdx = 0 ;
    
    //now loop until any one string finished 
    
    while ( t[tIdx] != '\0' && s[sIdx] != '\0') {
        
        //check if both tIdx and sIdx point to same characters 
         if (t[tIdx] == s[sIdx]) {
             sIdx++;
         }
        
        // increase tIdx in all cases
        tIdx++;        
        
    }
    
    //now check if sIdx is = length of array 
    if ( s[sIdx] == '\0')
        return true;
    else 
        return false;

}


//LeetCode 845 : Longest Mountain 
//Link https://leetcode.com/problems/longest-mountain-in-array/
int longestMountain(int* arr, int arrSize){
    
    int longestPeakLength = 0 ;
    
    int i = 1; 
    
    while ( i < arrSize - 1) {
        bool isPeak = arr[i-1] < arr[i] && arr[i+1] < arr[i];
        
        if (!isPeak){
            i += 1; 
            continue;
        }
        
        int leftIdx = i - 2; 
        int rightIdx = i + 2; 
        
        while (leftIdx >= 0 && arr[leftIdx] < arr[leftIdx+1]){
            leftIdx -= 1;
        }
        
        while (rightIdx < arrSize && arr[rightIdx] < arr[rightIdx -1]){
            rightIdx += 1;
        }
        
        int currentLength = rightIdx - leftIdx -1;
        if (longestPeakLength < currentLength){
            longestPeakLength = currentLength;
        }
        
        i = rightIdx;
        
        
    }
    
    return longestPeakLength;

}

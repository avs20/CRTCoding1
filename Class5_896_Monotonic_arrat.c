// Leet code 896
// https://leetcode.com/problems/monotonic-array/

bool isMonotonic(int* A, int ASize){
    
    bool increasing = true;
    bool decreasing = true;
    
    for ( int i = 1 ; i < ASize; i++){
        
        if (A[i] > A[i - 1]) {
            decreasing = false;
        }
        else if (A[i] < A[i - 1]){
            increasing = false;
        }
        
        
        
    }
    
    return increasing || decreasing;
        

}

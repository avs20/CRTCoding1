/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    printf("Hello World");

    return 0;
}


vector<int> getSmaller(vector<int> array){
    vector<int> smaller = {};
    for (int i = 1 ; i < array.size() ; i++) {
        if (array[i] < array[0]){
            smaller.push_back(array[i]);
        }
    }
    return smaller;
}


vector<int> getBiggerOrEqual(vector<int> array){
    vector<int> bigger = {};
    for (int i = 1 ; i < array.size() ; i++) {
        if (array[i] >= array[0]){
            bigger.push_back(array[i]);
        }
    }
    return bigger;
}




//check if the bsts in array form are same or not 
bool sameBsts(vector<int> arrayOne, vector<int> arrayTwo){
    
    //both empty
    if(arrayOne.size() ==0 && arrayTwo.size() == 0)
        return true;
    
    //check length
    if (arrayOne.size() != arrayTwo.size())
        return false;
        
    //check the first values in array 
    if (arrayOne[0] ! = arrayTwo[0])
        return false;
    
    //make our 4 arrays 
    
    vector<int> leftOne = getSmaller(arrayOne);
    vector<int> leftTwo = getSmaller(arrayTwo);
    vector<int> rightOne = getBiggerOrEqual(arrayOne);
    vector<int> rightTwo = getBiggerOrEqual(arrayTwo);
    
    return sameBsts(leftOne, leftTwo) && sameBsts(rightOne, rightTwo);
    
}

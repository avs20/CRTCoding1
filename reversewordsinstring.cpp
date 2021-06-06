#include <vector>

using namespace std;

// reverses an array elements from start to end 
// ashu, 0, 2
// hsau 
// O(N)
void reverseListRange(vector<string> &list, int start, int end){
    while(start < end){
        char temp = list[start];
        list[start] = list[end];
        list[end] = temp;
        start++;
        end--;
    }

    /*
        h s a u      0, 2

    */


}

//O(N) Time | O(N) space
string reverseWordsinString(string str){

    vector<char> characters;

    // ashu 
    // 'a','s','h','u'
    for(int i = 0 ; i < str.length(); i++){
        characters.push_back(str[i]);
    }

    //reverse the full stirng 
    reverseListRange(characters, 0, characters.size() - 1);

    int startOfWord = 0 ; 
    while (startOfWord < characters.size() ){
        int endOfWord = startOfWord;
        
        while (endOfWord < characters.size() && characters[endOfWord] != " "){
            endOfWord++;
        }

        //now we got the space 
        // extract the word from sow to eow
        reverseListRange(characters, startOfWord, endOfWord - 1);

        startOfWord = endOfWord + 1
    }

    //we have an array of characters with reverse words 
    // we need string 
    string output; 

    for (int i = 0 ; i < characters.size() ; i++){
        output += characters[i];
    }


    return output;   

}

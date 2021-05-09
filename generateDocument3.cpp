#include <iostream>
#include <unordered_map>;

using namespace std;

// Time : O(m+n) Space : O(c)
bool generateDocument( string characters, string document){
  // create hashmap 
  unordered_map<char, int> characterCounts;

  //fill the hashmap
  for (int i = 0 ;i < characters.length(); i++){
    if (characterCounts.find(characters[i]) == characterCounts.end()){
      characterCounts[characters[i]] = 0;
    }
    //increment the count
    characterCounts[characters[i]]++;
  }

  //now check for each charcter in document 
  for (auto character: document){
        // if this char is not found in the hashmap
        if (characterCounts.find(character) == characterCounts.end() || characterCounts[character] == 0){
          return false;
        }
    //decrement the count
    characterCounts[character]--;

}

return true;
}

int main() {

  string chars = "sumitaarora";
  string docs = "arorasumitaa";
  
  cout << generateDocument(chars, docs);


  
}

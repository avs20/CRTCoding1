#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool isValidPart(string str){
  //2 conditions 
  // integer value < 255
  // there should be no leading 0 
  //  "028" -> integer me convert -> 28 -> conver to string ->. "28"

  int intPart = stoi(str);
  if (intPart > 255)
    return false;
  
  string strPart = to_string(intPart);
  if (strPart.length() == str.length())
    return true;
  
  return false;
  
}
/*
["192", "168", "255" ["20"]
192.168.255.20.

192.168.255.20
*/
string join(vector<string> str){
  string s; 
  for(int i = 0 ; i < str.size() ; i++){
    s += str[i];
    if (i < str.size() - 1) {
      s += ".";
    }
  }

  return s;
}

//Time Complexity

// maximum 12 digits 
// steps are fixed now 
// O(1) -> 
vector<string> getValidIpAddress(string str){

  vector<string> ipAddressFound;
  if (str.length() > 12 || str.length() < 4){
    return ipAddressFound;
  }
  //result array 
  

  /*
    192

    min(3,4)

    i 1 -> 4 not included  

    1921680

    i = 1 
    substr(0, 1) = 1

    1926
    1


  */
  for (int i = 1 ; i < min((int)str.length(), 4 ); i++){
      vector<string> parts = { "", "", "", ""};
      parts[0] = str.substr(0, i);
      if(!isValidPart(parts[0])){
        continue;
      }

      //now find the second part 
      for (int j = i + 1 ; j < (i + min((int)str.length() -i , 4)) ; j++){
          parts[1] = str.substr(i, j-i);
          if(!isValidPart(parts[1])){
            continue;
          }

          //now find 3rd and 4th parts 
          for (int k = j + 1 ; k < (j + min((int)str.length() - j, 4)); k++){
            parts[2] = str.substr(j, k-j);
            parts[3] = str.substr(k);

            if(isValidPart(parts[2]) && isValidPart(parts[3])){
              ipAddressFound.push_back(join(parts));
            }

          }
      }
  }
  return ipAddressFound;
}


int main() {

  vector<string> result = getValidIpAddress("1921680");
  for(int i = 0 ; i < result.size() ;i++){
    cout<<result[i]<<endl;
  }
}

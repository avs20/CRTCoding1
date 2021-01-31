#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  //dynamic array in c++
  vector<int> array;

  array.push_back(67);
  array.push_back(23);
  array.push_back(33);
  array.push_back(11);

  cout << "Size of array is " << array.size() <<endl;

  array.push_back(-1);

  cout << "Size of array is " << array.size();

  sort(array.begin(), array.end());

  for (int i = 0 ;i < array.size() ; i++){
    cout << array[i] <<endl;
  }

  vector<vector<int>> _2darray;
  // [ [1,2], [3,5] ]

  _2darray.push_back({1,2});
  _2darray.push_back({3,4});

  for (int i = 0 ;i < _2darray.size() ; i++){
      cout << _2darray[i][1] << "\t" ;
    }


}

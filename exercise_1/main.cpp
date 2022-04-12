#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> myarray = {4, 2, 11, 8, 3};

int sum = 14;

/**
 * @brief Iterate naively over the array in a double loop. O(n^2)
 */
void naive_method(){

  for ( int i = 0; i < myarray.size(); ++i){
    for (int j = i+1; j < myarray.size(); ++j){
      if (myarray[i] + myarray[j] == sum){
        cout << "Solution found: " << myarray[i] << " + " << myarray[j] <<  " = " << sum << endl;
        return;
      }
    }
  }
  cout << "No solution found" << endl;
}

/**
 * @brief Sort the array and then iterate only once over the array O(n log(n) + n) -> O(n log(n)) 
 */
void sort_and_split(){
  sort(myarray.begin(), myarray.end()); // sorts the array from small to big values, O(n log(n))
  
  //Create iterators
  std::vector<int>::iterator frontal = myarray.begin(), backward = myarray.end()-1; 

  // Check for edgecase O(1)
  if(frontal == backward){ //Is this edge case even possible?
    if (*frontal == sum) cout << "Solution found with only one element in array: " << sum << endl;
    else cout << "No solution possible" << endl;
  }

  // Iterate once over the sorted set O(n)
  while (frontal != backward){
    if (*frontal + *backward == sum){
      cout << "Solution found: " << *frontal << " + " << *backward <<  " = " << sum << endl;
      return;
    }
    else if (*frontal + *backward < sum) ++frontal; // Number too small, increase by moving forward with the frontal
    else --backward; // Number too small, decrease by moving back with backward.
  }

  cout << "No solution found" << endl;
  

}

int main(int argc, char* argv[]){
  naive_method();
  sort_and_split();

}
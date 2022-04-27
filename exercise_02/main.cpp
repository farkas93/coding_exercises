#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> myarray = {3, 5, 0, 1, 0, -10, 0, 0, 7, 4};

void print_solution(vector<int> arr){
  cout << "Solution is [ ";
  for(int i = 0; i < arr.size(); ++i){
    cout << arr[i];
    if(i < arr.size()-1)
      cout << ", ";
  }
  cout << " ]" << endl;
}


/**
 * @brief Pushing all the 0 by first copying the array into a deque -> putting all the zeros to the front. O(n), 
 * since push_back and push_front both O(1), copying array to deque is O(n). Copying deque back to an array is O(n) too.
 * Total complexity: O(n)
 * Memory complexity: O(n)
 */
void naive_method(){
  deque<int> my_deque;
  for(auto el : myarray){
    if(el == 0)
      my_deque.push_front(el);
    else
      my_deque.push_back(el);
  }
  //convert deque back to array
  vector<int> new_array;
  for(int i = 0; i < my_deque.size(); ++i){
    new_array.push_back(my_deque[i]);
  }

  print_solution(new_array);
}

/**
 * @brief Pushing all the 0 by in-place comparison of the elements to the front. O(n)
 * Total complexity: O(n)
 * Memory complexity: O(1)
 */
void inplace_method(){
  int copy_to_ind = myarray.size()-1;
  for(int i = myarray.size()-1; i >= 0; --i){
    if(myarray[i] == 0){
      if(myarray[i-1] != 0){
        //swap
        myarray[copy_to_ind] = myarray[i-1];
        myarray[i-1] = 0; 
      }
      else continue;

    }
    --copy_to_ind;
  }
}

int main(int argc, char* argv[]){
  
  print_solution(myarray);
  naive_method();
  inplace_method();  
  print_solution(myarray);
}
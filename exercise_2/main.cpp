#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> myarray = {3, 5, 0, 1, 0, 7, 4};

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

int main(int argc, char* argv[]){
  naive_method();

}
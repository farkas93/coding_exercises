#include <cstdlib>
#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

/**
 * @brief Find largest subarray sum
 * Runtime Memory O(n^2)
 * Memory Complexity O(n^2)
 * @param input 
 * @return int 
 */
int find_largest_sum_with_mem(vector<int> &input){
    vector<vector<int> > memory(input.size(), vector<int>(input.size(),0));
    int current_maximum = INT_MIN; 
    for (int i = 0; i < input.size(); ++i){
        for (int j = i; j < input.size(); ++j){
            if (i == j) memory[i][j] = input[i];
            else memory[i][j] = input[j] + memory[i][j-1];

            if (memory[i][j] > current_maximum) current_maximum = memory[i][j];
        }
    }
    return current_maximum;
}

/**
 * @brief Find largest subarray sum
 * Runtime Memory O(n^2)
 * Memory Complexity O(1), since we can neglect additional memory
 * @param input 
 * @return int 
 */
int find_largest_sum_without_mem(vector<int> &input){
    int current_maximum = INT_MIN; 
    for (int i = 0; i < input.size(); ++i){
        int current_sum = 0;
        for (int j = i; j < input.size(); ++j){
            current_sum += input[j];
            if (current_sum > current_maximum) current_maximum = current_sum;
        }
    }
    return current_maximum;
}

/**
 * @brief Find largest subarray sum
 * Runtime Memory O(n)
 * Memory Complexity O(1), since we can neglect additional memory
 * @param input 
 * @return int 
 */
int find_largest_sum_linear(vector<int> &input){
    int current_maximum = INT_MIN; 
    int current_sum = 0;
    for (int i = 0; i < input.size(); ++i){
        if(input[i] + current_sum > 0){
            current_sum += input[i];
            if(current_sum > current_maximum) current_maximum = current_sum;
        }
        else{
            current_sum = 0;
        }
    }
    return current_maximum;
}

int main(int argv, char* argc[]){
    vector<int> array = { 1, -5, 2, 3, -1, -1, 4};
    cout << find_largest_sum_with_mem(array) << endl;
    cout << find_largest_sum_without_mem(array) << endl;
    cout << find_largest_sum_linear(array) << endl;
    
}
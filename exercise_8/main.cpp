#include <cstdlib>
#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

/**
 * @brief Naive solution. Check each possible substring in the input. 
 * Runtime complexity: O(n^3)
 * Memory complexity: O(n^2)
 * @param input 
 * @return unordered_set<string> 
 */
unordered_set<string> find_palindromes(string input)
{
    unordered_set<string> output;
    for(int i = 0; i < input.length()-1; ++i){
        for(int j = 2; j <= input.length()-i; ++j){
            string toAnalyse = input.substr(i, j);
            bool palindrome = true;

            string::iterator front_it = toAnalyse.begin();
            string::iterator end_it = toAnalyse.end() - 1;
            for(int k = 0; k < j/2; ++k){
                
                if(*front_it != *end_it){
                    palindrome = false;
                    break;
                }
                ++front_it;
                --end_it;
            }
            if(palindrome){
                cout << "Found palindrome: " << toAnalyse << endl;
                output.insert(toAnalyse);

            }
        }
    }
    return output;
}

/**
 * @brief finds palindromes by divide and conquer
 * Runtime complexity: O(n^2)
 * Memory complexity: O(n^2)
 * @param input 
 * @return unordered_set<string> 
 */
unordered_set<string> find_palindromes_n2(string input){
    unordered_set<string> output;
    for(int i = 0; i < input.length(); ++i){
        //Find palindromes with even number of chars
        for(int j = i, k =i+1; j >= 0 && k < input.length(); ++k, --j){
            if(input[j] != input[k]) break;
            else output.insert(input.substr(j, k-j+1));
        }
        //Find palindromes with odd number of chars
        for(int j = i-1, k =i+1; j >= 0 && k < input.length(); ++k, --j){
            if(input[j] != input[k]) break;
            else output.insert(input.substr(j, k-j+1));
        }
    }
    return output;
}

void print_palindromes(unordered_set<string> toPrint){
    for(auto palindrome : toPrint){
        cout << palindrome << endl;
    }
}

int main(int argv, char* argc[])
{
    string input = "ananabanana";
    unordered_set<string> out = find_palindromes(input);
    print_palindromes(out);
    cout << "======" << endl;
    out = find_palindromes_n2(input);
    print_palindromes(out);
}
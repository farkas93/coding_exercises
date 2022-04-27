#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

bool is_digit(char c){
    return c >= '0' && c <= '9';
}

bool is_period(char c ){
    return c == '.';
}

/**
 * @brief Investigate some string on if it is a number or not.
 * Runtime complexity: O(n)
 * Memory complexity: O(1) 
 * @param input some string.
 * @return true if the string is describing a number, else false.
 */
bool eval_if_number(string input){
    bool isANumber = true;
    bool isFloat = false;
    for( char c : input){
        if(is_digit(c)) continue;
        if (is_period(c)){
            if(!isFloat) isFloat = true;
            else isANumber = false;
            continue;
        }
        isANumber = false;
    }
    return isANumber;
}

int main(int argv, char* argc[]){
    string input = "4245";
    cout << input << " is a number? " << (eval_if_number(input) ? "True" : "False") << endl;
}
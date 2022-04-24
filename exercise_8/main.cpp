#include <cstdlib>
#include <unordered_set>
#include <string>
#include <iostream>

using namespace std;

bool iterate_and_search(string input, unordered_set<string> &dict){
    int start_word_ind = 0;
    int term = 0;
    for(int i = 1; i < input.length() - term; ++i){
        string temp = input.substr(start_word_ind, i);
        cout << "looking at word: " << temp << endl;
        if(dict.find(temp) != dict.end()){
            start_word_ind += i;
            term = start_word_ind -1;
            i = 0;
            cout << "found word : " << temp << endl;
        }
    }
    return start_word_ind == input.size();
}

int main(int argv, char* argc[]){
    unordered_set<string> dictionary = {"Word1", "humsibumsi", "Word2", "Word3"};
    string input_string = "Word1humsibumsiWord2Word3";
    bool solveable = iterate_and_search(input_string, dictionary);
    cout << (solveable ? "True" : "False") << endl;
}
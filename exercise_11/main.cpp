#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

string concat_right(string in){
    return in + "{}";
}

string concat_left(string in){
    return "{}" + in;
}

string wrap(string in){
    return "{" + in + "}";
}

unordered_set<string> recurse(int n){
    if(n == 1){
        unordered_set<string> res;
        res.insert("{}");
        return res;
    }
    else{
        unordered_set<string> temp = recurse(n-1);
        unordered_set<string> res;
        for (unordered_set<string>::iterator it = temp.begin(); it != temp.end(); ++it){
            res.insert(concat_left(*it));
            res.insert(concat_right(*it));
            res.insert(wrap(*it));
        }
        return res;
    }
}

void print_all_combinations(int n){
    if (n <= 0) return;
    unordered_set<string> result = recurse(n);

    for (unordered_set<string>::iterator it = result.begin(); it != result.end(); ++it){
        cout << *it << " | ";
    }
    cout << endl;
}


int main(int argv, char* argc[]){
    int n = 4;
    print_all_combinations(n);
}
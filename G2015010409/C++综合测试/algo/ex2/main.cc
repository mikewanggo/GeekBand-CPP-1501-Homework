#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <string.h>
using namespace std;

int main() {
    string str;
    set<string> string_set;
    while (getline(cin, str)) {
    
        // IF CASE INSENSITIVE, SHOULD CONVERT THE STRING TO UPPER CASE
        // transform(str.begin(), str.end(), str.begin(), [](char c) { return toupper(c); });
        sort(str.begin(), str.end());
        string_set.insert(str);
    }
    cout << string_set.size() << endl;
    return 0;
}


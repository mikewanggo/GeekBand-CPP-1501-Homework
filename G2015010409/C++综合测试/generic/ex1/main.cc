#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main() {
    vector<int> src = { 0, 0, 30, 20, 0, 0, 0, 0, 10, 0 };
    vector<int> dest;
    copy_if(src.cbegin(), src.cend(), back_inserter(dest),
            bind1st(not_equal_to<int>(), 0));
    for (auto i : dest) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}


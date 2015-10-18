#include <iostream>

#include "moving_average.h"

using namespace std;

int main() {
    MovingAverage ma(2);
    cout << ma.next(1) << endl;
    cout << ma.next(3) << endl;
    cout << ma.next(4) << endl;
    return 0;
}


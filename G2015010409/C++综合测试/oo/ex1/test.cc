#include <iostream>

#include "polygon.h"
using namespace std;

int main() {
    Point points[] = {
        { 1, 2 },
        { 2, 4 },
    };
    const int kPointCount = sizeof(points) / sizeof(points[0]);
    Polygon p(points, kPointCount, 1);
    cout << p << endl;
    Polygon q(p);
    cout << q << endl;
    Polygon t(points, kPointCount, 2);
    cout << t << endl;
    t = q;
    cout << t << endl;
    return 0;
}


#include <iostream>

#include "console_observer.h"
#include "imodifier.h"
#include "point.h"

using namespace std;

int main() {
    Point p;
    ConsoleObserver observer;
    p.addIModifier(&observer);
    p.set_x(1);
    p.set_y(2);
    p.removeIModifier(&observer);
    p.set_x(3);
    p.set_y(4);
    return 0;
}


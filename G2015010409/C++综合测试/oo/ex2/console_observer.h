#ifndef CONSOLE_OBSERVER_H_
#define CONSOLE_OBSERVER_H_

#include "point.h"
#include "imodifier.h"

class ConsoleObserver: public IModifier {
public:
    ConsoleObserver() { }
    ~ConsoleObserver() { }

    void update(const Point& p) {
        std::cout << p.x() << ", " << p.y() << std::endl;
    }

};

#endif  // CONSOLE_OBSERVER_H_


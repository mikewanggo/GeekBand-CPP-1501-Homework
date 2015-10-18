#ifndef IMODIFIER_H_
#define IMODIFIER_H_

#include "point.h"

class IModifier {
public:
    virtual ~IModifier() { }
    virtual void update(const Point& p) = 0;
};

#endif  // IMODIFIER_H_


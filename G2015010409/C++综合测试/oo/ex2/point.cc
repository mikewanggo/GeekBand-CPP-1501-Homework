#include "point.h"

#include <assert.h>
#include <set>

#include "imodifier.h"

void Point::onModify() {
    for (std::set<IModifier*>::iterator it = imodifier_set.begin();
         it != imodifier_set.end();
         ++it) {
        (*it)->update(*this);
    }
}

void Point::set_x(int x) {
    x_ = x;
    onModify();
}

void Point::set_y(int y) {
    y_ = y;
    onModify();
}

void Point::addIModifier(IModifier* modifier) {
    assert(modifier);
    if (modifier) {
        imodifier_set.insert(modifier);
    }
}

void Point::removeIModifier(IModifier* modifier) {
    assert(modifier);
    imodifier_set.erase(modifier);
}


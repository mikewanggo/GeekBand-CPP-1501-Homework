#ifndef POLYGON_H_
#define POLYGON_H_

#include <memory>

#include "shape.h"
#include "point.h"

class Polygon: public Shape {
friend std::ostream& operator<<(std::ostream& os, const Polygon& rhs);

public:
    Polygon(const Point* points, int num = 0, int no = 0);
    Polygon(const Polygon& rhs);
    Polygon& operator=(const Polygon& rhs);
    ~Polygon();
    
private:
    static std::allocator<Point> alloc;
    Point* copy_and_construct(const Point* p, int size);
    void clear();
    Point* points_;
    int num_;  // Number of points
};

std::ostream& operator<<(std::ostream& os, const Polygon& rhs);

#endif  // POLYGON_H_


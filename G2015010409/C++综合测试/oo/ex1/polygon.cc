#include "polygon.h"

#include <assert.h>
#include <algorithm>
#include <iostream>
#include <memory>

#include "shape.h"
#include "point.h"

std::allocator<Point> Polygon::alloc;

Point* Polygon::copy_and_construct(const Point* points, int size) {
    Point* p = nullptr;
    if (points == nullptr) {
        return nullptr;
    } else {
        p = alloc.allocate(size);
        std::uninitialized_copy(points, points + size, p);
    }
    return p;
}

void Polygon::clear() {
    if (points_) {
        for (int i = 0; i < num_; ++i) {
            alloc.destroy(points_ + i);
        }
        alloc.deallocate(points_, num_);
        points_ = nullptr;
    }
    num_ = 0;
}

Polygon::Polygon(const Point* points, int num, int no):
    Shape(no), num_(num) {
    points_ = copy_and_construct(points, num);
}

Polygon::Polygon(const Polygon& rhs): Shape(rhs), num_(rhs.num_) {
    points_ = copy_and_construct(rhs.points_, rhs.num_);
}

Polygon&
Polygon::operator=(const Polygon& rhs) {
    if (this == &rhs) {
        return *this;
    }
    Shape::operator=(rhs);
    Point* new_points = copy_and_construct(rhs.points_, rhs.num_);
    clear();
    points_ = new_points;
    num_ = rhs.num_;
    return *this;
}


Polygon::~Polygon() {
    clear();
}

std::ostream& operator<<(std::ostream& os, const Polygon& rhs) {
    os << "No: " << rhs.no() << " ";
    if (rhs.points_) {
        for (int i = 0; i < rhs.num_; ++i) {
            os << rhs.points_[i] << " ";
        }
    }
    return os;
}


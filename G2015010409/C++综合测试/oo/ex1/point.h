#ifndef POINT_H_
#define POINT_H_

#include <iostream>

class Point {
friend std::ostream& operator<<(std::ostream& os, const Point& rhs);
public:
    Point(int x = 0, int y = 0): x_(x), y_(y) { }

private:
    int x_;
    int y_;
};

inline std::ostream& operator<<(std::ostream& os, const Point& rhs) {
    os << "(" << rhs.x_ << ", " << rhs.y_ << ")";
    return os;
}

#endif  // POINT_H_


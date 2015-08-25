#ifndef GEEKBAND_HOMEWORK_CIRCLE_H
#define GEEKBAND_HOMEWORK_CIRCLE_H

#include "shape.h"
#include "point.h"

class Circle : public Shape {
 private:
  Point center_;
  int radius_;
 public:
  Circle(int x, int y, int r) : center_(Point(x, y)), radius_(r) { }

  Circle(const Circle& other): center_(other.center_), radius_(other.radius_) { }

  Circle& operator=(const Circle& other) {
      this->Shape::operator=(other);
      this->center_ = other.center_;
      this->radius_ = other.radius_;
      return *this;
  }

  int GetArea() const {
      static const double kPi = 3.1415926;
      return kPi * radius_ * radius_; 
  }
};

#endif  // GEEKBAND_HOMEWORK_CIRCLE_H


#ifndef GEEKBAND_HOMEWORK_RECTANGLE_H
#define GEEKBAND_HOMEWORK_RECTANGLE_H

#include "shape.h"
#include "point.h"

class Rectangle : public Shape {
 private:
  int width_;
  int height_;
  Point left_up_;

 public:
  Rectangle(int width = 0, int height = 0, int x = 0, int y = 0) 
      : width_(width), height_(height), left_up_(Point(x, y)) { }

  Rectangle(const Rectangle& other) 
      : Shape(other), width_(other.width_), 
        height_(other.height_), left_up_(other.left_up_) { }

  Rectangle& operator=(const Rectangle& other) {
      this->Shape::operator=(other);
      this->width_ = other.width_;
      this->height_ = other.height_;
      this->left_up_ = other.left_up_;
      return *this;
  }

  void set_width(int width) {
      this->width_ = width;
  }

  void set_height(int height) {
      this->height_ = height;
  }

  int GetArea() const {
      return this->width_ * this->height_;
  }
};

#endif  // GEEKBAND_HOMEWORK_RECTANGLE_H


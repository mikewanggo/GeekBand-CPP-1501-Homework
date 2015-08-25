#ifndef GEEKBAND_HOMEWORK_SHAPE_H
#define GEEKBAND_HOMEWORK_SHAPE_H

class Shape {
 private:
  int no_;
 public:
  Shape(int no = 0) : no_(no) { }
  virtual ~Shape() { }
  virtual int GetArea() const = 0;
  int no() const { return this->no_; }
  void set_no(int no) { this->no_ = no; }
};

#endif  // GEEKBAND_HOMEWORK_SHAPE_H


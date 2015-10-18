#ifndef SHAPE_H_
#define SHAPE_H_

class Shape {
public:
    Shape(int n = 0): no_(n) { }
    virtual ~Shape() { }
    int no() const { return no_; }

private:
    int no_;
    
};

#endif  // SHAPE_H_


#ifndef POINT_H_
#define POINT_H_

#include <set>

class IModifier;

class Point {
public:
    Point(int x = 0, int y = 0):
        x_(x), y_(y) { }
    Point(const Point& rhs): x_(rhs.x_), y_(rhs.y_) { }
    Point& operator=(const Point& rhs) {
        if (this != &rhs) {
            x_ = rhs.x_;
            y_ = rhs.y_;
            onModify();
        }
        return *this;
    }
    ~Point() { }

    void addIModifier(IModifier* imodifier);
    void removeIModifier(IModifier* imodifier);

    int x() const { return x_; }
    int y() const { return y_; }

    void set_x(int x);
    void set_y(int y);

private:
    int x_;
    int y_;
    std::set<IModifier*> imodifier_set;  // Not owned.
    void onModify();
};

#endif  // POINT_H_


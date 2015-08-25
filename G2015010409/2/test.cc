#include <climits>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "circle.h"
#include "rectangle.h"

using namespace std;

const int kRectangleCount = 10;
const int kCircleCount = 10;
const int kShapeCount = kRectangleCount + kCircleCount;

const int kMinRadius = 1;
const int kMaxRadius = 10;
const int kMinWidth = kMinRadius;
const int kMaxWidth = kMaxRadius; 
const int kMinHeight = kMinWidth;
const int kMaxHeight = kMaxWidth;
const int kMinX = kMinWidth;
const int kMaxX = kMaxWidth;
const int kMinY = kMinHeight;
const int kMaxY = kMaxHeight;
const int kMinLegalShapeSize = 50;

// Returns a random number in [first, last]
int RandInt(int first, int last) {
    double p = (rand() + 0.0)/ RAND_MAX;
    return first + (last + 1 - first) * p;
}

// Removes the shapes the size of which is smaller than the given area limit, 
// and returns the count of shapes left. The shapes removed from the shape 
// will be destructed, and the relevant pointer in the array will be set
// nullptr.
// shape - inout, the shape for work.
// size - the shape array size.
// limit - the lower bound of the shape's area.
int RemoveSmallerThan(Shape* shape[], int size, int limit) {
    int result_size = 0;
    for (int i = 0; i < size; ++i) {
        if (shape[i]->GetArea() < limit) {
            delete shape[i];
            shape[i] = nullptr;
        } else {
            shape[result_size++] = shape[i];
        }
    }
    return result_size;
}

int main() {
    srand(time(NULL));
    Shape* shape[kShapeCount];
	// Construct rectangles and circles, will be destructed
	// in RemoveSmallerThan and the end of the program.
	// Construct rectangles.
    for (int i = 0; i < kRectangleCount; ++i) {
        int x = RandInt(kMinX, kMaxX);
        int y = RandInt(kMinY, kMinY);
        int width = RandInt(kMinWidth, kMaxWidth);
        int height = RandInt(kMinHeight, kMinHeight);
        cout << "NO." << i + 1 << ": (" << x << "," << y
             << ")" << ", [" << width << ", " << height
             << "]" << endl;
        shape[i] = new Rectangle(x, y, width, height);
        shape[i]->set_no(i);
    }
	// Construct circles.
    for (int i = kRectangleCount; i < kShapeCount; ++i) {
        int x = RandInt(kMinX, kMaxX);
        int y = RandInt(kMinY, kMinY);
        int radius = RandInt(kMinRadius, kMaxRadius);
        cout << "NO." << i + 1 << ": (" << x << "," << y
             << ")"  << ", [" << radius << "]" << endl;
        shape[i] = new Circle(x, y, radius);
        shape[i]->set_no(i);
    }
    int legal_shape_count = RemoveSmallerThan(
        shape, kShapeCount, kMinLegalShapeSize);
	// Show the legal shapes, and destruct them.
    for (int i = 0; i < legal_shape_count; ++i) {
        cout << "NO: " << shape[i]->no() << ", size is "
             << shape[i]->GetArea() << endl;
        delete shape[i];
        shape[i] = nullptr;
    }
    return 0;
}


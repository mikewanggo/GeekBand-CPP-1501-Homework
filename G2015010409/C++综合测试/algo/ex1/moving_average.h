#ifndef MOVING_AVERAGE_H_
#define MOVING_AVERAGE_H_

#include <deque>

class MovingAverage {
public:
    MovingAverage(std::size_t window_size): window_size_(window_size), sum_(0) { }
    double next(int value) {
        sum_ += value;
        window_.push_back(value);
        if (window_.size() > window_size_) {
            sum_ -= window_.front();
            window_.pop_front();
        }
        return (sum_ + 0.0) / window_.size();
    }

private:
    const std::size_t window_size_;
    int sum_;
    std::deque<int> window_;
};

#endif  // MOVING_AVERAGE_H_

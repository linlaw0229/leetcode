/*
Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

Example:

MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3

*/

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size): sum(0) {
        this->size= size;
    }
    
    double next(int val) {
        if(q.size()>= size){
            sum-= q.front(); q.pop();
        }
        q.push(val);
        sum+= val;
        return q.size() == size? (sum/size): (sum/q.size());
    }
    
    queue<int> q;
    int size;
    double sum;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
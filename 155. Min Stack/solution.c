/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/

class MinStack {
public:
    /** initialize your data structure here. */
        stack<int> _stack;
        stack<int> trackmin;
    MinStack() {
        
    }
    
    void push(int x) {
        _stack.push(x);
        if(trackmin.empty() || x <= trackmin.top())
            trackmin.push(x);
    }
    
    void pop() {
        if(_stack.top() == trackmin.top())
            trackmin.pop();
        return _stack.pop();
    }
    
    int top() {
        return _stack.top();
    }
    
    int getMin() {
        return trackmin.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

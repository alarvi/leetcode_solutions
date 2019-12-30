// https://leetcode.com/problems/min-stack/
class MinStack {
    stack<int> data;
    stack<int> minimums;
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        data.push(x);
        if (minimums.empty() or minimums.top() >= x) {
            minimums.push(x);
        }
    }
    
    void pop() {
        int v = data.top();
        data.pop();
        if (minimums.top() == v) {
            minimums.pop();
        }
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return minimums.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
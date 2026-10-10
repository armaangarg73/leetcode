class MinStack {
public:
    stack<int> main;
    stack<int> mins;

    MinStack() {}

    void push(int value) {
        main.push(value);

        if (mins.empty())
            mins.push(value);
        else
            mins.push(min(value, mins.top()));
    }

    void pop() {
        main.pop();
        mins.pop();
    }

    int top() {
        return main.top();
    }

    int getMin() {
        return mins.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
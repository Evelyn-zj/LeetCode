class MyQueue {
public:
    MyQueue() {
    }
    
    void push(int x) {
        back.push(x);
    }
    
    int pop() {
        if (!front.empty()) {
            int temp = front.top();
            front.pop();
            return temp;
        } else if (!back.empty()) {
            while (!back.empty()) {
                front.push(back.top());
                back.pop();
            }
            int temp = front.top();
            front.pop();
            return temp;
        }
        return 0;
    }
    
    int peek() {
        if (!front.empty()) {
            int temp = front.top();
            return temp;
        } else if (!back.empty()) {
            while (!back.empty()) {
                front.push(back.top());
                back.pop();
            }
            int temp = front.top();
            return temp;
        } else {
            return 0;
        }
    }
    
    bool empty() {
        return back.empty() && front.empty();
    }

private:
    stack<int> back, front;

};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
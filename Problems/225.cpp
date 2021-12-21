class MyStack {
public:
    MyStack() {
    }
    
    void push(int x) {
        que.push(x);
    }
    
    int pop() {
        int size = que.size() - 1;
        while (size != 0) {
            size--;
            que.push(que.front());
            que.pop();
        }
        int temp = que.front();
        que.pop();
        return temp;
    }
    
    int top() {
        int size = que.size() - 1;
        while (size != 0) {
            size--;
            que.push(que.front());
            que.pop();
        }
        int temp = que.front();
        que.push(que.front());
        que.pop();
        return temp;
    }
    
    bool empty() {
        return que.empty();
    }

private:
    queue<int> que;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
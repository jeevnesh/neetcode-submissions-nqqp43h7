class MyStack {
private:
    void rotate(queue<int> &q){
        int size = q.size();
        for(int i = 0; i < size - 1; i++){
            int front = q.front();
            q.pop();
            q.push(front);
        }
    }
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        rotate(q);
        int front = q.front();
        q.pop();
        return front;
    }
    
    int top() {
        rotate(q);
        int front = q.front();
        q.pop();
        q.push(front);
        return front;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
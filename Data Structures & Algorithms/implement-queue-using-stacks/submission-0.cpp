class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        int size1 = st1.size();
        for(int i = 0; i < size1-1; i++){
            int num = st1.top();
            st1.pop();
            st2.push(num);
        }
        int top = st1.top();
        st1.pop();
        int size2 = st2.size();
        for(int i = 0; i < size2; i++){
            int num = st2.top();
            st2.pop();
            st1.push(num);
        }
        return top;
    }
    
    int peek() {
        int size1 = st1.size();
        for(int i = 0; i < size1-1; i++){
            int num = st1.top();
            st1.pop();
            st2.push(num);
        }
        int top = st1.top();
        int size2 = st2.size();
        for(int i = 0; i < size2; i++){
            int num = st2.top();
            st2.pop();
            st1.push(num);
        }
        return top;
    }
    
    bool empty() {
        return st1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
class MinStack {
public:
    stack<long long> st;
    long long minElement;
    MinStack() {
        
    }
    
    void push(int val) { 
        if(st.empty()){
            st.push(val);
            minElement = val;
        }else if(val >=minElement){
            st.push(val);
        }else{
            st.push(2LL*val-minElement);
            minElement = val;
        }
    }
    
    void pop() {
        if(st.top() >= minElement){
            st.pop();
        }else{
            minElement = 2*minElement-st.top();
            st.pop();
        }
    }
    
    int top() {
        if(st.top() >= minElement){
            return st.top();
        }else{
            return minElement;
        }
    }
    
    int getMin() {
        return minElement;
    }
};

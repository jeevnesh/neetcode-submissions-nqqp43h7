class FreqStack {
public:
    unordered_map<int,int> freqMap;
    unordered_map<int,stack<int>> group;
    int maxFreq;
    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int val) {
        freqMap[val]++;
        group[freqMap[val]].push(val);
        if(freqMap[val] > maxFreq){
            maxFreq = freqMap[val];
        }
    }
    
    int pop() {
        int result = group[maxFreq].top();
        freqMap[result]--;
        group[maxFreq].pop();
        if(group[maxFreq].empty()){
            maxFreq--;
        }
        return result;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
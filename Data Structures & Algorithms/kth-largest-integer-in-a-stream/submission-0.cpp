class KthLargest {
//brute force
private:
    vector<int> numbers;
    int pos;
    int addNumAndReturnKthLargest(vector<int>& numbers, int val, int pos){
        numbers.push_back(val);
        //rebuilding heap everytime we add a new element this is less efficient
        priority_queue<int, vector<int>, greater<>> minHeap;
        for(auto i : numbers){
            minHeap.push(i);
            if(minHeap.size() > pos){
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
public:
    KthLargest(int k, vector<int>& nums) {
        for(auto i : nums){
            numbers.push_back(i);
        }
        pos = k;
    }
    
    int add(int val) {
        return addNumAndReturnKthLargest(numbers,val,pos);
    }
};

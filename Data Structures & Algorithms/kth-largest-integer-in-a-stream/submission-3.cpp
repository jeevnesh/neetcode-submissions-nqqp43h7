class KthLargest {
private:
    priority_queue<int,vector<int>,greater<int>> minHeap;
    int k = 0;
public:
    KthLargest(int k, vector<int>& nums) {
        for(auto i : nums){
            minHeap.push(i);
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }
        this->k = k;
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size() > k){
            minHeap.pop();
        }
        return minHeap.top();
    }
};

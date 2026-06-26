class KthLargest {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k = 0;

   public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (auto i : nums) {
            minHeap.push(i);
        }
    }

    int add(int val) {
        minHeap.push(val);
        while (minHeap.size() > k) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};

class Solution {
   public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap(stones.begin(), stones.end());
        while (maxHeap.size() > 1) {
            int num1 = maxHeap.top();
            maxHeap.pop();
            int num2 = maxHeap.top();
            maxHeap.pop();
            if (num1 != num2) {
                maxHeap.push(num1 - num2);
            }
        }
        return maxHeap.size() != 0 ? maxHeap.top() : 0;
    }
};

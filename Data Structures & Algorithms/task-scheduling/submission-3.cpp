class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        int count = 0;
        // frequency of each task
        unordered_map<char, int> freqMap;
        for (auto i : tasks) {
            freqMap[i]++;
        }
        // create and populate maxHeap based on frequency
        priority_queue<int> maxHeap;
        for (auto i : freqMap) {
            maxHeap.push(i.second);
        }
        // create a waiting queue
        queue<pair<int, int>> q;  //{freq,nextAvailable}
        while (!maxHeap.empty() || !q.empty()) {
            count++;
            if (!maxHeap.empty()) {
                int top = maxHeap.top();
                top--;
                maxHeap.pop();
                if (top > 0) {
                    q.push({top, n + count});
                }
            }
            if (!q.empty()) {
                pair<int, int> front = q.front();
                if (front.second <= count) {
                    maxHeap.push(front.first);
                    q.pop();
                }
            }
        }
        return count;
    }
};

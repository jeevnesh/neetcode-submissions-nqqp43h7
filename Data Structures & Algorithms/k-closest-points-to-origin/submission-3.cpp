class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> maxHeap;
        for (auto i : points) {
            int dist = (i[0] * i[0]) + (i[1] * i[1]);
            maxHeap.push({dist, i});
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        vector<vector<int>> ans;
        while (!maxHeap.empty()) {
            vector<int> val = maxHeap.top().second;
            maxHeap.pop();
            ans.push_back(val);
        }
        return ans;
    }
};

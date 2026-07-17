class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int, vector<int>>> maxDistance;
        for (auto i : points) {
            long long dist = 1LL * i[0] * i[0] + 1LL * i[1] * i[1];
            maxDistance.push({dist, i});
            if (maxDistance.size() > k) {
                maxDistance.pop();
            }
        }
        while (!maxDistance.empty()) {
            ans.push_back(maxDistance.top().second);
            maxDistance.pop();
        }
        return ans;
    }
};

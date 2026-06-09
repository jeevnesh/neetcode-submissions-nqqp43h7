class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // calculate the distance for each point in the array and 
        // put the distance and point in a maxHeap of size k
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>> pq;
        for (auto& point : points) {
            // int dist = sqrt(pow(i[0], 2) + pow(i[1], 2)); 
            // floating point values when converting into int loose precision
            int dist = point[0] * point[0] + point[1] * point[1];
            pq.push({dist, point});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<vector<int>> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};

class Solution {
   private:
    int getDist(vector<int> point) { return point[0] * point[0] + point[1] * point[1]; }
    int partition(vector<vector<int>>& points, int left, int right) {
        int dist = getDist(points[right]);
        int i = left;
        for (int j = left; j < right; j++) {
            if (getDist(points[j]) <= dist) {
                swap(points[i], points[j]);
                i++;
            }
        }
        swap(points[i], points[right]);
        return i;
    }

   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            int pivotIndex = partition(points, left, right);
            if (pivotIndex == k) {
                break;
            } else if (pivotIndex < k) {
                left = pivotIndex + 1;
            } else if (pivotIndex > k) {
                right = pivotIndex - 1;
            }
        }
        vector<vector<int>> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(points[i]);
        }
        return ans;
    }
};

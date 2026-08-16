class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int i = 0, j = heights.size() - 1, maxWater = 0;
        while (i < j) {
            int minHeight = min(heights[i], heights[j]);
            maxWater = max(maxWater, minHeight * (j - i));
            if (heights[i] < heights[j])
                i++;
            else
                j--;
        }
        return maxWater;
    }
};

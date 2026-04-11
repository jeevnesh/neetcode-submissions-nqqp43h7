class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        int n = heights.size();
        for(int i = 0; i < n; i++){
            int left = i, right = i;
            while(left - 1 >= 0 && heights[left-1] >= heights[i]){
                left--;
            }
            while(right + 1 < n && heights[right+1] >= heights[i]){
                right++;
            }
            int width = right-left+1;
            maxArea = max(maxArea,(width*heights[i]));
        }
        return maxArea;
    }
};

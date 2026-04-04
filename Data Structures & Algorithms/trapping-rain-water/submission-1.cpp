class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0, n = height.size();
        //calculate left max 
        vector<int> leftMax(n,0);
        int topLeft = 0, topRight = 0;
        for(int i = 0; i < n; i++){ 
            topLeft = max(topLeft,height[i]);
            leftMax[i] = topLeft;
        }
        //calculate right max
        vector<int> rightMax(n,0);
        for(int i = n-1; i >= 0; i--){
            topRight = max(topRight,height[i]);
            rightMax[i] = topRight;
        }
        //calculate water 
        for(int i = 1; i < n-1; i++){
            water += max(0,min(leftMax[i],rightMax[i]) - height[i]);
        }
        return water;
    }
};

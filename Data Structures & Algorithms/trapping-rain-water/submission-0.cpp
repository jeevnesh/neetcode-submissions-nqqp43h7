class Solution {
public:
    int trap(vector<int>& height) {
        //brute force
        int water = 0, n = height.size();
        for(int i = 1; i < n-1; i++){
            int maxLeft = 0;
            for(int left = 0; left < i; left++){
                maxLeft = max(maxLeft, height[left]);
            }
            int maxRight = 0;
            for(int right = n-1; right > i; right--){
                maxRight = max(maxRight,height[right]);
            }
            water += max(0,min(maxLeft,maxRight) - height[i]); 
        }
        return water;
    }
};

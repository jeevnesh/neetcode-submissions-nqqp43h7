class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        int maxLen = 1;
        int currLen = 1;
        for(int i = 1 ; i < nums.size(); i++){
            if(nums[i-1] + 1 == nums[i]) {
                currLen++;
            } else if(nums[i-1] == nums[i]){
                continue;
            }
            else {
                currLen = 1;
            }
            maxLen = max(maxLen, currLen);
        }
        return maxLen;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        for(int i = 0 ; i < nums.size(); i++){
            int cmp = target - nums[i];
            if(mpp.find(cmp) != mpp.end()){
                return {mpp[cmp],i};
            }
            mpp[nums[i]] = i;
        }
        return {};
    }
};

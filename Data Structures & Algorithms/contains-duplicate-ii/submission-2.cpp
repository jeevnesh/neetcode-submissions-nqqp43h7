class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n ==0) return false;
        unordered_map<int,int> mpp;
        int i = 0;
        while(i < n){
            if(mpp.find(nums[i]) != mpp.end()){
                if(i-mpp[nums[i]] <= k) return true;
            }
            mpp[nums[i]] = i;
            i++;
        }
        return false;
    }
};
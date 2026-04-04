class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(int num : nums){
            if(mpp[num] != 0){
               return true;
            }
            mpp[num]++;
        }
        return false;
    }
};
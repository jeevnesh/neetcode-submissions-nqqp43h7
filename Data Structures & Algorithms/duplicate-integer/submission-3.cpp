class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(auto i : nums){
            if(mpp.find(i) != mpp.end()){
                return true;
            }
            mpp[i]++;
        }
        return false;
    }
};
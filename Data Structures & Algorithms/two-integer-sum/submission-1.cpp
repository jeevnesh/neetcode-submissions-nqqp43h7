class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> complimentMap;
        for(int i = 0 ; i < nums.size(); i++){
            int cmp = target - nums[i];
            if(complimentMap.find(cmp) != complimentMap.end()){
                return {complimentMap[cmp], i};
            }
            complimentMap[nums[i]] = i;
        }
        return {};
    }
};

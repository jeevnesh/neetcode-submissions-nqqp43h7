class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> freqCount;
        vector<int> result;
        int n = nums.size();
        for(auto num : nums){
            freqCount[num]++;
        }
        for(auto num : freqCount){
            if(num.second > (n/3)){
                result.push_back(num.first);
            }
        }
        return result;
    }
};
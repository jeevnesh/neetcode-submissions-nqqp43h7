class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        vector<vector<int>> freqCount(nums.size()+1);
        for(auto i : nums){
            count[i]++;
        }
        for(auto i : count){
            freqCount[i.second].push_back(i.first);
        }
        vector<int> ans;
        for(int i = nums.size(); i >= 0; i--){
            if(ans.size() == k){
                return ans;
            }
            while(!freqCount[i].empty() && ans.size() < k){
                ans.push_back(freqCount[i].back());
                freqCount[i].pop_back();
            }
        }
        return ans;
    }
};

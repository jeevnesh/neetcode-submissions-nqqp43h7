class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int,int> freqMap;
        for(auto i : nums){
            freqMap[i]++;
        }
        vector<vector<int>> bucket(n+1);
        for(auto i : freqMap){
            bucket[i.second].push_back(i.first);
        }
        for(int i = n ; i > 0; i--){
            for(auto num : bucket[i]){
                ans.push_back(num);
                if(ans.size() == k){
                    return ans;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> freqMap;
        vector<pair<int,int>> freq;
        for(auto i : nums){
          freqMap[i]++;
        }
        for(auto i : freqMap){
            freq.push_back({i.second,i.first});
        }
        sort(freq.begin(),freq.end(),[](auto &a, auto &b){return a.first > b.first;});
        for(int i = 0 ; i < k; i++){
            ans.push_back(freq[i].second);
        }
        return ans;
    }
};

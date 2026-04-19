class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freqMap;
        for(auto i : nums){
            freqMap[i]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;
        for(auto i : freqMap){
            minHeap.push({i.second, i.first});
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }
        vector<int> ans;
        while(!minHeap.empty()){
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return ans;
    }
};

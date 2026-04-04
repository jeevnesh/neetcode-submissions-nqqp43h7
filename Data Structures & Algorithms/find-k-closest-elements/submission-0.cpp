class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //brute force we don't consider sorting of array here
        priority_queue<pair<int,int>> maxHeap;
        vector<int> ans;
        for(auto i : arr){
            maxHeap.push({abs(i-x),i});
            if(maxHeap.size() > k){
                maxHeap.pop();
            }
        }
        while(!maxHeap.empty()){
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }   
        sort(ans.begin(),ans.end());
        return ans;
    }
};
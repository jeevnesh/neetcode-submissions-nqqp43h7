class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        int j = 0, n = nums.size();
        while(j < n){
            //remove unwanted from back of the queue
            while(!dq.empty() && nums[dq.back()] < nums[j]){
                dq.pop_back();
            }
            dq.push_back(j);
            //remove from front those indices which are out of window 
            if(dq.front() < j-k+1){
                dq.pop_front();
            }
            //insert the max value for window in the ans
            if(j >= k-1){
                ans.push_back(nums[dq.front()]);
            }
            j++;
        }
        return ans;
    }
};

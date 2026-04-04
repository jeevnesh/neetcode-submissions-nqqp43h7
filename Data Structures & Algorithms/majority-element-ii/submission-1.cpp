class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int candidate1 = INT_MIN;
        int candidate2 = INT_MIN;
        int count1 = 0;
        int count2 = 0;
        for(int i = 0 ; i < n; i++){
            if(nums[i] == candidate1) count1++;
            else if(nums[i] == candidate2) count2++;
            else if(count1 == 0) {candidate1 = nums[i]; count1++;}
            else if(count2 == 0) {candidate2 = nums[i]; count2++;}
            else {count1--; count2--;}
        }
        int freq1 = 0;
        int freq2 = 0;
        for(auto num : nums){
            if(num == candidate1) freq1++;
            if(num == candidate2) freq2++;
        }
        if(freq1 > n/3) ans.push_back(candidate1);
        if(freq2 > n/3) ans.push_back(candidate2);
        return ans;
    }
};
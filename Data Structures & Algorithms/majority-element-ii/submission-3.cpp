class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2 = 0;
        int majority1 = 0, majority2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == majority1){
                count1++;
            }else if(nums[i] == majority2){
                count2++;
            }else if(count1 == 0){
                majority1 = nums[i];
                count1++;
            }else if(count2 == 0){
                majority2 = nums[i];
                count2++;
            }else{
                count1--;
                count2--;
            }
        }
        int n = nums.size();
        int majority1Count = 0, majority2Count = 0;
        for(auto i : nums){
            if(i == majority1) majority1Count++;
            if(i == majority2) majority2Count++;
        }
        vector<int> ans;
        if(majority1Count > n/3 ) ans.push_back(majority1);
        if(majority2Count > n/3 ) ans.push_back(majority2);
        return ans;
    }
};
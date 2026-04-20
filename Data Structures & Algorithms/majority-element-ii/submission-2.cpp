class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int majority1 = 0 , count1 = 0;
        int majority2 = 0, count2 = 0;
        for(auto i : nums){
            if(i == majority1){
                count1++;
            }else if(i == majority2){
                count2++;
            }else if(count1 == 0){
                majority1 = i;
                count1++;
            }else if(count2 == 0){
                majority2 = i;
                count2++;
            }else{
                count1--;
                count2--;
            }
        }
        vector<int> result;
        int freq1 = 0, freq2 = 0, n = nums.size();
        for(auto i : nums){
            if(i == majority1) freq1++;
            if(i == majority2) freq2++;
        }
        if(freq1 > n/3) result.push_back(majority1);
        if(freq2 > n/3) result.push_back(majority2);
        return result;
    }
};
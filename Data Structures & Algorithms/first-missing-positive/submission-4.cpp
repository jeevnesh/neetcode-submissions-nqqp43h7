class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<bool> present(n+1,false);
        for(auto i : nums){
            if(i >= 1 && i <= n){
                present[i] = true;
            }
        }
        for(int i = 1; i <= n; i++){
            if(!present[i]){
                return i;
            }
        }
        return n+1;
    }
};
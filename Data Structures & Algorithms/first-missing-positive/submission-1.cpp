class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int element = 1;
        while(true){
            bool flag = false;
            for(int num : nums){
                if(num == element){
                    flag = true;
                    break;
                }
            }
            if(flag == false) return element;
            element++;
        }
        return 0;
    }
};
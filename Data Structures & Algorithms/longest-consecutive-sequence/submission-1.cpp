class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_set<int> st;
        for(auto num : nums){
            st.insert(num);
        }
        int maxLen = 1;
        for(auto num : st){
            if(st.find(num - 1) != st.end()){
                continue;
            } else {
                int currLen = 1;
                while(st.find(num + 1) != st.end()){
                    currLen++;
                    num++;
                }
                maxLen = max(maxLen, currLen);
            }
        }
        return maxLen;
    }
};

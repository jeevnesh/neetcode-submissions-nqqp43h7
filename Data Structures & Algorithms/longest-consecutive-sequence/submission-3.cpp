class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(auto i : nums){
            st.insert(i);
        }
        int maxSeq = 0;
        for(auto num : st){
            if(st.find(num-1) == st.end()){
                int count = 1;
                while(st.find(num) != st.end()){
                    maxSeq = max(maxSeq,count);
                    num++;
                    count++;
                }
            } 
        }
        return maxSeq;
    }
};

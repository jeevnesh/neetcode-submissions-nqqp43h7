class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, n = s.size(), longest = 0;
        unordered_map<char,int> mpp;
        while(j<n){
            if(mpp.find(s[j]) != mpp.end() && mpp[s[j]] >= i){
                i = mpp[s[j]] + 1; 
            }
            mpp[s[j]] = j;
            longest = max(longest, j-i+1);
            j++;
        }
        return longest;
    }
};

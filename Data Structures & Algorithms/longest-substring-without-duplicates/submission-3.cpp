class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0, i = 0, j = 0;
        unordered_map<char,int> mpp;
        while(j < s.size()){
            if(mpp.find(s[j]) != mpp.end()){
                i = max(i, mpp[s[j]] + 1);
            }
            mpp[s[j]] = j;
            maxLength = max(maxLength, j-i+1);
            j++;
        }
        return maxLength;
    }
};

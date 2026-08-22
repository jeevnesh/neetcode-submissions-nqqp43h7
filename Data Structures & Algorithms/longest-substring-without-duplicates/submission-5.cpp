class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), i = 0, j = 0, maxLen = 0;
        unordered_map<char, int> mpp;
        while (j < n) {
            if (mpp.find(s[j]) != mpp.end()) {
                i = max(i, mpp[s[j]] + 1);
            }
            mpp[s[j]] = j;
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        return maxLen;
    }
};

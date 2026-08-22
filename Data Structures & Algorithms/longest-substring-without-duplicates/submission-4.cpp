class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), i = 0, j = 0, maxLen = 0;
        unordered_set<char> st;
        while (j < n) {
            while (st.count(s[j])) {
                st.erase(s[i]);
                i++;
            }
            st.insert(s[j]);
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        return maxLen;
    }
};

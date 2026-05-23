class Solution {
   public:
    bool isAnagram(string s, string t) {
        int n = s.size(), m = t.size();
        if (n != m) return false;
        vector<int> freqCount(26, 0);
        for (auto c : s) {
            freqCount[c - 'a']++;
        }
        for (auto c : t) {
            freqCount[c - 'a']--;
            if (freqCount[c - 'a'] < 0) return false;
        }
        return true;
    }
};

class Solution {
   public:
    string minWindow(string s, string t) {
        unordered_map<char, int> targetFreq;
        unordered_map<char, int> windowFreq;
        for (auto c : t) {
            targetFreq[c]++;
        }
        int need = targetFreq.size(), have = 0;
        int i = 0, j = 0, n = s.size();
        int minLength = INT_MAX, start = 0;
        while (j < n) {
            windowFreq[s[j]]++;
            if (targetFreq.count(s[j]) && windowFreq[s[j]] == targetFreq[s[j]]) {
                have++;
            }
            while(have == need){
                int windowSize = j-i+1;
                if(windowSize < minLength){
                    minLength = windowSize;
                    start = i;
                }
                windowFreq[s[i]]--;
                if(targetFreq.count(s[i]) && windowFreq[s[i]] < targetFreq[s[i]]){
                    have--;
                }
                i++;
            }
            j++;
        }
        return minLength == INT_MAX ? "" : s.substr(start,minLength);
    }
};

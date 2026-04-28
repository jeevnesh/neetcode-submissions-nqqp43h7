class Solution {
   public:
    int characterReplacement(string s, int k) {
        int i = 0, j = 0, maxFreq = 0, maxLength = 0;
        unordered_map<char, int> freq;
        while (j < s.size()) {
            freq[s[j]]++;
            maxFreq = max(maxFreq,freq[s[j]]);
            int windowSize = j-i+1;
            if(windowSize - maxFreq > k){
                freq[s[i]]--;
                i++;
            }
            maxLength = max(j-i+1, maxLength);
            j++;
        }
        return maxLength;
    }
};

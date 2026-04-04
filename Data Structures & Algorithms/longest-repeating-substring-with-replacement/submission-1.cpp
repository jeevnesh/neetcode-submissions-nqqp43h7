class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> freqCount;
        int i = 0, j = 0, n = s.size(), maxFreq = 0, ans = 1;
        while(j<n){
            freqCount[s[j]]++;
            maxFreq = max(maxFreq, freqCount[s[j]]);
            if(j-i+1 - maxFreq > k){
                freqCount[s[i]]--;
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};

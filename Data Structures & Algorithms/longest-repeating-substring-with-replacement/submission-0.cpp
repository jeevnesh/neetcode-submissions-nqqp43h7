class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(), i = 0, j = 0, ans = 0, maxFreq = 0;
        unordered_map<char,int> freq;
        while(j < n){
            freq[s[j]]++;
            maxFreq = max(maxFreq, freq[s[j]]);
            int windowSize = j-i+1;
            if(windowSize - maxFreq > k){
                freq[s[i]]--;
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};

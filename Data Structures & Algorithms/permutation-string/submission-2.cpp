class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mpp1;
        unordered_map<char, int> mpp2;
        int i = 0, j = 0, n = s1.size(), m = s2.size();
        for (int i = 0; i < n; i++) {
            mpp1[s1[i]]++;
        }
        while (j < m) {
            mpp2[s2[j]]++;
            if (j - i + 1 > n) {
                mpp2[s2[i]]--;
                if(mpp2[s2[i]] == 0) mpp2.erase(s2[i]);
                i++;
            } 
            if(j - i + 1 == n) {
                if (mpp1 == mpp2) return true;
            }
            j++;
        }
        return false;
    }
};

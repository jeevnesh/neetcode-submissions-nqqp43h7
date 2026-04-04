class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> target(26,0);
        vector<int> window(26,0);
        for(auto c : s1){
            target[c - 'a']++;
        }
        int i = 0, j = 0, n = s2.size(), m = s1.size();
        while(j < n){
            window[s2[j] - 'a']++;
            if(j-i+1 > m){
                window[s2[i] - 'a']--;
                i++;
            }
            if(j-i+1 == m && target == window){
                return true;
            }
            j++;
        }
        return false;
    }
};

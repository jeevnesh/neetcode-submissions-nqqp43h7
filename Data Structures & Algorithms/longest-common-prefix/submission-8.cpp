class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string ans;
        int n = strs.size();
        string s = strs[0];
        string t = strs[n-1];
        int size = s.size() < t.size() ? s.size() : t.size();
        for(int i = 0 ; i < size; i++){
            if(s[i] != t[i]){
                break;
            }
            ans += s[i];
        }
        return ans;
    }
};
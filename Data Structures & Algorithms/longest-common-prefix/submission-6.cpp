class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int n = strs.size();
        string ans;
        int len1 = strs[0].size();
        int len2 = strs[n-1].size();
        int i = 0;
        while(i < len1 && i < len2){
            if(strs[0][i] != strs[n-1][i]){
                return ans;
            }
            else{
                ans += strs[0][i];
                i++;
            }
        }
        return ans;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string res = "";
        int n = strs.size(), i = 0;
        while(i < strs[0].size() && i < strs[n-1].size()){
            if(strs[0][i] != strs[n-1][i]){
                return res;
            }
            res += strs[0][i];
            i++;
        }
        return res;
    }
};
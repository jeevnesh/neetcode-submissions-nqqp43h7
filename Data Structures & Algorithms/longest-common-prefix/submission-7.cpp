class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string minStr = strs[0];
        string maxStr = strs[0];
        for(int i = 1 ; i < strs.size(); i++){
            if(minStr > strs[i]) minStr = strs[i];
            if(maxStr < strs[i]) maxStr = strs[i];
        }
        string ans;
        int len1 = minStr.size();
        int len2 = minStr.size();
        int i = 0;
        while(i < len1 && i < len2){
            if(minStr[i] != maxStr[i]){
                return ans;
            }
            else{
                ans += minStr[i];
                i++;
            }
        }
        return ans;
    }
};
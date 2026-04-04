class Solution {
private:
    string compare(string& prefix, string& str){
        int i = 0;
        while(i < prefix.size() && i < str.size() && prefix[i] == str[i]){
            i++;
        }
        return prefix.substr(0,i);
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        int n = strs.size();
        string minStr = strs[0];
        string maxStr = strs[0];
        for(int i = 1; i < n; i++){
            if(minStr > strs[i]) minStr = strs[i];
            if(maxStr < strs[i]) maxStr = strs[i];
        }
        return compare(minStr, maxStr);
    }
};
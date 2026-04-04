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
        sort(strs.begin(), strs.end());
        return compare(strs[0], strs[n-1]);
    }
};
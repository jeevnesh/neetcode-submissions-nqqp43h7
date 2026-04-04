class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n == 0) return "";
        string ans = "";
        int i = 0;
        while(true){
           char c = strs[0][i];
           for(auto str : strs){
            if(i >= str.size()){
                return ans;
            }
            if(c != str[i]){
                return ans;
            }
           }
            ans.push_back(c);
            i++;
        }
        return ans;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n == 0) return "";
        int upperBound = INT_MAX;
        string ans = "";
        for(int i = 0 ; i < n; i++){
            int n = strs[i].length();
            if(n < upperBound) upperBound = n;
        }
        for(int i = 0; i < upperBound; i++){
            char c = strs[0][i];
            for(auto str : strs){
                if(str[i] != c){
                    return ans;
                }
            }
            ans.push_back(c);
        }
        return ans;
    }
};
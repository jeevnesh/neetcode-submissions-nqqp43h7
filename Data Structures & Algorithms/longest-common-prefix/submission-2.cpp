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
        string prefix = strs[0];
        for(int i = 1 ; i < strs.size(); i++){
            if(prefix.size()){
                prefix = compare(prefix, strs[i]);
            }else{
                return "";
            }
        }
        return prefix;
    }
};
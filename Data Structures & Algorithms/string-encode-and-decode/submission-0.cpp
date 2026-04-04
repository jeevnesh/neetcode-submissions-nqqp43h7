class Solution {
public:

    string encode(vector<string>& strs) {
        string str = "";
        for(auto i : strs){
            str += i + "-";
        }
        decode(str);
        return str;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        string str = "";
        for(auto c : s){
            if(c == '-'){
                ans.push_back(str);
                str = "";
            }else{
                str += c;
            }
        }
        return ans;
    }
};

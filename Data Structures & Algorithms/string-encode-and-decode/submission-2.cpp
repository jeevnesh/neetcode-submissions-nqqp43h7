class Solution {
public:

    string encode(vector<string>& strs) {
        string str = "";
        for(auto &s : strs){ 
            str += to_string(s.size()) + "#" + s;
        }
        decode(str);
        return str;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        while(i < s.size()){
            int len = 0;
            string numStr = "";
            while(s[i] != '#'){
                numStr += s[i]; 
                i++;
            }
            len = stoi(numStr);
            i++;
            string str = s.substr(i,len);
            ans.push_back(str);
            i += len;
        }
        return ans;
    }
};

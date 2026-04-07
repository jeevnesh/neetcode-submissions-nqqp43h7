class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string result = "";
        stringstream ss(path);
        string token;
        while(getline(ss,token,'/')){
            if(token == "" || token == "."){
                continue;
            }else if(token == ".."){
                if(!st.empty()){
                    st.pop_back();
                }
            }else{
                st.push_back(token);
            }
        }
        for(auto &dir : st){
            result += "/"+ dir;
        }
        if(result == "") return "/";
        return result;
    }
};
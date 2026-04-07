class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string result = "";
        stringstream ss(path);
        string token;
        while(getline(ss,token,'/')){
            if(token == "" || token == "."){
                continue;
            }else if(token == ".."){
                if(!st.empty()){
                    st.pop();
                }
            }else{
                st.push(token);
            }
        }
        //reverse the order
        stack<string> temp;
        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }
        while(!temp.empty()){
            result += "/"+ temp.top();
            temp.pop();
        }
        if(result == "") return "/";
        return result;
    }
};
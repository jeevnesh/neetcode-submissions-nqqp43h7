class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int result = 0;
        for(auto i : tokens){
            if(i != "+" && i != "-" && i != "*" && i != "/"){
                st.push(stoi(i));
            }else if(i == "+"){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                result = num2 + num1;
                st.push(result);
            }else if(i == "-"){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                result = num2 - num1;
                st.push(result);
            }else if(i == "*"){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                result = num2 * num1;
                st.push(result);
            }else if(i == "/"){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                result = num2 / num1;
                st.push(result);
            }
        }
        return st.top();
    }
};

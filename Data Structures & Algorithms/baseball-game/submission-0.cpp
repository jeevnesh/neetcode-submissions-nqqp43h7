class Solution {
public:
    int calPoints(vector<string>& operations) {
       stack<int> st;
       int sum = 0;
       for(auto c : operations){
        if(c != "C" && c != "D" && c != "+"){
            int num = stoi(c);
            st.push(num);
            sum += st.top();
        }
        else if(c == "+"){
            int num1 = st.top();
            st.pop();
            int num2 = st.top();
            st.push(num1);
            int sumLastTwo = num1 + num2;
            st.push(sumLastTwo); 
            sum += st.top();
        }
        else if(c == "C"){
            sum -= st.top();
            st.pop();
        }
        else if(c == "D"){
            int num = st.top();
            int newNum = 2*num;
            st.push(newNum);
            sum += st.top();
        }
       }
       return sum;
    }
};
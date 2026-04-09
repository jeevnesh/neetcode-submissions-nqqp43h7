class Solution {
public:
    string decodeString(string s) {
      stack<int> numStack;
      stack<string> strStack;
      string curr = "";
      int num = 0;
      for(auto c : s){
        if(isdigit(c)){
            num = num * 10 + (c - '0');
        }else if(c == '['){
            strStack.push(curr);
            numStack.push(num);
            curr = "";
            num = 0;
        }else if(c == ']'){
            int repeat = numStack.top();
            numStack.pop();
            string prev = strStack.top();
            strStack.pop();
            string temp = "";
            for(int i = 0; i < repeat; i++){
                temp += curr;
            }
            curr = prev + temp;
        }else{
            curr += c;
        }
      }
      return curr;
    }
};
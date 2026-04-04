class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> result;
        for(auto i : asteroids){
            bool destroyed = false;
            if(st.empty()){
                st.push(i);
            }else if(st.top() > 0 && i < 0){
                while(!st.empty() && st.top() > 0 && i < 0){
                    if(abs(st.top()) < abs(i)){
                        st.pop();
                    }else if(abs(st.top()) == abs(i)){
                        st.pop();
                        destroyed = true;
                        break;
                    }else{
                        destroyed = true;
                        break;
                    }
                }
                if(!destroyed){
                    st.push(i);
                }
            }else{
                st.push(i);
            }
        }
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
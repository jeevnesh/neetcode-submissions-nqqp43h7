class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // brute force
        vector<int> ans;
        int n = temperatures.size();
        for(int i = 0; i < n; i++){
            bool found = false;
            for(int j = i+1; j < n; j++){
                if(temperatures[j] > temperatures[i]){
                    ans.push_back(j-i);
                    found = true;
                    break;
                }
            }
            if(!found){
                ans.push_back(0);
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;
        vector<vector<string>> ans;
        for(auto &str : strs){
            vector<int> arr(26,0);
            for(auto i : str){
                arr[i - 'a']++;
            }
            string tempStr = "";
            for(auto i : arr){
                tempStr += to_string(i) + "-";
            }
            mpp[tempStr].push_back(str);
        }
        for(auto i : mpp){
            ans.push_back(i.second);
        }
        return ans;
    }
};


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mpp;
        for(auto &str: strs){
            vector<int> keyArr(26,0);
            for(auto c : str){
                keyArr[c - 'a']++;
            }
            string keys = "";
            for(int i = 0 ; i < 26; i++){
                keys += keyArr[i] + '#';
            }
            mpp[keys].push_back(str);
        }
        for(auto &[key, value] : mpp){
            ans.push_back(value);
        }
        return ans;
    }
};

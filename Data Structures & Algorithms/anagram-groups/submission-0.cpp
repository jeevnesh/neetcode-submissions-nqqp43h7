class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> anagramMap;
        for(int i = 0 ; i < strs.size(); i++){
            string tempStr = strs[i];
            sort(tempStr.begin(), tempStr.end());
            anagramMap[tempStr].push_back(strs[i]);
        }
        for(const auto &[key,value] : anagramMap){
            ans.push_back(value);
        }
        return ans;
    }
};

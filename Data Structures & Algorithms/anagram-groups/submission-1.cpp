class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> anagramMap;
        for(const auto& str : strs){
            vector<int> keyArr(26,0);
            for(int i = 0; i < str.size(); i++){
                keyArr[str[i] - 'a']++;
            }
            string keys = "";
            for(int i = 0; i < 26; i++){
                keys += to_string(keyArr[i]) + '#';
            }
            anagramMap[keys].push_back(str);
        }
        for(const auto &[key,value] : anagramMap){
            ans.push_back(value);
        }
        return ans;
    }
};

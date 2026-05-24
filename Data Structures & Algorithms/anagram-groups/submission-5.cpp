class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;
        vector<vector<string>> ans;
        for (auto s : strs) {
            vector<int> charMap(26, 0);
            for (auto c : s) {
                charMap[c - 'a']++;
            }
            string key = "";
            for (int i = 0; i < 26; i++) {
                key += to_string(charMap[i]) + "#";
            }
            mpp[key].push_back(s);
        }
        for (auto s : mpp) {
            ans.push_back(s.second);
        }
        return ans;
    }
};

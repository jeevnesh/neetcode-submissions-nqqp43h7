class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mpp;
        for (auto str : strs) {
            string temp = str;
            sort(temp.begin(), temp.end());
            mpp[temp].push_back(str);
        }
        for (auto i : mpp) {
            ans.push_back(i.second);
        }
        return ans;
    }
};

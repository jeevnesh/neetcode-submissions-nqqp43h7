class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mpp;
        for (auto str : strs) {
            vector<int> arr(26,0);
            for(auto c : str){
                arr[c-'a']++;
            }
            string key = "";
            for(int i = 0; i < 26; i++){
                key += to_string(arr[i]) + "#";
            }
            mpp[key].push_back(str);
        }
        for (auto i : mpp) {
            ans.push_back(i.second);
        }
        return ans;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> arr(26,0);
        for(auto c : s){
            arr[c - 'a']++;
        }
        for(auto c : t){
            arr[c - 'a']--;
        }
        for(int i = 0 ; i < 26; i++){
            if(arr[i] != 0){
                return false;
            }
        }
        return true;
    }
};

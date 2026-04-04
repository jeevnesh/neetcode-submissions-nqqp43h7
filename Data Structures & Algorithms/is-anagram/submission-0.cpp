class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        int n = s.length();
        unordered_map<char, int> countWord;
        for(char word : s){
            countWord[word]++;
        }
        for(char word : t){
            if(countWord[word]){
                countWord[word]--;
            }else{
                return false;
            }
        }
        return true;
    }
};

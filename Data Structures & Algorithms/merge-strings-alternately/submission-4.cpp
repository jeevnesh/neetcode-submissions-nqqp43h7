class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        int i = 0, j = 0, n = word1.size(), m = word2.size();
        while(i < n && j < m){
            result.push_back(word1[i++]);
            result.push_back(word2[j++]);
        }
        while(i < n){
            result.push_back(word1[i++]);
        }
        while(j < m){
            result.push_back(word2[j++]);
        }
        return result;
    }
};
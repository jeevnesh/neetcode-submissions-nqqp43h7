class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0, j = 0 , n1 = word1.size(), n2 = word2.size();
        if(n1 == 0) return word2;
        if(n2 == 0) return word1;
        string merged;
        while(i < n1 && j < n2){
            merged += word1[i];
            merged += word2[j];
            i++;
            j++;
        }
        while(i < n1){
            merged += word1[i];
            i++;
        }
        while(j < n2){
            merged += word2[j];
            j++;
        }
        return merged;
    }
};
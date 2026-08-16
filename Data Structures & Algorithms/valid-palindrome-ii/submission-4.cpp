class Solution {
   private:
    bool isPalindrom(string& s, int start, int end){
        while(start < end){
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
   public:
    bool validPalindrome(string s) {
        int i = 0, j = s.size() - 1, count = 0;
        while (i < j) {
            if(s[i] == s[j]){
                i++;
                j--;
            }else if(s[i] != s[j] && count == 0){
                count++;
                return ( isPalindrom(s, i+1, j) || isPalindrom(s, i, j-1) );
            }
        }
        return true;
    }
};
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> target;
        unordered_map<char,int> window;
        for(auto c : t){
            target[c]++;
        }
        int i = 0, j = 0, n = s.size(), formed = 0, reached = target.size();
        int minLength = INT_MAX, start = 0;
        while(j<n){
            window[s[j]]++;
            if(target.find(s[j]) != target.end() && window[s[j]] == target[s[j]]){
                formed++;
            }
            while(formed == reached){
                int windowSize = j-i+1;
                if(windowSize < minLength){
                    minLength = windowSize;
                    start = i;
                }
                window[s[i]]--;
                if(target.find(s[i]) != target.end() && window[s[i]] < target[s[i]]){
                    formed--;
                }
                i++;
            }
            j++;
        }
        if(minLength == INT_MAX) return "";
        return s.substr(start,minLength);
    }
};

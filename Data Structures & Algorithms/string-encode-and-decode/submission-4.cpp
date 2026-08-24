class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedStr = "";
        for(auto str : strs){
            int n = str.size();
            encodedStr += to_string(n) + "#" + str;
        }
        decode(encodedStr);
        return encodedStr;
    }

    vector<string> decode(string s) {
        vector<string> decodedStr;
        int i = 0, n = s.size();
        while(i < n){
            string numSize = "";
            while(s[i] != '#'){
                numSize += s[i];
                i++;
            }
            i++;
            int size = stoi(numSize);
            string word = s.substr(i,size);
            decodedStr.push_back(word);
            i = i + size;
        }
        return decodedStr;
    }
};

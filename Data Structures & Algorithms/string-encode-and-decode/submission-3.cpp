class Solution {
   public:
    string encode(vector<string>& strs) {
        string encodedStr = "";
        for (auto s : strs) {
            encodedStr += to_string(s.size()) + "#" + s;
        }
        decode(encodedStr);
        return encodedStr;
    }

    vector<string> decode(string s) {
        vector<string> decodedStr;
        int i = 0;
        while (i < s.size()) {
            string numStr = "";
            while (s[i] != '#') {
                numStr += s[i];
                i++;
            }
            int len = stoi(numStr);
            i++;
            decodedStr.push_back(s.substr(i, len));
            i += len;
        }
        return decodedStr;
    }
};

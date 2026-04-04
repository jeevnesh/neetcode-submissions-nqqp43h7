// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    void modifyPairs(vector<Pair>& pairs, int start, int end){
            for(int i = start+1 ; i < end; i++){
                int key = pairs[i].key;
                string value = pairs[i].value;
                int j = i-1;
                while(j >= 0 && pairs[j].key > key){
                    pairs[j+1].key = pairs[j].key;
                    pairs[j+1].value = pairs[j].value;
                    j--;
                }
                pairs[j+1].key = key;
                pairs[j+1].value = value;
            }
    }
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        vector<vector<Pair>> ans;
        int n = pairs.size();
        for(int i = 1 ; i <= n; i++){
            //modify pairs 
            modifyPairs(pairs,0,i);
            //push back pairs to ans
            ans.push_back(pairs);
        }
        return ans;
    }
};

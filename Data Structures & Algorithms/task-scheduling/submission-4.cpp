class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> freqMap;
        for(auto i : tasks){
            freqMap[i]++;
        }
        int totalNumberWithMaxFreq = 0, maxFreqNum = 0;
        for(auto i : freqMap){
            if(i.second > maxFreqNum){
                maxFreqNum = i.second;
            }
        }
        for(auto i :freqMap){
            if(i.second == maxFreqNum){
                totalNumberWithMaxFreq++;
            }
        }
        int ans = (maxFreqNum - 1) * (n+1) + totalNumberWithMaxFreq;
        return max((int)tasks.size(),ans);
    }
};

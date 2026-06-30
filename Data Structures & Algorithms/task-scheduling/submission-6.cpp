class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> tasksFreq;
        for (auto i : tasks) {
            tasksFreq[i]++;
        }
        // find the maxFreq
        int maxFreq = 0;
        for (auto i : tasksFreq) {
            if (i.second > maxFreq) {
                maxFreq = i.second;
            }
        }
        // find total number of task with maxFreq
        int totalMaxFreqTask = 0;
        for (auto i : tasksFreq) {
            if (i.second == maxFreq) {
                totalMaxFreqTask++;
            }
        }
        int ans = (maxFreq - 1) * (n + 1) + totalMaxFreqTask;
        return max((int)tasks.size(), ans);
    }
};

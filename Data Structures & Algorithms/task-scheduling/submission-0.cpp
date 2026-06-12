#include<bits/stdc++.h>
#include<math.h>
class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        // highly specific formula for this problem only
        // count the frequency of tasks
        unordered_map<char, int> maxFreq;
        for (auto c : tasks) {
            maxFreq[c]++;
        }
        // find the max frequency
        int maxFreqNum = 0;
        for (auto i : maxFreq) {
            if (i.second > maxFreqNum) {
                maxFreqNum = i.second;
            }
        }
        // find the number of tasks with maxFreq
        int totalMaxFreqTasks = 0;
        for (auto i : maxFreq) {
            if (i.second == maxFreqNum) {
                totalMaxFreqTasks++;
            }
        }
        int taskSize = tasks.size();
        int ans = max(taskSize, ((maxFreqNum - 1) * (n + 1) + totalMaxFreqTasks));
        return ans;
    }
};

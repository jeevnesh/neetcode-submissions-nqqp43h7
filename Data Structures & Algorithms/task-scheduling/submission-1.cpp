class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> taskCount;
        for (auto i : tasks) {
            taskCount[i]++;
        }
        priority_queue<int> maxHeap;
        for (auto i : taskCount) {
            maxHeap.push({i.second});
        }
        queue<pair<int, int>> cooldownQueue;  //{remainingTasks,cooldownTime}
        int time = 0;
        while (!maxHeap.empty() || !cooldownQueue.empty()) {
            time++;
            if(!cooldownQueue.empty()){
                int cooldownTime = cooldownQueue.front().second;
                if(cooldownTime == time){
                    maxHeap.push({cooldownQueue.front().first});
                    cooldownQueue.pop();
                }
            }
            if(!maxHeap.empty()){
                int top = maxHeap.top();
                maxHeap.pop();
                top--;
                if(top > 0){
                    cooldownQueue.push({top,time+n+1});
                }
            }
        }
        return time;
    }
};

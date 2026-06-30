class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> taskFreq;
        for(auto i : tasks){
            taskFreq[i]++;
        }
        priority_queue<int> remTask;
        for(auto i : taskFreq){
            remTask.push(i.second);
        }
        int time = 0;
        queue<pair<int,int>> waitQueue;  //{nextAvailableTime,remTaskNum}
        while(!remTask.empty() || !waitQueue.empty()){
            if(remTask.empty()){
                time = waitQueue.front().first;
            }else{
                time++;
            }
            //process task from heap
            if(!remTask.empty()){
                int top = remTask.top();
                top--;
                remTask.pop();
                if(top > 0){
                    waitQueue.push({time+n,top});
                }
            }
            //fill the task in Heap if it's cooldown period is over
            if(!waitQueue.empty() && time >= waitQueue.front().first){
                remTask.push(waitQueue.front().second);
                waitQueue.pop();
            }
        }
        return time;
    }
};

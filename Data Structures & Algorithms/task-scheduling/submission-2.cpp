class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //calculate the frequency
        unordered_map<char,int> taskFreq;
        for(auto i : tasks){
            taskFreq[i]++;
        }
        //put this task frequency in a max heap
        priority_queue<int> maxHeap;
        for(auto i : taskFreq){
            maxHeap.push(i.second);
        }
        //create a queue to park waiting task {timeToUnlock,taskRemaining}
        queue<pair<int,int>> q;
        int time = 0;
        while(!maxHeap.empty() || !q.empty()){
            time++;
            if(!q.empty()){
                if(q.front().first == time){
                    maxHeap.push(q.front().second);
                    q.pop();
                }
            }
            if(!maxHeap.empty()){
                int top = maxHeap.top();
                maxHeap.pop();
                top--;
                if(top > 0){
                    q.push({time+n+1,top});
                }
            }
        }
        return time;
    }
};

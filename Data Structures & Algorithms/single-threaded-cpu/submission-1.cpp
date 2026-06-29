class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> ans;
        //modify the tasks to include indexes
        vector<pair<vector<int>,int>> tasksIdx;
        for(int i = 0; i < tasks.size(); i++){
            tasksIdx.push_back({tasks[i],i});   //{{enqueuTime,processingTime},index}
        }
        //sort the tasksIdx based on enqueuTime
        sort(tasksIdx.begin(), tasksIdx.end());
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap; //{processingTime, index}
        int time = 0, i = 0;
        while(i < tasksIdx.size() || !minHeap.empty()){
            if(minHeap.empty() && time < tasksIdx[i].first[0]){
                time = tasksIdx[i].first[0];
            }
            while(i < tasksIdx.size() && tasksIdx[i].first[0] <= time){
                minHeap.push({tasksIdx[i].first[1],tasksIdx[i].second});
                i++;
            }
            pair<int,int> top = minHeap.top();
            minHeap.pop();
            ans.push_back(top.second);
            time += top.first;
        }
        return ans;
    }
};
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int,vector<int>> pq;
        for(auto stone : stones){
            pq.push(stone);
        }
        while(pq.size() > 1){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            int diff = x < y ? y-x : x-y;
            if(diff){
                pq.push(diff);
            }
        }
        int ans = pq.size() == 1 ? pq.top() : 0;
        return ans;
    }
};

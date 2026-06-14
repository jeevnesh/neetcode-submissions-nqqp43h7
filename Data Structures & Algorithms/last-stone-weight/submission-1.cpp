class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto stone : stones){
            pq.push(stone);
        }
        while(pq.size() > 1){
            int stone1 = pq.top();
            pq.pop();
            int stone2 = pq.top();
            pq.pop();
            int diff = stone1 - stone2;
            if(diff){
                pq.push(diff);
            }
        }
        return pq.size() == 1 ? pq.top() : 0;
    }
};

class Twitter {
   private:
    unordered_map<int, unordered_set<int>>
        followerMap;  //{followerID : {followeeId,followeeId,...}}
    int time = 0;
    unordered_map<int, vector<pair<int, int>>> tweetMap;  //{userId : {time, tweetId}}
   public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        time++;
        tweetMap[userId].push_back({time, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        priority_queue<pair<int, int>> maxHeap;  //{time,tweetId}
        // find all followeeId user follows
        for (auto followeeId : followerMap[userId]) {
            // find all tweets posted by that particular followeeId
            for (auto tweets : tweetMap[followeeId]) {
                // add them in maxHeap heapify by time
                maxHeap.push(tweets);
            }
        }
        // find all tweets psoted by user himself
        for (auto tweets : tweetMap[userId]) {
            // add them in maxHeap heapify by time
            maxHeap.push(tweets);
        }
        // now put at max 10 tweetsId in the answer based on time which is already sorted by heap
        while (!maxHeap.empty()) {
            ans.push_back(maxHeap.top().second);
            if (ans.size() == 10) {
                break;
            }
            maxHeap.pop();
        }
        return ans;
    }

    void follow(int followerId, int followeeId) { 
        if(followerId == followeeId) return;
        followerMap[followerId].insert(followeeId); 
    }

    void unfollow(int followerId, int followeeId) {
        if (followerMap[followerId].find(followeeId) != followerMap[followerId].end()) {
            followerMap[followerId].erase(followeeId);
        }
    }
};

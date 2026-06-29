class Twitter {
    unordered_map<int, unordered_set<int>> followerMap;  //{followerId, followeeId}
    unordered_map<int, vector<pair<int, int>>> tweetMap;
    int time = 0;

   public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        time++;
        tweetMap[userId].push_back({time, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        priority_queue<pair<int, int>> maxHeap;
        for (auto followeeId : followerMap[userId]) {
            int count = 0;
            for (int i = tweetMap[followeeId].size() - 1; i >= 0 && count < 10; i--) {
                count++;
                maxHeap.push(tweetMap[followeeId][i]);
            }
        }
        int userTweet = 0;
        for (int i = tweetMap[userId].size() - 1; i >= 0 && userTweet < 10; i--) {
            userTweet++;
            maxHeap.push(tweetMap[userId][i]);
        }

        while (!maxHeap.empty() && ans.size() < 10) {
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return ans;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            followerMap[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        if (followerMap[followerId].find(followeeId) != followerMap[followerId].end()) {
            followerMap[followerId].erase(followeeId);
        }
    }
};

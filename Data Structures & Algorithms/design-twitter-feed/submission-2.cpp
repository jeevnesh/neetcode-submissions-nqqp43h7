//better approach becasue getNewsFeed() is not optimised yet O(M log M + 10 log M) = O(M log M)
class Twitter {
   private:
    unordered_map<int, unordered_set<int>> followeeMap;  //{followerId : {followeeId,followeeId,...}}
    int time = 0;
    unordered_map<int, vector<pair<int, int>>> tweets;  //{userId : {{time,tweetId}, {time,tweetId}, ...}}
    public : Twitter() {}

    void postTweet(int userId, int tweetId) {
        time++;
        tweets[userId].push_back({time,tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        priority_queue<pair<int,int>> maxHeap; //{time,tweetId}
        //find all followeeId user follows
        for(auto followeeId : followeeMap[userId]){
            //find all tweets followeeId posted and push into maxHeap
            for(auto tweet : tweets[followeeId]){
                maxHeap.push(tweet);
            }
        }
        //find all tweets userId posted and push into maxHeap
        for(auto tweet : tweets[userId]){
            maxHeap.push(tweet);
        }
        //loop through maxHeap untill all the tweets consumed or at max 10 tweets consume
        while(!maxHeap.empty() && ans.size() < 10){
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return ans;
    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        followeeMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followeeMap[followerId].find(followeeId) != followeeMap[followerId].end()) {
            followeeMap[followerId].erase(followeeId);
        }
    }
};

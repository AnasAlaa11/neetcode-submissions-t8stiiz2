class Twitter {
private:
    int clock;
    unordered_map<int, unordered_set<int>> user_follower;
    unordered_map<int, vector<pair<int, int>>> user_posts;

public:
    Twitter() {
        clock = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        user_posts[userId].push_back({clock, tweetId});
        clock++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int n = user_posts[userId].size();
        for (int i = n - 1; i >= max(0, n - 10); i--) {
            pq.push(user_posts[userId][i]);
            if (pq.size() > 10) pq.pop();
        }
        if (user_follower.count(userId)) {
            for (int followeeId : user_follower[userId]) {
                int m = user_posts[followeeId].size();
                for (int i = m - 1; i >= max(0, m - 10); i--) {
                    pq.push(user_posts[followeeId][i]);
                    if (pq.size() > 10) pq.pop();
                }
            }
        }
        vector<int> feed;
        while (!pq.empty()) {
            feed.push_back(pq.top().second);
            pq.pop();
        }
        reverse(feed.begin(), feed.end());
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            user_follower[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        user_follower[followerId].erase(followeeId);
    }
};

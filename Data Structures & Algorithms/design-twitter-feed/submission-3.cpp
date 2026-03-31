class Twitter {
public:
    Twitter() {
        timeCount = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back(tweetId);
        timestamp[tweetId] = timeCount;
        timeCount++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> news;
        auto cmp = [&](pair<int, int> left, pair<int, int> right) {
            return timestamp[tweets[left.first][left.second]] < timestamp[tweets[right.first][right.second]];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp); // <userId, index>

        followList[userId].insert(userId);
        
        for (int followeeId:followList[userId])
            if (!tweets[followeeId].empty()) {
                pq.push({followeeId, tweets[followeeId].size()-1});
            }

        while (!pq.empty() && news.size() < 10) {
            auto m = pq.top();
            pq.pop();
            news.push_back(tweets[m.first][m.second]);

            if (m.second-1 >= 0) pq.push({m.first, m.second - 1});
        }

        return news;
    }
    
    void follow(int followerId, int followeeId) {
        followList[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followList[followerId].erase(followeeId);
    }
private:
    unordered_map<int, unordered_set<int>> followList;
    unordered_map<int, vector<int>> tweets;
    unordered_map<int, int> timestamp;
    int timeCount;
};

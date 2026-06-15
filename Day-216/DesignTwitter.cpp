class Twitter {
public:
    class Twitte {
        public:
            int tId;
            int time;

            Twitte(int id, int t) : tId(id), time(t) {};
    };

    unordered_map<int, vector<Twitte>> posts;
    unordered_map<int, vector<int>> following;
    int time;

    class cmp {
        public:
            bool operator()(Twitte& a, Twitte& b) {
                return a.time > b.time;
            }
    };

    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back(Twitte(tweetId, time++));
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<Twitte, vector<Twitte>, cmp> minHeap;

        // top post from user itself
        vector<Twitte> userTwt = posts[userId];
        for(auto twt : userTwt) {
            minHeap.push(twt);
            if(minHeap.size() > 10) minHeap.pop();
        }

        //top post from user's followings
        vector<int> fwing = following[userId];
        for(int fwingId : fwing) {
            userTwt = posts[fwingId];

            for(auto twt: userTwt) {
                minHeap.push(twt);
                if(minHeap.size() > 10) minHeap.pop();
            }
        }

        vector<int> newsFeedTopPost;
        while(!minHeap.empty()) {
            Twitte topE = minHeap.top();
            minHeap.pop();
            newsFeedTopPost.push_back(topE.tId);
        }

        reverse(newsFeedTopPost.begin(), newsFeedTopPost.end()); // making it in decreasing order cause we want top most first
        return newsFeedTopPost;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        if(find(following[followerId].begin(), following[followerId].end(), followeeId) == following[followerId].end())
            following[followerId].push_back(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        vector<int>& v = following[followerId];
        auto it = find(v.begin(), v.end(), followeeId);

        if(it !=  v.end()) v.erase(it);
    }
};




#include <stdlib.h>
#include <stdbool.h>

#define MAX_USERS 501
#define MAX_TWEETS 50001
#define FEED_SIZE 10

typedef struct {
    int tweetId;
    int userId;
    int time;
} Tweet;

typedef struct {
    bool following[MAX_USERS][MAX_USERS];
    Tweet tweets[MAX_TWEETS];
    int tweetCount;
    int time;
} Twitter;

Twitter* twitterCreate() {
    Twitter* obj = (Twitter*)calloc(1, sizeof(Twitter));
    return obj;
}

void twitterPostTweet(Twitter* obj, int userId, int tweetId) {
    if (obj->tweetCount >= MAX_TWEETS) return;

    Tweet* t = &obj->tweets[obj->tweetCount++];
    t->tweetId = tweetId;
    t->userId = userId;
    t->time = ++obj->time;
}

int* twitterGetNewsFeed(Twitter* obj, int userId,
                        int* retSize) {
    int* feed = (int*)malloc(FEED_SIZE * sizeof(int));
    *retSize = 0;

    // Scan tweets from newest to oldest
    for (int i = obj->tweetCount - 1;
         i >= 0 && *retSize < FEED_SIZE; i--) {

        int author = obj->tweets[i].userId;

        if (author == userId ||
            obj->following[userId][author]) {
            feed[(*retSize)++] = obj->tweets[i].tweetId;
        }
    }

    return feed;
}

void twitterFollow(Twitter* obj, int followerId,
                   int followeeId) {
    if (followerId == followeeId) return;

    obj->following[followerId][followeeId] = true;
}

void twitterUnfollow(Twitter* obj, int followerId,
                     int followeeId) {
    if (followerId == followeeId) return;

    obj->following[followerId][followeeId] = false;
}

void twitterFree(Twitter* obj) {
    free(obj);
}





#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 2001
#define MAX_ID_LEN 101

typedef struct {
    char tokenId[MAX_TOKENS][MAX_ID_LEN];
    int expiry[MAX_TOKENS];
    int count;
    int ttl;
} AuthenticationManager;

AuthenticationManager* authenticationManagerCreate(int timeToLive) {
    AuthenticationManager* obj =
        (AuthenticationManager*)malloc(sizeof(AuthenticationManager));

    obj->count = 0;
    obj->ttl = timeToLive;

    return obj;
}

int findToken(AuthenticationManager* obj, char* tokenId) {
    for (int i = 0; i < obj->count; i++) {
        if (strcmp(obj->tokenId[i], tokenId) == 0) {
            return i;
        }
    }
    return -1;
}

void authenticationManagerGenerate(AuthenticationManager* obj,
                                   char* tokenId, int currentTime) {
    int i = findToken(obj, tokenId);

    if (i == -1) {
        i = obj->count++;
        strcpy(obj->tokenId[i], tokenId);
    }

    obj->expiry[i] = currentTime + obj->ttl;
}

void authenticationManagerRenew(AuthenticationManager* obj,
                                char* tokenId, int currentTime) {
    int i = findToken(obj, tokenId);

    if (i != -1 && obj->expiry[i] > currentTime) {
        obj->expiry[i] = currentTime + obj->ttl;
    }
}

int authenticationManagerCountUnexpiredTokens(AuthenticationManager* obj,
                                              int currentTime) {
    int count = 0;

    for (int i = 0; i < obj->count; i++) {
        if (obj->expiry[i] > currentTime) {
            count++;
        }
    }

    return count;
}

void authenticationManagerFree(AuthenticationManager* obj) {
    free(obj);
}

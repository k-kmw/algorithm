#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int id;
    int v;
    Node* nxt;

    Node() {}

    Node(int id, Node* nxt) {
        this->id = id;
        this->nxt = nxt;
    }

    Node(int id, int v, Node* nxt) {
        this->id = id;
        this->v = v;
        this->nxt = nxt;
    }
};

Node node[200005];
int cnt = 0;
int version[100005];
int tId[100005];

Node* getNewNode(int id, Node* nxt) {
    node[cnt].id = id;
    node[cnt].nxt = nxt;
    node[cnt].v = ++version[id];
    return &node[cnt++];
}

class Team {
public:
    Node* head[6];
    Node* tail[6];
};

Team team[6];

void init()
{
    cnt = 0;
    fill(version, version+100005, 0);
    fill(tId, tId+100005, 0);
    for(int i=0; i<200005; i++){
        node[i] = Node();
    }
    for(int i=1; i<=5; i++) {
        team[i] = Team();
        for (int j = 1; j <= 5; j++) {
            team[i].tail[j] = team[i].head[j] = getNewNode(0, nullptr);
        }
    }
}

void hire(int mID, int mTeam, int mScore)
{
    Node* newNode = getNewNode(mID, nullptr);
    team[mTeam].tail[mScore]->nxt = newNode;
    team[mTeam].tail[mScore] = newNode;
    tId[mID] = mTeam;
}

void fire(int mID)
{
    version[mID] = -1;
}

void updateSoldier(int mID, int mScore)
{
    hire(mID, tId[mID], mScore);
}

void updateTeam(int mTeam, int mChangeScore)
{
    if(mChangeScore > 0) {
        for(int i=5; i>=1; i--) {
            int k = i + mChangeScore;
            k = (k > 5) ? 5 : k;
            if(k == i)  continue;
            if(team[mTeam].head[i]->nxt == nullptr) continue;
            team[mTeam].tail[k]->nxt = team[mTeam].head[i]->nxt;
            team[mTeam].tail[k] = team[mTeam].tail[i];
            team[mTeam].head[i]->nxt = nullptr;
            team[mTeam].tail[i] = team[mTeam].head[i];
        }
    } else if(mChangeScore < 0) {
        for(int i=1; i<=5; i++) {
            int k = i + mChangeScore;
            k = (k < 1) ? 1 : k;
            if(k == i)  continue;
            if(team[mTeam].head[i]->nxt == nullptr) continue;
            team[mTeam].tail[k]->nxt = team[mTeam].head[i]->nxt;
            team[mTeam].tail[k] = team[mTeam].tail[i];
            team[mTeam].head[i]->nxt = nullptr;
            team[mTeam].tail[i] = team[mTeam].head[i];
        }
    }
}

int bestSoldier(int mTeam)
{
    int mID = 0;
    for(int i=5; i>=1; i--) {
        Node* ptr = team[mTeam].head[i]->nxt;
        if(ptr == nullptr) continue;

        while(ptr != nullptr) {
            if(ptr->v == version[ptr->id] && mID < ptr->id) {
                mID = ptr->id;
            }
            ptr = ptr->nxt;
        }
        if(mID != 0) {
            return mID;
        }
    }
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

bool vis[201];

// 한 번 호출에 하나의 네트워크를 탐색
void dfs(int node, int n, vector<vector<int>> computers) {

    for(int i=node+1; i<n; i++) {
        if(vis[i] || computers[node][i] == 0)  continue;
        vis[i] = true;
        dfs(i, n, computers);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    // 1. 방문 확인
    // 2. 방문 안했으면 방문하고 재귀 호출하여 네트워크 그래프 그림
    // 3. 모든 노드 방문할때까지 반복
    for(int i=0; i<n; i++) {
        if(vis[i])  continue;
        answer++;
        vis[i] = true;
        dfs(i, n, computers);
    }
    return answer;
}
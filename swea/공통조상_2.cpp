#include<bits/stdc++.h>
using namespace std;

const int M = 13;
vector<int> adj[10001];
int parent[10001][M];
int depth[10001];
int v, e, v1, v2;
int cnt;

void makeTree(int cur) {
    for(int next : adj[cur]) {
        if(depth[next] == -1) {
            depth[next] = depth[cur] +1;
            parent[next][0] = cur;
            makeTree(next);
        }
    }
}

void dfs(int k) {
    cnt++;
    for(int i=1; i<v; i++) {
        if(parent[i][0] != k)	continue;
        dfs(i);
    }
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin >> v >> e >> v1 >> v2;
        v1--;
        v2--;
        for(int  i=0; i<10001; i++) {
            adj[i].clear();
        }
        for(int i=0; i<e; i++) {
            int u,  v;
            cin >> u >> v;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cnt = 0;
        // 인접 리스트 값 이용해서 트리 만들기
        for(int i=0; i<v; i++)
            fill(parent[i], parent[i]+13, -1);
        fill(depth, depth+v, -1);
        depth[0] = 0;
        makeTree(0);

        // 2^(M-2)까지 parent 배열 채우기 
        for(int j=0; j < M-1; j++) {
            for(int i=1; i<v; i++) {
                if(parent[i][j] != -1)
                    parent[i][j+1] = parent[parent[i][j]][j];
            }
        }

        // 두 정점의 depth 맞추기
        if(depth[v1] < depth[v2])	swap(v1, v2);
        int diff = depth[v1] - depth[v2];
        for(int j=0; diff; j++) {
            if(diff % 2 != 0)	v1 = parent[v1][j];
            diff /= 2;
        }
//        cout << "test: " << v1 <<  ' ' << v2 << '\n';
        if(v1 != v2) {
            for(int j=M-1; j>=0; j--) {
                if(parent[v1][j] != -1 && parent[v1][j] != parent[v2][j]) {
                    v1 = parent[v1][j];
                    v2 = parent[v2][j];
                }
            }
        }
        v1 = parent[v1][0];
        dfs(v1);
        cout << '#' << test_case << ' ' << v1+1 << ' ' << cnt << '\n';
    }
    return 0;
}
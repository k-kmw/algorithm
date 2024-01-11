#include <bits/stdc++.h>
using namespace std;

int n, m;
const int M = 18;
vector<int> adj[100001];
int parent[100001][M];
int depth[100001];


void makeTree(int cur) {
    for(int next : adj[cur]) {
        if(depth[next] == -1) {
            parent[next][0] = cur;
            depth[next] = depth[cur] + 1;
            makeTree(next);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    // 1. adj배열 채우고, 트리 만들기
    for(int i=0; i<n; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0; i<n; i++)
        fill(parent[i], parent[i]+18, -1);
    fill(depth, depth+n, -1);
    depth[0] = 0;
    makeTree(0);

    // 2. parent 배열 dp로 채움
    for(int j=0; j<M-1; j++) {
        for(int i=1; i<n; i++) {
            if(parent[i][j] != -1) {
                parent[i][j+1] = parent[parent[i][j]][j];
            }
        }
    }

    // 쿼리 입력 받기
    cin >> m;
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        // 3. LCA 찾으려는 두 정점의 depth 같게 만들기
        if(depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        for(int j=0; diff; j++) {
            if(diff % 2 != 0)    u = parent[u][j];
            diff /= 2;
        }

        // 4. u와 v가 다르면 동시에 일정 높이만큼 위로 이동시킴
        if(u != v) {
            // parent배열에서 2^M-1번째 부모부터 2^0=1번째 부모까지 모두 순회하여 가장 depth가 깊은 부모를 찾음
            for(int j=M-1; j>=0; j--) {
                if(parent[u][j] != -1 && parent[u][j] != parent[v][j]) { // u와 v의 부모가 같지 않으면 한 칸씩 올림
                    u = parent[u][j];
                    v = parent[v][j];
                }
            }
            // for문 후에는 마지막에는 u와 v의 부모가 같음. 따라서 마지막으로 한 칸 올리면 LCA
            u = parent[u][0];
        }
        cout << u+1 << '\n';
    }
}
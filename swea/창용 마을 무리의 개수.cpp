#include<bits/stdc++.h>
using namespace std;

bool edge[101][101];
bool vis[101];
int n, m;
int cnt;

// 한 조각에 하나의 노드의 그룹을 결정한다
void dfs(int k) {
    if(vis[k]) {
        return;
    }
    vis[k] = true;
    for(int i=0; i<n; i++) {
        if(edge[k][i]) {
            dfs(i);
        }
    }
}
int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin >> n >> m;
        for(int i=0; i<n; i++)
            fill(edge[i], edge[i]+n, false);
        fill(vis, vis+n, false);
        cnt = 0;
        for(int i=0; i<m; i++) {
            int x, y;
            cin >> x >> y;
            edge[x-1][y-1] = true;
            edge[y-1][x-1] = true;
        }
        for(int i=0; i<n; i++) {
            if(vis[i])  continue;
            cnt++;
            dfs(i);
        }
        cout << '#' << test_case << ' ';
        cout << cnt << '\n';
    }
    return 0;
}
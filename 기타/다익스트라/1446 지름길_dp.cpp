#include <bits/stdc++.h>
using namespace std;

int n, d;
int dist[10005];
vector< pair<int, int> > adjList[10005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> d;
    for(int i=1; i<=d; i++) {
        dist[i] = i;
    }
    for(int i=0; i<n; i++) {
        int st, en, dis;
        cin >> st >> en >> dis;
        adjList[en].push_back(make_pair(dis, st));
    }

    dist[0] = 0;
    for(int i=1; i<=d; i++) {
        if(adjList[i].empty()) {
            dist[i] = dist[i-1]+1;
        } else {
            for(auto r : adjList[i]) {
                dist[i] = min(dist[i], min(dist[i-1]+1, dist[r.second] + r.first));
            }
        }
    }
    cout << dist[d] << '\n';
}

// dp..? 다익스트라로 풀어보기
#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int src, dest, dist;
    Edge() = default;
    Edge(int src, int dest, int dist) {
        this->src = src;
        this->dest = dest;
        this->dist = dist;
    }

    bool operator < (const Edge& other) const {
        return this->dist > other.dist;
    }
};

int n, m;
int board[105][105];
bool vis[105][105];
int dy[] = {-1, 0, 1 ,0};
int dx[] = {0, -1, 0, 1};
int num = 1;
priority_queue<Edge> edges;

void bfs(int y, int x) {
    queue< pair<int, int> > q;
    q.push(make_pair(y, x));
    vis[y][x] = true;
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(int dir=0; dir<4; dir++) {
            int ny = cur.first + dy[dir];
            int nx = cur.second + dx[dir];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(vis[ny][nx] || board[ny][nx] == 0) continue;
            vis[ny][nx] = true;
            board[ny][nx] = num;
            q.push(make_pair(ny, nx));
        }
    }
}

/*
 * 다른 섬과 직선 거리(간선) 찾기
 */
void bfs2(int i, int j, int dir) {
    queue< pair<pair<int, int>, int > > q; // 좌표(i, j), 길이
    q.push(make_pair(make_pair(i, j), 0));
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
//        cout << "cur: " << cur.first.first << ' ' << cur.first.second << ' ' << cur.second.first << '\n';
        int ny = cur.first.first + dy[dir];
        int nx = cur.first.second + dx[dir];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if(board[ny][nx] != 0 && board[i][j] != board[ny][nx]) {
            if(cur.second >= 2) {
                edges.push(Edge(board[i][j], board[ny][nx], cur.second));
                break;
            }
            continue;
        }
        if(board[ny][nx] == board[i][j]) continue;
        q.push(make_pair(make_pair(ny, nx), cur.second+1));
    }
}

int parent[8];
void make_set() {
    for(int i=1; i<num; i++) {
        parent[i] = i;
    }
}

int find(int a) {
    if(a == parent[a])   return a;
    return parent[a] = find(parent[a]);
}

bool doUnion(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    if(rootA == rootB)  return false;
    parent[rootA] = rootB;
    return true;
}


int main() {

    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(vis[i][j] || board[i][j] == 0)   continue;
            board[i][j] = num;
            bfs(i, j);
            num++;
        }
    }

//    for(int i=0; i<n; i++) {
//        for(int j=0; j<m; j++) {
//            cout << board[i][j] << ' ';
//        }
//        cout << '\n';
//    }

    // 간선 리스트 만들기
    // 1. 모든 0이 아닌 점을 큐에 넣고 좌표, 거리, 방향을 담은 bfs
    // 2. 다른 섬 번호를 만나면 간선으로 만들어서 리스트에 추가
    for(int i=0; i<n; i++) {
        fill(vis[i], vis[i]+m, false);
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(board[i][j] == 0) continue;
            for(int dir=0; dir<4; dir++) { // 하나의 방향으로 계속 이동
                bfs2(i, j, dir);
            }
        }
    }

//    while(!edges.empty()) {
//        auto edge = edges.top();
//        edges.pop();
//        cout << edge.src << ' ' << edge.dest << ' ' << edge.dist << '\n';
//    }

    int ans = 0;
    int cnt = 0;
    make_set();
    while(!edges.empty()) {
        auto edge = edges.top();
        edges.pop();
        if(doUnion(edge.src, edge.dest)) {
//            cout << edge.src << ' ' << edge.dest << '\n';
            ans += edge.dist;
            cnt++;
        }
    }
    if(cnt == num-2) {
        cout << ans << '\n';
        return 0;
    }
    cout << -1 << '\n';
}
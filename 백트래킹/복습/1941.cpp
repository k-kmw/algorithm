#include <bits/stdc++.h>
using namespace std;
string board[5];
pair<int, int> arr[7];
bool isused[25];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int ans;
bool vis[5][5];

bool bfs() {
    for(int i=0; i<5; i++) // bfs가 여러번 실행되므로 vis를 초기화 시켜줘야 함
        fill(vis[i], vis[i]+5, 0);
    queue<pair<int, int>> q;
    int x = arr[0].first;
    int y = arr[0].second;
    q.push({x, y}); // 처음 시작점
    vis[x][y] = true;
    int cnt = 1; // 처음 cnt = 1임을 주의
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(int dir=0; dir<4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5)   continue;
            if(!isused[nx*5+ny] || vis[nx][ny])    continue; // 선택된 학생이 아니거나 방문했으면 넘어감
            q.push({nx, ny});
            vis[nx][ny] = true;
            cnt++;
        }
    }
    if(cnt == 7) { // 7명이 인접하면
        return true;
    }
    return false;
}

bool check(){
    int cnt = 0;
    for(auto & i : arr) {
        if(board[i.first][i.second] == 'S') { // 이다솜파 학생이면
            cnt++;
        }
    }
    if(cnt >= 4) // 이다솜파 학생이 4명 이상이면
        return true;
    return false;
}

void dfs(int k) {
    if(k == 7) { // 7명이 선택되면
        if (check()) { // 이다솜파가 4명 이상인지 확인
            if(bfs()) { // 인접하게 7명이 있는지 확인
                ans++;
            }
        }
        return;
    }

    int st = 0;
    if(k != 0)  st = arr[k-1].first*5 + arr[k-1].second + 1; // 순서를 배치는 상관없으므로 현재 다음부터 선택
    for(int i=st; i<25; i++) {
        arr[k] = {i/5, i%5}; // 0~24번 학생을 좌표로 나타냄
        isused[i] = true; // i번 학생 선택 표시
        dfs(k+1); // 다음 번째 학생 선택
        isused[i] = false; // 선택후 i번째 학생 선택 표시 제거
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(auto & s : board)
        cin >> s;

    dfs(0);
    cout << ans;
}
#include <bits/stdc++.h>
using namespace std;
int n, m;
int board[50][50];
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;
pair<int, int> arr[15];
int ans = 99999999;

void func(int k, int st) {
    if(k == m) {
        int sum = 0;
        for(auto h : home) {
            int mn = 99999999;
            int tmp;
            for(int i=0; i<m; i++) {
                tmp = abs(h.first - arr[i].first) + abs(h.second - arr[i].second);
//                cout << tmp << '\n';
                mn = min(tmp, mn);
            }
            sum += mn;
        }
        ans = min(ans, sum);
        return;
    }
    for(int i=st; i<chicken.size(); i++) {
            arr[k] = chicken[i];
            func(k+1, i+1);
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> board[i][j];
            if(board[i][j] == 1)
                home.emplace_back(i, j);
            if(board[i][j] == 2)
                chicken.emplace_back(i, j);
        }
    }
    func(0, 0);
    cout << ans;
}

//백트래킹 순열로 구현하면 시간초과 13P6 = 1,235,520
// 13C6 = 1,716
// 100 * 13 * 13P6 = 16억~ (1초 3~5억)
// 100 * 13 * 13C6 = 22만~
#include <bits/stdc++.h>
using namespace std;

int n, m, l, k;
vector< pair<int, int> > stars;
int dist[105][105];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> l >> k;
    for(int i=0; i<k; i++) {
        int y, x;
        cin >> y >> x;
        stars.push_back(make_pair(y, x));
    }

    // 한 점에서 다른 모든 점까지 거리를 구하기
    // 모든 점을 순회하며 트램펄린 길이 안에 들어올 수 있는 점의 개수를 찾기
    // 전체 개수에서 구한 점의 개수의 최대 값을 빼기
    for(int i=0; i<k; i++) {
        for(int j=0; j<k; j++) {
            if(i == j) continue;
            if(dist[i][j] != 0) continue;
            dist[i][j] = abs(stars[i].first - stars[j].first) + abs(stars[i].second - stars[j].second);
//            cout << i << ' ' << j << ' ' << dist[i][j] << '\n';
        }
    }
    int mx = 0;
    for(int i=0; i<k; i++) {
        int cnt = 0;
        for(int j=0; j<k; j++) {
            if(i ==j) continue;
            if(dist[i][j] <= 2*(l+1)) {
                if(stars[i].first <= stars[j].first && stars[i].second <= stars[j].second) { // 왼쪽 맨 위
                    cnt++;
                }
            }
        }
        mx = max(mx, cnt);
        cnt = 0;

        for(int j=0; j<k; j++) {
            if(i ==j) continue;
            if(dist[i][j] <= 2*(l+1)) {
                if(stars[i].first <= stars[j].first && stars[i].second >= stars[j].second) { // 오른쪽 맨 위
                    cnt++;
                }
            }
        }
        mx = max(mx, cnt);
        cnt = 0;

        for(int j=0; j<k; j++) {
            if(i ==j) continue;
            if(dist[i][j] <= 2*(l+1)) {
                if(stars[i].first >= stars[j].first && stars[i].second <= stars[j].second) { // 왼쪽 아래
                    cnt++;
                }
            }
        }
        mx = max(mx, cnt);
        cnt = 0;

        for(int j=0; j<k; j++) {
            if(i ==j) continue;
            if(dist[i][j] <= 2*(l+1)) {
                if(stars[i].first >= stars[j].first && stars[i].second >= stars[j].second) { // 오른쪽 아래
                    cnt++;
                }
            }
        }
        mx = max(mx, cnt);
        cnt = 0;
    }
    cout << k - mx;
}
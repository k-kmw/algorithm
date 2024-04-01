#include <bits/stdc++.h>
using namespace std;

int h[100005];
vector<pair<int, int>> adjList[100005];
int main() {

    // 각 지점의 높이와 갈 수 있는 다른 지점까지의 거리
    // 임의의 지점을 목표로
    // 집에서 정한 목표에 도달할 때 까지 항상 높이가 증가하는 방향으로만 이동
    // 거리 1을 움직일 때 마다 D의 체력이 소모
    // 정한 목표에 도달하면 높이 1당 E의 성취감
    // 등산의 가치 = 얻은 성취감 - 소모한 체력
    // 가치가 가장 높은 등산 경로 선택

    // 집 - 등산 - 고려대학교
    // 이전 산과 높이가 같거나 커야함

    int n, m, d, e;
    cin >> n >> m >> d >> e;
    for(int i=1; i<=n; i++) {
        cin >> h[i];
    }
    for(int i=0; i<m; i++) {
        int u, v, w;
        adjList[u].push_back({w, v});
        adjList[v].push_back({w, u});
    }
    
}
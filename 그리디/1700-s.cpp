#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int a[105];
bool power[105];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    for(int i=0; i<k; i++)  cin >> a[i];

    int ans = 0;
    int cnt = 0;
    for(int i=0; i<k; i++) {
        if(power[a[i]]) continue; // 이미 꽂혀 있음

        if(cnt < n) {   // 빈칸이 있으면
            power[a[i]] = true;
            cnt++;
        }
        else { // 그외, 스케줄링 필요
            vector<pair<int, int>> idx;
            for(int x=1; x<=k; x++) { // 전기용품 1부터 확인
                if(!power[x]) continue; // 꽂혀 있지 않으면 스케줄링 대상이 아님
                bool vis = false;
                for(int y=i+1; y<k; y++) { // y=i+1부터 시작
                    if(a[y] == x) { // 해당 전기용품의 다음번에 가장 먼저 사용되는 인덱스를 저장
                        idx.emplace_back(y, x);
                        vis = true;
                        break; // 가장 먼저 사용되는 인덱스를 저장하고 빠져나감
                    }
                }
                if(!vis) { // 꽂혀있는 전기용품이 현재 전기용품 뒤로 사용하지 않는 경우
                    idx.emplace_back(k+1, x);
                }
            }

            sort(idx.begin(), idx.end(), greater<pair<int, int>>()); // 내림 차순 정렬
            power[idx[0].Y] = false; // 가장 나중에 사용되는 전기용품을 대체
            ans++;
            power[a[i]] = true;
        }
    }
    cout << ans;
}
// 그리디하게 가장 나중에 사용하는 전기용품을 대체
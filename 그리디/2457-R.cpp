#include <bits/stdc++.h>
using namespace std;
pair<int, int> flowers[100001];
#define X first
#define Y second

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        int sm, sd, em, ed;
        cin >> sm >> sd >> em >> ed;
        flowers[i].X = sm*100 + sd;
        flowers[i].Y = em*100 + ed;
    }
    sort(flowers, flowers+n);

    int t = 301; // 현재 시점
    int nt = 301; // 다음 시점
    int ans = 0;
    for(int i=0; i<n; i++) {
        if(t >= flowers[i].X) { // 피는 시점이 현재 시점 이전
            if(flowers[i].Y > nt) { // 더 늦게 지는 것
                nt = flowers[i].Y;
            }
        }
        else{ // 꽃을 추가하고 t를 갱신
            ans++;
            t = nt;
            if(t < flowers[i].X) {
                ans = 0;
                break;
            }
            i--; // 현재 꽃을 재조사
//            cout << t << '\n';
            continue;
        }
        if(t >= 1201)    break; // 현재 시점에 1201이상이 되면 멈춤

        if(i == n-1 && nt >= 1201) { // 마지막 꽃 예외 처리
            ans++;
            t = nt;
        }
        else if(i == n-1 && nt < 1201){
            ans = 0;
        }

    }
    cout << ans;
}
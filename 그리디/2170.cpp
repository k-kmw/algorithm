#include<bits/stdc++.h>
using namespace std;
pair<long long, long long> dots[1000001];
#define X first
#define Y second

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> dots[i].X >> dots[i].Y;
    sort(dots, dots+n);

    long long ans = 0;
    long long x = dots[0].X;
    long long y = dots[0].Y;
    for(int i=0; i<n; i++) {
        // 한 선의 시작점이 다른 선에 포함 되는 경우
        if(dots[i].X <= y) {
            if(dots[i].Y > y) {
                y = dots[i].Y;
            }
        }
        // 새로운 시작점의 경우
        else if(dots[i].X > y){
            if(x >= 0 && y >= 0) {
                ans += y - x;
            }
            else if(x <= 0 && y >= 0) {
                ans += y - x;
            }
            else if(x <= 0) {
                ans += abs(x) - abs(y);
            }
            x = dots[i].X;
            y = dots[i].Y;
        }
        if(i == n-1) { // 마지막 선 처리
            if(x >= 0 && y >= 0) {
                ans += y - x;
            }
            else if(x <= 0 && y >= 0) {
                ans += y - x;
            }
            else if(x <= 0) {
                ans += abs(x) - abs(y);
            }
            break;
        }
        // 한 선이 다른 선에 포함 되는 경우
        if(dots[i].X <= y && dots[i].Y <= y) {
            continue;
        }

    }
    cout << ans;
}
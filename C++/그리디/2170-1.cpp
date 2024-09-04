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
    long long st = -1000000001;
    long long en = st;
    for(int i=0; i<n; i++) {
        // 새로운 시작점
        if(en < dots[i].X) {
            ans += en - st;
            st = dots[i].X;
            en = dots[i].Y;
        }
        // 한 선분의 시작점이 다른 선분에 포함 되는 경우
        else if(en < dots[i].Y) {
            en = dots[i].Y;
        }
        // 선분이 다른 선분에 포함되는 경우 pass
    }
    ans += en - st;
    cout << ans;
}
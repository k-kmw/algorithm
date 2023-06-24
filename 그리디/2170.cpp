#include<bits/stdc++.h>
using namespace std;
pair<int, int> dots[1000001];
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

    int x = dots[0].X;
    int y = dots[0].Y;
    int ans = 0;
    for(int i=1; i<n; i++) {
        int ny = y;
        if(dots[i].X < y && dots[i].Y > y) {
            ny = dots[i].Y;
        }
        if(ny == y) {
            ans += abs(ny) - abs(x);
        }
        if(i==n-1 && dots[i].X > x) {
            ans += abs(dots[i].Y) - abs(dots[i].X);
        }
    }
    cout << ans;
}
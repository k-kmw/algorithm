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

    int t = 301;
    int ans = 0;
    while(t < 1201) {
        int nt = t;
        for(int i=0; i<n; i++) {
            if(flowers[i].X <= t){
                if(flowers[i].Y > nt) {
                    nt = flowers[i].Y;
                }
            }
        }
        if(nt == t) {
            ans = 0;
            break;
        }
        ans++;
        t = nt;
    }
    cout << ans;
}
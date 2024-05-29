#include <bits/stdc++.h>
using namespace std;
int ans[10000];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int m;
        cin >> m;
        for(int i=1; i<=m; i++) {
            int a;
            cin >> a;
            ans[i] = a;
            int idx = -1;
            for(int j=i-1; j>=1; j--) {
                if(ans[j] > a) {
                    idx = j;
                }
            }
            if(idx != -1) {
                int tmp = ans[idx];
                ans[idx] = a;
                ans[i] = tmp;
            }

            for(int k=1; k<=m; k++) {
                cout << ans[k] << ' ';
            }
            cout << '\n';

//            if(i % 2 != 0) {
//                cout << ans[i/2 + 1] << ' ';
//            }
        }
        cout << '\n';
    }
}

// 다시 생각 해보기..
#include <bits/stdc++.h>
using namespace std;
int n, m;
int card[101];
int ans;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++)
        cin >> card[i];

    int tmp;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            for(int k=j+1; k<n; k++) {
                tmp = card[i] + card[j] + card[k];
                if(tmp <= m)
                    ans = max(ans, tmp);
            }
        }
    }
    cout << ans << '\n';
}
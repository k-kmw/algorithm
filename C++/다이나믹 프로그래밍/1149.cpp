#include <bits/stdc++.h>
using namespace std;
int rgb[1001][3];
int d[1001][3];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=1; i<=n; i++)
        for(int j=0; j<3; j++)
            cin >> rgb[i][j];

    d[1][0] = rgb[1][0];
    d[1][1] = rgb[1][1];
    d[1][2] = rgb[1][2];

    for(int i=2; i<=n; i++) {
        d[i][0] = min(d[i-1][1], d[i-1][2]) + rgb[i][0];
        d[i][1] = min(d[i-1][0], d[i-1][2]) + rgb[i][1];
        d[i][2] = min(d[i-1][0], d[i-1][1]) + rgb[i][2];
    }
//    cout << min(min(d[n][0], d[n][1]), d[n][2]);
    cout << min({d[n][0], d[n][1], d[n][2]});
//    cout << *min_element(d[n], d[n]+3);
}

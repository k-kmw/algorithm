#include <bits/stdc++.h>
using namespace std;
int maxDP[3];
int minDP[3];
int tempMax[3];
int tempMin[3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for(int i=0; i<n; i++) {
        for(int j=0; j<3; j++) {
            cin >> tempMax[j];
            tempMin[j] = tempMax[j];
            tempMax[j] += max(maxDP[1], (j==1 ? max(maxDP[0], maxDP[2]) : maxDP[j]));
            tempMin[j] += min(minDP[1], (j==1 ? min(minDP[0], minDP[2]) : minDP[j]));
        }
        copy(tempMax, tempMax+3, maxDP);
        copy(tempMin, tempMin+3, minDP);
    }
    sort(maxDP, maxDP+3);
    sort(minDP, minDP+3);

    cout << maxDP[2] << ' ' << minDP[0] << '\n';
}
#include <bits/stdc++.h>
using namespace std;
int a[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];

    int max = a[0];
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            int tmp = a[i];
            int pre = a[i];
            for(int k=j; k<n; k++) {
                if(pre >= a[k]) {
                    continue;
                }
                else {
                    tmp += a[k];
                    pre = a[k];
                }
            }
            if (max < tmp) {
                max = tmp;
//                cout << max << '\n';
            }
        }
    }
    cout << max;
}

// naive한 풀이
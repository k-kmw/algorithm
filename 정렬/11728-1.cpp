#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int b[1000000];
int c[2000000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<m; i++) cin >> b[i];

    int aidx = 0;
    int bidx = 0;

    for(int i=0; i<n+m; i++) {
        if(bidx == m)   c[i] = a[aidx++];
        else if(aidx == n)  c[i] = b[bidx++];
        else if(a[aidx] <= b[bidx]) c[i] = a[aidx++];
        else    c[i] = b[bidx++];
    }

    for(int i=0; i<n+m; i++)
        cout << c[i] << ' ';
}


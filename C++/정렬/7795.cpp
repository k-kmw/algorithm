#include <bits/stdc++.h>
using namespace std;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> vecA(n);
        vector<int> vecB(m);
        for(int i=0; i<n; i++)  cin >> vecA[i];
        for(int i=0; i<m; i++)  cin >> vecB[i];
        sort(vecA.begin(), vecA.end());
        sort(vecB.begin(), vecB.end());

        int cnt = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(vecA[i] > vecB[j]) {
                    cnt++;
                }
                else
                    break;
            }
        }
        cout << cnt << '\n';
    }
}
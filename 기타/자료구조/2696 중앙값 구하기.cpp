#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int m;
        cin >> m;
        int midx = 0;
        int ans[10000];
        queue<int> q;
        priority_queue<int> pq;
        for(int i=1; i<=m; i++) {
            int a;
            cin >> a;
            pq.push(a);

            if(i % 2 != 0) {
                midx++;
                while(midx != pq.size()) {
                    int top = pq.top();
                    pq.pop();
                    q.push(top);
                }
                ans[midx] = pq.top();
                while(!q.empty()) {
                    pq.push(q.front());
                    q.pop();
                }
            }
        }
        cout << midx << '\n';
        for(int i=1; i<=midx; i++) {
            cout << ans[i] << ' ';
            if (i % 10 == 0) {
                cout << '\n';
            }
        }
        cout << '\n';
    }
}
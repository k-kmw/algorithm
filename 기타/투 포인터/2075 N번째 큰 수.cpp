    #include <bits/stdc++.h>
    using namespace std;

    int main() {

        ios::sync_with_stdio(0);
        cin.tie(0);
        int n;
        cin >> n;
        priority_queue<int> pq;
        for(int i=0; i<n; i++) {
            int x;
            cin >> x;
            pq.push(-x);
        }

        for(int i=1; i<n; i++) {
            for(int j=0; j<n; j++) {
                int x;
                cin >> x;
                pq.push(-x);
            }
            for(int j=0; j<n; j++) {
                pq.pop();
            }
        }
        cout << -pq.top() << '\n';
    }
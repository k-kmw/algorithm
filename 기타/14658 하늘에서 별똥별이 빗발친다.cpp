#include <bits/stdc++.h>
using namespace std;

int n, m, l, k;
vector< pair<int, int> > stars;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> l >> k;
    for(int i=0; i<k; i++) {
        int y, x;
        cin >> y >> x;
        stars.push_back(make_pair(y, x));
    }

    int mx = 0;
    for(int i=0; i<k; i++) {
        for(int j=0; j<k; j++) {
            int cnt = 0;
            for(int a=0; a<k; a++) {
                auto cur = stars[a];
                if(cur.first >= stars[i].first && cur.first <= stars[i].first+l
                && cur.second >= stars[j].second && cur.second <= stars[j].second+l) {
                    cnt++;
                }
            }
            mx = max(mx, cnt);
        }
    }
    cout << k - mx;
}
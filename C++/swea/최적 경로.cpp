#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> customers;
vector<pair<int, int>> vec;
bool vis[11];
int n;
int mn = 200 * 11;
int tmp;
int stY, stX, enY, enX;

void dfs(int k) {
    if(k == n) {
        tmp += abs(vec[0].first - stX) + abs(vec[0].second - stY);
        tmp += abs(vec[n-1].first - enX) + abs(vec[n-1].second - enY);
        for(int i=0; i<n-1; i++) {
            tmp += abs(vec[i].first - vec[i+1].first) + abs(vec[i].second - vec[i+1].second);
        }
        // cout << tmp << '\n';
        mn = min(mn, tmp);
        tmp = 0;
        return;
    }
    for(int i=0; i<n; i++) {
        if(vis[i])  continue;
        vis[i] = true;
        vec.push_back({customers[i].first, customers[i].second});
        dfs(k+1);
        vis[i] = false;
        vec.pop_back();
    }
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin >> n;
        cin >> stX >> stY >> enX >> enY;
        customers.clear();
        mn = 200 * 11;
        for(int i=0; i<n; i++) {
            int x, y;
            cin >> x >> y;
            customers.push_back({x, y});
        }
        dfs(0);
        cout << '#' << test_case << ' ' << mn << '\n';
    }
    return 0;
}
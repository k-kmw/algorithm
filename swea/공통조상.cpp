#include<bits/stdc++.h>
using namespace std;
int p[10001];
vector<int> p1;
vector<int> p2;
int n, e, v1, v2;
int cnt;

void dfs(int k) {
    cnt++;
    for(int i=1; i<=n; i++) {
        if(p[i] != k)   continue;
        dfs(i);
    }
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin >> n >> e >> v1 >> v2;
        for(int i=0; i<e; i++) {
            int a, b;
            cin >> a >> b;
            p[b] = a;
        }
        cnt = 0;
        p1.clear();
        p2.clear();
        int np = p[v1];
        while(np != 0) {
            p1.push_back(np);
            np = p[np];
        }
        np = p[v2];
        while(np != 0) {
            p2.push_back(np);
            np = p[np];
        }

        int lca = np;
        if(p1.size() < p2.size()) {
            for(auto v : p1) {
                if(find(p2.begin(), p2.end(), v) != p2.end()) {
                    lca = v;
                    break;
                    // cout << lca << '\n';
                }
            }
        }
        else {
            for(auto v : p2) {
                if(find(p1.begin(), p1.end(), v) != p1.end()) {
                    lca = v;
                    break;
                    // cout << lca << '\n';
                }
            }
        }
        dfs(lca);

        cout << '#' << test_case << ' ' << lca << ' ' << cnt << '\n';
    }
    return 0;
}
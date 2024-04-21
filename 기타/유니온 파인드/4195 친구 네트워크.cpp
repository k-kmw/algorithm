#include <bits/stdc++.h>
using namespace std;
map<string, int> cnt;
map<string, string> p;

string find(string s) {
    if(p[s] == "") {
        return s;
    }
    return p[s] = find(p[s]);
}

void merge(string s1, string s2) {
    string root1 = find(s1);
    string root2 = find(s2);
    if(root1 == root2) {
        return;
    }
    p[root2] = root1;
    if(cnt[root1] == 0) {
        cnt[root1] = 1;
    }
    if(cnt[root2] == 0) {
        cnt[root2] = 1;
    }
    cnt[root1] += cnt[root2];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

//    cout << (p["Fred"] == "") << '\n';
    int t;
    cin >> t;
    while(t--) {
        cnt = map<string, int>();
        p = map<string, string>();

        int f;
        cin >> f;
        for(int i=0; i<f; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            merge(s1, s2);
            string root = find(s1);
//            cout << root << '\n';
            cout << cnt[root] << '\n';
        }
    }
}
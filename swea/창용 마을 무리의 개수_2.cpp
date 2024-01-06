#include<bits/stdc++.h>
using namespace std;

int p[101];

int find(int n) {
    if(p[n] < 0) return n;
    p[n] = find(p[n]);
    return p[n];
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return;
    p[b] = a;
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int n, m;
        cin >> n >> m;
        fill(p, p+101, -1);
        for(int i=0; i<m; i++) {
            int a, b;
            cin >> a >> b;
            if(a > b) {
                swap(a, b);
            }
            int rootA = find(a);
            int rootB = find(b);
            if(rootA != rootB) {
                merge(a, b);
            }
            if(rootA == rootB && rootA == -1) {
                merge(a, b);
            }
        }
        int cnt = 0;
        for(int i=1; i<=n; i++) {
            if(p[i] < 0) {
                cnt++;
            }
        }
        cout << '#' << test_case << ' ';
        cout << cnt << '\n';
    }
    return 0;
}
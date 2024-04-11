#include <bits/stdc++.h>
using namespace std;

int n, m;
int p[205];

void make_set() {
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
}

int find(int n) {
    if (n == p[n])	return n;
    return p[n] = find(p[n]);
}

void merge(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    if (rootA == rootB)	return;
    p[rootA] = rootB;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    make_set();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int a;
            cin >> a;
            if (a == 1) {
                merge(i, j);
            }
        }
    }

    int city;
    cin >> city;
    int rootA = find(city);

    for (int i = 1; i < m; i++) {
        cin >> city;
        int rootB = find(city);
        //cout << city << ' ' << rootB << '\n';
        if (rootA != rootB) {
            cout << "NO" << '\n';
            return 0;
        }
        rootA = rootB;
    }
    cout << "YES" << '\n';
}
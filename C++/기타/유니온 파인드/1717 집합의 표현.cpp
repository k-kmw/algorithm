#include <bits/stdc++.h>
using namespace std;

int p[1000005];
int n, m;

void make_set() {
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
}

int find(int n) {
    if (p[n] == n)	return n;
    return p[n] = find(p[n]);
}

void merge(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    if (rootA == rootB) return;
    p[rootA] = rootB;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    make_set();

    while (m--) {
        int op, a, b;
        cin >> op >> a >> b;
        switch (op) {
            case 0:
                merge(a, b);
                break;
            case 1:
                int rootA = find(a);
                int rootB = find(b);
                if (rootA == rootB) {
                    cout << "yes" << '\n';
                }
                else {
                    cout << "no" << '\n';
                }
                break;
        }
    }
}
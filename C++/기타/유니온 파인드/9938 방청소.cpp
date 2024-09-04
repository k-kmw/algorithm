#include <bits/stdc++.h>
using namespace std;

int n, l;
int a[300005];
int b[300005];
bool surab[300005];

int p[300005];
void make_set() {
    for(int i=1; i<=l; i++) {
        p[i] = i;
    }
}

int find(int k) {
    if(k == p[k])   return k;
    return p[k] = find(p[k]);
}

bool merge(int k, int u) {
    int rootA = find(k);
    int rootB = find(u);
    if(!surab[rootA]) {
        surab[rootA] = true;
        p[rootA] = rootB;
        return true;
    } else if(!surab[rootB]) {
        surab[rootB] = true;
        p[rootB] = rootA;
        return true;
    } else {
        return false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l;

    make_set();
    for(int i=1; i<=n; i++) {
        cin >> a[i] >> b[i];
        if(merge(a[i], b[i])) {
            cout << "LADICA" << '\n';
        } else {
            cout << "SMECE" << '\n';
        }
    }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int e, s, m;
    cin >> e >> s >> m;
    int ne = 0;
    int ns = 0;
    int nm = 0;
    int year = 0;
    while(1) {
        if(ne == 16)
            ne = 1;
        if(ns == 29)
            ns = 1;
        if(nm == 20)
            nm = 1;
        if(ne == e && ns == s && nm == m) {
            cout << year;
            break;
        }
        ne++;
        ns++;
        nm++;
        year++;
    }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int e, s, m;
    cin >> e >> s >> m;
    for(int i=1; i<=15*28*19; i++) {
        if((i-e)%15 == 0 && (i-s)%28 == 0 && (i-m)%19 == 0){
            cout << i;
            return 0;
        }
    }
}
#include <bits/stdc++.h>
using namespace std;

void star(int i, int j, int n) {
    if(i%3 == 1 && j%3 == 1)
        cout << ' ';
    else if((i/3)%3 == 1 && (j/3)%3 == 1)
        cout << ' ';
    else
        cout << '*';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        for (int j = 0; j < n; j++) {
            star(i, j, n);
        }
        cout << '\n';
    }
}
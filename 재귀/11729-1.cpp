#include <bits/stdc++.h>
using namespace std;

void hanoi(int src, int dest, int tmp, int n) {
    if(n == 1) {
        cout << src << ' ' << dest << '\n'; // 맨 위 1개를 옮길때 까지 재귀로 n-1
        return;
    }
    hanoi(src, tmp, dest, n-1); // src에서 tmp로 n-1개를 옮김
    cout << src << ' ' << dest << '\n'; // src에서 dest로 맨 밑 1개를 옮김
    hanoi(tmp, dest, src, n-1); // tmp에서 dest로 n-1개를 옮김
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    cout << (1<<n) -1 << '\n';
    hanoi(1, 3, 2, n);
}
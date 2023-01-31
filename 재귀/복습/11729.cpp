#include <bits/stdc++.h>
using namespace std;

void hanoi(int src, int dst, int tmp, int n) {
    if(n == 1) { // n = 1 일 때
        cout << src << ' ' << dst << '\n';
        return;
    }
    hanoi(src, tmp, dst, n-1); // src에서 tmp로 n-1개를 옮김
    cout << src << ' ' << dst << '\n'; // 남은 1개를 src에서 dst로 옮김
    hanoi(tmp, dst, src, n-1); // tmp의 n-1개를 dst로 옮김
}
// n=k가 성립한다고 가정하면, n=k+1번째 성립

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    hanoi(1, 3, 2, n);
}

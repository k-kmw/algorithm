#include <bits/stdc++.h>
using namespace std;

void print(int n) {
    cout << n << ' ';
    if(n == 1)
        return;
    print(n-1);
}

int sum(int n) {
    if(n == 0)
        return 0;
    return n + sum(n-1);
}

void func(int a) {
    if(a == 0)  return;
    func(a-1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    print(n);
    cout << sum(n);
}





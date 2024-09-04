#include <bits/stdc++.h>
using namespace std;

int n, m;
int trees[1000005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> trees[i];
    }

    // 1. 절단기의 높이를 0부터 10^9까지 이분탐색으로 찾는다.

    int st = 0;
    int en = 1000000000;
    while(st <= en) {
        int h = (st + en)/2;
        long long sum = 0;
        for(int i=0; i<n; i++) {
            if(trees[i] > h) {
                sum += trees[i] - h;
            }
        }
        cout << st << ' ' << en << '\n';
        if(sum >= m) {
            st = h+1;
        } else {
            en = h-1;
        }
    }
    cout << en << '\n';
}
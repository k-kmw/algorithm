#include <bits/stdc++.h>
using namespace std;
int p[1000001];
int n;
long long ans;

void func(int st, int en) {
    if(st == en) {
        if(st != n-1) {
            int mxIdx = max_element(p + en + 1, p + n) - p;
            func(en + 1, mxIdx);
        }
        return;
    }

    for(int i=st; i<en; i++) {
        ans += p[en] - p[i];
    }

    if(en == n-1) {
        return;
    }

    int mxIdx = max_element(p+en+1, p+n) - p;
    func(en+1, mxIdx);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        ans = 0;
        fill(p, p+n, 0);
        for(int i=0; i<n; i++)
            cin >> p[i];

        bool allSame = true;
        for(int i=0; i<n-1; i++) {
            if(p[i] != p[i+1])  allSame = false;
        }
        if(allSame) {
            cout << 0 << '\n';
            continue;
        }

        int mxIdx = max_element(p, p+n) - p;
        func(0, mxIdx);
        cout << ans << '\n';
    }
}

// 이렇게 하면 최악의 경우 시간 복잡도 (n-1)*n으로 사실 틀린 풀이이지만, 테스트 케이스가 부족해서 맞은거 같다
// 최악의 경우 func n-1번 호출, max_element 시간 복잡도 n
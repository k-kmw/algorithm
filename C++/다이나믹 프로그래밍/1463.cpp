#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, 2, 3};
int N;
int ans = 1000000;
int cnt;

void func(int n) {
    if(n <= 1) {
        if(n==1) {
//            cout << cnt << '\n';
            ans = min(ans, cnt);
        }
        return;
    }
    for(int i=0; i<3; i++) {
        if(i == 0) {
            cnt++;
            func(n- dx[i]);
            cnt--;
        }
        else {
            if(n % dx[i] == 0) {
                cnt++;
                func(n / dx[i]);
                cnt--;
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    func(N);
    cout << ans;
}

//시간 초과
//백트래킹 시간복잡도 계산을 잘 모르겠음
//chat gpt에 의하면 3^k인데 k는 dx 배열에 있는 값들을 사용하는 횟수라고 함


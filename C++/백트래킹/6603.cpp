#include <bits/stdc++.h>
using namespace std;
int arr[15];
int ans[15];
int n;
void func(int k, int st) {
    if(k == 6) {
        for(int i=0; i<6; i++)
            cout << ans[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i=st; i<n; i++) {
        ans[k] = arr[i];
        func(k+1, i+1); // 현재 인덱스+1을 다음에 올 숫자의 인덱스 시작 번호로 넘김
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true) {
        cin >> n;
        if(!n)  break;
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }
        func(0, 0);
        cout << '\n';
    }
}


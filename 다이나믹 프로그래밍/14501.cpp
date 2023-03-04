#include <bits/stdc++.h>
using namespace std;
int t[16];
int p[16];
int d[16]; // i번째 일에 상담을 시작했을 때 얻을 수 있는 최대 수익

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> t[i] >> p[i];

    for(int i=n; i>=1; i--) {
        if(i + t[i] <= n+1) {
            d[i] = max(d[i+t[i]] + p[i], d[i+1]);
        }
        else
            d[i] = d[i+1];
    }
    cout << *max_element(d+1, d+1+n);
}

//답지 보고도 어렵게 이해
//다시 풀어보기(앞에서 부터 순서대로 할 경우?)
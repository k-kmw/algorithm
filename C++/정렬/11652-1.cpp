#include <bits/stdc++.h>
using namespace std;
long long arr[100001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    for(int i=0; i<n; i++)  cin >> arr[i];
    sort(arr, arr+n);

    int cnt = 1;
    long long mxval = arr[0];
    int mxcnt = 0;
    for(int i=1; i<n; i++) {
        if(arr[i-1] == arr[i]) {
            cnt++;
        }
        else {
            if(mxcnt < cnt) {
                mxcnt = cnt;
                mxval = arr[i-1];
            }
            cnt = 1;
        }
    }
    if(mxcnt < cnt) { //마지막으로 센 수까지 비교를 해줘야 함
        mxval = arr[n-1];
    }

    cout << mxval;
}
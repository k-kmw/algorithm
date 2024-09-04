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

    int mx = 0;
    int cur = 0;
    int cnt = 1;
    long long mxNum = arr[0];

    for(int i=1; i<n; i++) {
        if(arr[cur] == arr[i]) {
            cnt++;
        }
        else {
            if(mx < cnt) {
                mxNum = arr[cur];
                mx = cnt;
            }
            else if(mx == cnt) {
                if(arr[cur] > arr[i]) {
                    mxNum = arr[i];
                }
            }
            cnt = 1;
            cur = i;
        }
    }
    if(mx < cnt) {
        mxNum = arr[n-1];
    }
    cout << mxNum;
}
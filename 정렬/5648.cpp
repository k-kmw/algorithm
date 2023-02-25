#include <bits/stdc++.h>
using namespace std;
long long arr[1000001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        long long x;
        cin >> x;
        if(x/10 == 0) {
            arr[i] = x;
        }
        else {
            long long cnt = 1;
            long long tmp = x;
            while(tmp/10 > 0) {
                tmp /= 10;
                cnt *= 10;
            }
            long long rev = 0;
            while(x > 0) {
                rev += (x%10) * cnt;
                cnt /= 10;
                x /= 10;
            }
            arr[i] = rev;
        }
    }
    sort(arr, arr+n);

    for(int i=0; i<n; i++) {
        cout << arr[i] << '\n';
    }
}
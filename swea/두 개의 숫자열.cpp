#include<bits/stdc++.h>

using namespace std;

int n, m;
int a[21];
int b[21];
int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin >> n >> m;
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }
        for(int i=0; i<m; i++) {
            cin >> b[i];
        }
        cout << '#' << test_case << ' ';
        int mx = 0;
        if(n>m) {
            int sizeDiff = n - m;
            for(int pos=0; pos<=sizeDiff; pos++) {
                int tot = 0;
                for(int i=0; i<m; i++) {
                    tot += a[pos+i] * b[i];
                }
                mx = max(tot, mx);
            }
        }
        else {
            int sizeDiff = m - n;
            for(int pos=0; pos<=sizeDiff; pos++) {
                int tot = 0;
                for(int i=0; i<n; i++) {
                    tot += a[i] * b[pos+i];
                }
                mx = max(tot, mx);
            }
        }
        cout << mx << '\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
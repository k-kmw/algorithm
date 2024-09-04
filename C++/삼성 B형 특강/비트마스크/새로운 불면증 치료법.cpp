#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int n;
        cin >> n;
        int vis = 0;
        int k = 1;
        while(vis != (1 << 10) -1) {
            int cur = n * k;
            while(cur != 0) {
                vis |= 1 << (cur % 10);
                cur /= 10;
            }
            k++;
        }
        cout << '#' << test_case <<  ' ' << (k-1) * n << '\n';
    }
    return 0;
}
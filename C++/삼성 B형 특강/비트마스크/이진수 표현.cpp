#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int n, m;
        cin >> n >> m;
        cout << '#' << test_case << ' ';
        if((m & ((1 << n)-1)) == ((1<<n)-1)) {
            cout << "ON" << '\n';
        } else {
            cout << "OFF" << '\n';
        }
    }
    return 0;
}
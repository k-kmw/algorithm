#include <bits/stdc++.h>
using namespace std;
int board[8][8];

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int n;
        cin >> n;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cin >> board[i][j];
            }
        }
        cout << '#' << test_case << '\n';
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cout << board[n-1-j][i];
            }
            cout << ' ';
            for(int j=0; j<n; j++) {
                cout << board[n-1-i][n-1-j];
            }
            cout << ' ';
            for(int j=0; j<n; j++) {
                cout << board[j][n-1-i];
            }
            cout << '\n';
        }
    }
    return 0;
}
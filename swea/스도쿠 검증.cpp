#include <bits/stdc++.h>
using namespace std;

int board[10][10];

bool verify(int stY, int stX, int n) { // 9x9 확인
    set<int> s;
    set<int> s2;
    for(int i=stY; i<stY+n; i++) {
        s.clear(); // 가로줄 확인
        s2.clear(); // 세로줄 확인
        for(int j=stX; j<stX+n; j++) {
            s.insert(board[i][j]);
            s2.insert(board[j][i]);
        }
        if(n != s.size() || n != s2.size()) {
            return false;
        }
    }
    return true;
}

bool verify2(int stY, int stX) { // 3x3 확인
    set<int> s;
    for(int i=stY; i<stY+3; i++) {
        for(int j=stX; j<stX+3; j++) {
            s.insert(board[i][j]);
        }
    }
    if(s.size() != 9) {
        return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cout << '#' << test_case << ' ';
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                cin >> board[i][j];
            }
        }
        bool check = false;
        if(!verify(0, 0, 9)) { // 9x9가 유효한지 확인
            cout << 0 << '\n';
            check = true;
        }
        for(int stY=0; stY<=6; stY+=3) { // 3x3의 가능한 시작점 순회
            for(int stX=0; stX<=6; stX+=3) {
                if(!verify2(stY, stX)) {
                    cout << 0 << '\n';
                    check = true;
                    break;
                }
            }
            if(check)   break;
        }
        if(!check) { // 유효할 경우
            cout << 1 << '\n';
        }
    }
    return 0;
}

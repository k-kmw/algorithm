#include <bits/stdc++.h>

using namespace std;

int n;
int m;

bool isFinish(vector<string> board, char turn) {
    for(int i=0; i<3; i++) {
        if(board[i][0] == turn && board[i][1] == turn && board[i][2] == turn) {
            return true;
        }

        if(board[0][i] == turn && board[1][i] == turn && board[2][i] == turn) {
            return true;
        }
    }

    if(board[0][0] == turn && board[1][1] == turn && board[2][2] == turn)   return true;
    if(board[0][2] == turn && board[1][1] == turn && board[2][0] == turn)   return true;

    return false;
}

int solution(vector<string> board) {
    int answer = 1;
    n = board.size();
    m = board[0].size();

    int p1 = 0;
    int p2 = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(board[i][j] == 'O') {
                p1++;
            } else if(board[i][j] == 'X') {
                p2++;
            }
        }
    }

    if(p1 < p2) {
        return 0;
    }

    // O로 끝나는지 확인
    bool isPlayer1Win = isFinish(board, 'O');

    bool isPlayer2Win = isFinish(board, 'X');

    if(p1 < p2) { // 후공이 더 많을 경우
        return 0;
    }

    if(isPlayer1Win && isPlayer2Win) { // 둘 다 이기는 경우는 없으므로
        return 0;
    }

    if(isPlayer1Win && p1 == p2+1) { // 선공이 이길 경우, O의 개수가 X의 개수보다 1개 많아야 함
        return 1;
    }

    if(isPlayer2Win && p1 == p2) { // 후공이 이길 경우 O의 개수와 X의 개수는 같아야 함
        return 1;
    }

    if(!isPlayer1Win && !isPlayer2Win && (p1 - p2 == 0 || p1 - p2 == 1)) { // 게임이 끝나지 않은 경우, O의 개수는 X의 개수보다 많거나 같아야 함
        return 1;
    }

    return 0;
}
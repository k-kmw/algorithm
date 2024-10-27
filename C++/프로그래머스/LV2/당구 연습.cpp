#include <bits/stdc++.h>

using namespace std;

int getMin(int m, int n, int startX, int startY, vector<int> ball) {
    int x1 = startX;
    int y1 = startY;

    int x2 = ball[0];
    int y2 = ball[1];

    int mn = INT_MAX;

    // 1. (0, y)
    if(!(y1 == y2 && x1 > x2)) {
        int x = -x1;
        int y = y1;
        int distSquare = pow(x - x2, 2) + pow(y - y2, 2);
        mn = min(mn, distSquare);
    }

    // 2. (m, y)
    if(!(y1 == y2 && x1 < x2)) {
        int x = m + (m - x1);
        int y = y1;
        int distSquare = pow(x - x2, 2) + pow(y - y2, 2);
        mn = min(mn, distSquare);
    }

    // 3. (x, 0)
    if(!(x1 == x2 && y1 > y2)) {
        int x = x1;
        int y = -y1;
        int distSquare = pow(x - x2, 2) + pow(y - y2, 2);
        mn = min(mn, distSquare);
    }

    // 4. (x, n)
    if(!(x1 == x2 && y1 < y2)) {
        int x = x1;
        int y = n + (n - y1);
        int distSquare = pow(x - x2, 2) + pow(y - y2, 2);
        mn = min(mn, distSquare);
    }
    return mn;
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;

    for(auto ball : balls) {
        answer.push_back(getMin(m, n, startX, startY, ball));
    }
    return answer;
}
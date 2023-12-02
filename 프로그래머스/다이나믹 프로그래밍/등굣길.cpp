#include <bits/stdc++.h>

using namespace std;

// 오른쪽과 아래쪽으로만 움직여 
// 집에서 학교까지 갈 수 있는 최단경로의 개수를 1,000,000,007로 나눈 나머지를 return
// m x n = m열 n행
int d[101][101];
int solution(int m, int n, vector<vector<int>> puddles) {
    int asnwer = 0;

    for(auto p : puddles) {
        d[p[1]-1][p[0]-1] = -1;
    }

    for(int i=1; i<m; i++) {
        if(d[0][i] == -1) {
            break;
        }
        d[0][i] = 1;
    }

    for(int i=1; i<n; i++) {
        if(d[i][0] == -1) {
            break;
        }
        d[i][0] = 1;
    }

    for(int i=1; i<n; i++) {
        for(int j=1; j<m; j++) {
            if(d[i][j] == -1)   continue;
            d[i][j] = (max(d[i-1][j], 0) + max(d[i][j-1], 0)) % 1000000007;
        }
    }
    return d[n-1][m-1];
}
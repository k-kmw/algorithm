#include <bits/stdc++.h>

using namespace std;
int d[501][501];
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int n = triangle.size();
    d[0][0] = triangle[0][0];
    for(int i=1; i<n; i++) {
        for(int j=0; j<triangle[i].size(); j++) {
            if(j==0) {
                d[i][j] = triangle[i][j] + d[i-1][j];
            } else {
                d[i][j] = triangle[i][j] + max(d[i-1][j-1], d[i-1][j]);
            }
        }
    }
    answer = *max_element(d[n-1], d[n-1]+n);
    return answer;
}
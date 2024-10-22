#include<bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    int n = targets.size();
    sort(targets.begin(), targets.end());

    int base = targets[0][1];
    int cnt = 1;
    for(int i=1; i<n; i++) {
        if(targets[i][0] >= base) {
            cnt++;
            base = targets[i][1];
        }
        if(targets[i][1] < base) {
            base = targets[i][1];
        }
    }
    answer = cnt;

    return answer;
}
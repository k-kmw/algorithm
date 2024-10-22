#include<bits/stdc++.h>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;

    for(int y=1; y<=r2; y++) {
        long long x1 = (long long)ceil(sqrt((long long)pow(r1, 2) - (long long)pow(y, 2)));
        long long x2 = (long long)floor(sqrt((long long)pow(r2, 2) - (long long)pow(y, 2)));
        if(x1 < 0) {
            x1 = 0;
        }
        answer += (x2 - x1 + 1);
    }

    answer *= 4;

    return answer;
}
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer = {0, 1000000};
    int n = sequence.size();

    int p1 = 0;
    int p2 = 0;
    int sum = 0;

    for(int i=0; i<n; i++) {

        sum += sequence[p2++];
        while(sum > k) {
            sum -= sequence[p1++];
        }
        if(sum == k) {
            if(answer[1] - answer[0] > p2 - p1 - 1) {
                answer = {p1, p2-1};
            }
        }
    }
    return answer;
}
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer = {0, 1000000};
    int n = sequence.size();

    int p1 = 0;
    int p2 = 0;
    int sum = sequence[0];

    while(p1 < n && p2 < n) { // p1이 p2보다 커질수 없다 (k >= 5)

        if(sum == k) { // 합이 k와 같으면
            if(answer[1] - answer[0] > p2 - p1) { // 더 짧은 수열을 선택
                answer[0] = p1;
                answer[1] = p2;
            }
            sum -= sequence[p1++]; // 더 짧은 수열 탐색
        } else if(sum < k) { // 합이 k보다 작으면
            sum += sequence[++p2]; // 수열에 원소 하나 추가
        } else if (sum > k) { // 합이 k보다 크면
            sum -= sequence[p1++]; // 수열에 원소 하나 제거
        }
    }
    return answer;
}
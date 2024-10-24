#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer = {0, 1000000};  // 가장 큰 값으로 초기화
    int n = sequence.size();

    int p1 = 0, p2 = 0;
    int sum = sequence[0];  // 첫 번째 값으로 sum 초기화

    while (p1 < n && p2 < n) {
        if (sum == k) {
            // 부분 수열의 길이가 더 짧은 경우 업데이트
            if (p2 - p1 < answer[1] - answer[0]) {
                answer[0] = p1;
                answer[1] = p2;
            }
            // 시작 인덱스를 앞으로 이동하여 더 짧은 수열을 찾음
            sum -= sequence[p1++];
        } else if (sum < k) {
            // 합이 작으면 p2를 늘려서 더 많은 원소를 포함
            if (++p2 < n) {
                sum += sequence[p2];
            }
        } else {
            // 합이 크면 p1을 늘려서 원소를 제외
            sum -= sequence[p1++];
        }
    }

    return answer;
}
#include <bits/stdc++.h>

using namespace std;
// 1번 수포자가 찍는 방식: 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ...
// 2번 수포자가 찍는 방식: 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, ...
// 3번 수포자가 찍는 방식: 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ...
// 가장 많은 문제를 맞힌 사람이 누구인지 배열에 담아 return
int correct[3];
vector<vector<int>> sol = {{1, 2, 3, 4, 5},
                           {2, 1, 2, 3, 2, 4, 2, 5},
                           {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
};
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    for(int i=0; i<answers.size(); i++) {
        if(answers[i] == sol[0][i%sol[0].size()])   correct[0]++;
        if(answers[i] == sol[1][i%sol[1].size()]) correct[1]++;
        if(answers[i] == sol[2][i%sol[2].size()])   correct[2]++;
    }
    int mx = *max_element(correct, correct+3);
    for(int i=0; i<3; i++) {
        if(mx == correct[i])    answer.push_back(i+1);
    }
    return answer;
}
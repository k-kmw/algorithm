#include <bits/stdc++.h>

using namespace std;

// begin -> target으로 변환하는 가장 짧은 변환 과정 찾기
// 1. 한 번에 한 개의 알파벳만 바꿀 수 있습니다.
// 2. words에 있는 단어로만 변환할 수 있습니다.
// 두 개의 단어 begin, target과 단어의 집합 words가 매개변수로 주어질 때, 
// 최소 몇 단계의 과정을 거쳐 begin을 target으로 변환할 수 있는지 return 
bool vis[51];
int answer = 51;
int tmp;

void dfs(int idx, vector<string> words, string target) {
    // cout << words[idx] << '\n';
    if (words[idx] == target) {
        answer = min(answer, tmp);
        return;
    }

    for (int i=0; i<words.size(); i++) {
        if(vis[i])  continue;
        int cnt = 0;
        for (int j=0; j<words[idx].length(); j++) {
            if(words[i][j] == words[idx][j])
                cnt++;
        }
        if (cnt < target.length()-1)    continue;
        tmp++;
        vis[i] = true;
        dfs(i, words, target);
        tmp--;
        vis[i] = false;
    }
}

int solution(string begin, string target, vector<string> words) {

    // 백트래킹하면 되겠다
    // 1. 모든 words의 단어 순회하면서 조건 만족하는지 검사
    // 2. 만족하면 방문 표시 남기고 계속 탐색
    // 3. 만족 안하면 종료
    for(int i=0; i<words.size(); i++) {
        int cnt = 0;
        for(int j=0; j<begin.length(); j++) {
            if(words[i][j] == begin[j])
                cnt++;
        }
        if (cnt < begin.length()-1)    continue;
        vis[i] = true;
        tmp++;
        dfs(i, words, target);
        vis[i] = false;
        tmp--;
    }
    if (answer == 51) {
        return 0;
    }
    return answer;
}
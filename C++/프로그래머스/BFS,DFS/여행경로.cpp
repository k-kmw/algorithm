#include <bits/stdc++.h>

using namespace std;

// 항상 "ICN" 공항에서 출발
// 방문하는 공항 경로를 배열에 담아 return

// 모든 공항은 알파벳 대문자 3글자
// 공항수 n=10^4
// [a, b]는 a공항 -> b공항
// 주어진 항공권 모두 사용해야 함
// 가능한 경로가 2개 이상 -> 알파벳 순서
// 가능한 티켓 수 10000 * 9999 = 약 10^8
vector<string> answer;
vector<string> tmp;
bool vis[100000000];

bool check() {
    for(int i=0; i<tmp.size(); i++) {
        if (tmp[i] < answer[i]) return true;
        else if (tmp[i] > answer[i])    return false;
    }
    return false;
}

void dfs(int k, vector<vector<string>> tickets) {
    if (tmp.size() == tickets.size()) {
        tmp.push_back(tickets[k][1]); // 마지막 도시
        if (!answer.empty()) { // 첫 번째 경로
            if (check()) {
                answer.clear();
                for (int i=0; i<=tickets.size(); i++) {
                    answer.push_back(tmp[i]);
                }
            }
        }
        else { // 두번째부터 현재 경로와 비교
            for (int i=0; i<=tickets.size(); i++) {
                answer.push_back(tmp[i]);
            }
        }
        tmp.pop_back(); // 마지막 도시 backtrack
        return;
    }

    for (int i=0; i<tickets.size(); i++) {
        if (vis[i]) continue;
        if(tickets[k][1] != tickets[i][0])  continue;
        vis[i] = true;
        tmp.push_back(tickets[k][1]);
        dfs(i, tickets);
        vis[i] = false;
        tmp.pop_back();
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    for(int i=0; i<tickets.size(); i++) {
        if(tickets[i][0] == "ICN") {
            tmp.push_back(tickets[i][0]);
            vis[i] = true;
            dfs(i, tickets);
            vis[i] = false;
            tmp.pop_back();
        }
    }

    return answer;
}
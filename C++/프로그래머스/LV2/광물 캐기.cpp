#include<bits/stdc++.h>

using namespace std;

vector<int> selected;
map<string, int> nameToIdx;
int table[3][3] = {{1, 1, 1}, {5, 1, 1}, {25, 5, 1}};
int answer = INT_MAX;
int n, m;
int tot;

void dfs(vector<int> picks, vector<string> minerals, int k) {
    if(k*5 >= n || k == tot) {
        int res = 0;
        int idx = 0;
        for(int i=0; i<n; i++) {
            int pickIdx = selected[idx];
            string mineral = minerals[i];
            int mineralIdx = nameToIdx[mineral];
            res += table[pickIdx][mineralIdx];
            if((i+1) % 5 == 0) {
                idx++;
            }
            if(idx == selected.size()) {
                break;
            }
        }
        answer = min(answer, res);
        return;
    }

    for(int i=0; i<3; i++) {
        if(picks[i] == 0)   continue;
        selected.push_back(i);
        picks[i]--;
        dfs(picks, minerals, k+1);
        picks[i]++;
        selected.pop_back();
    }
}

int solution(vector<int> picks, vector<string> minerals) {

    // 5번마다 곡괭이를 선택 => 50 / 5 = 10 => 3^10
    n = minerals.size();
    m = picks.size();
    nameToIdx.insert({"diamond", 0});
    nameToIdx.insert({"iron", 1});
    nameToIdx.insert({"stone", 2});

    for(int i=0; i<m; i++) {
        tot += picks[i];
    }

    dfs(picks, minerals, 0);
    return answer;
}
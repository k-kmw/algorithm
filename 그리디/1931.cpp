#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int >> sel;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.second < b.second)   return true;
    else if(a.second == b.second) return a.first < b.first;
    else return false;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> schedule(n);
    for (int i = 0; i < n; i++)
        cin >> schedule[i].first >> schedule[i].second;

    sort(schedule.begin(), schedule.end(), cmp);

    sel.emplace_back(schedule[0]);
    for (int i = 1; i < n; i++) {
        if (((sel.back().second) <= schedule[i].first)) {
            sel.push_back(schedule[i]);
        }
    }

//    for (auto & i : sel) {
//        cout << i.second << ' ' << i.first << '\n';
//    }
    cout << sel.size();
}

// 여러 풀이 생각해보기
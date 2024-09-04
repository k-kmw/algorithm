#include <bits/stdc++.h>
using namespace std;
pair<int, int> home[7];
pair<int, int> rest[7];
vector<int> path;
vector<int> pathTmp;
int index;
int dist;
int tmp;
int cnt;
int n;
bool isused[7];

int getDist(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void dfs(int k) {
    if(cnt > 2) {
        index = 0;
        tmp = 0;
        return;
    } // dead branch

    if(k == 2*n && tmp < dist) {
        for(int i=0; i<=2*n; i++ ){
            path[i] = pathTmp[i];
        }
        index = 0;
        dist = tmp;
        tmp = 0;
        return;
    } // finish branch. candidate

    for(int i=1; i<=n; i++) {
        if(k == 0) { // 첫번째 방문할 식당
            tmp += getDist(pair<int, int>(500, 500), rest[i]);
            isused[i] = true;
            cnt++;
            pathTmp[index] = i;
        }

        else if(isused[i] && cnt != 0){ // 식당 -> 집의 경우
            tmp += getDist(rest[i], home[i]);
            cnt--;
            pathTmp[index] = -i;
        }

        else if(cnt == 1 && !isused[i] && i < n) { // 식당 -> 식당의 경우
            tmp += getDist(rest[i], rest[i+1]);
            isused[i] = true;
            cnt++;
            pathTmp[index] = i;
        }
        else { // cnt == 0 && !isused[i]
            tmp += getDist(home[pathTmp[index]], rest[i]);
            cnt++;
            pathTmp[index] = i;
        }
        index++;
        dfs(k+1);
        isused[i] = false;
        index--;
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> rest[i].first >> rest[i].second  >> home[i].first >> home[i].second;

    dfs(0);
    cout << dist;
}
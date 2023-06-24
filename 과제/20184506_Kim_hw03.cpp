#include <bits/stdc++.h>
using namespace std;
pair<int, int> home[7]; // i 번째 집의 좌표 저장
pair<int, int> rest[7]; // i 번쨰 식당의 좌표 저장
int path[14]; // 최종 최단거리 path를 저장할 배열
int pathTmp[14]; // 각 dfs마다 임시로 path를 저장할 배열
int dist = 2*6*1000*1000; // 초기 거리를 나올 수 있는 경우의 수의 최대 값보다 크도록 설정
int cnt; // 배달원이 가지고 있는 아이템 수를 나타냄
int n; // 배달할 집의 개수
bool isDelivered[7]; // i 번째 집이 배달이 완료되었는지 나타냄
bool bag[7]; // i 번째 집의 아이템을 배달원이 픽업했는지 나타냄
int a;

int getDist(const int arr[]) { // path를 인자로 받아 거리를 리턴 해주는 함수
    int tmp = 0; // 거리를 저장할 변수
    int prior = arr[0]; // 이전에 방문한 곳을 저장
    tmp += abs(500-rest[prior].first) + abs(500-rest[prior].second);
    for(int i=1; i<2*n; i++) {
        int idx = arr[i];
        if(idx > 0 && prior > 0) { // 식당 -> 식당
            tmp += abs(rest[idx].first - rest[prior].first) + abs(rest[idx].second - rest[prior].second);
        }
        else if(idx > 0 && prior < 0) { // 집 -> 식당
            tmp += abs(rest[idx].first - home[-prior].first) + abs(rest[idx].second - home[-prior].second);
        }
        else if(idx < 0 && prior > 0) { // 식당 -> 집
            tmp += abs(home[-idx].first - rest[prior].first) + abs(home[-idx].second - rest[prior].second);
        }
        else { // 집 -> 집
            tmp += abs(home[-idx].first - home[-prior].first) + abs(home[-idx].second - home[-prior].second);
        }
        prior = arr[i];
    }
    return tmp;
}

void dfs(int k) {
    if(cnt > 2) { //
        return ;
    }
    if(k == 2*n) { // k == 2*n 즉, 집과 식당의 n개의 쌍을 모두 방문
        int tmp = getDist(pathTmp); // 이번에 구한 경로의 거리를 구함
        if(tmp <= dist) { // 구한 거리를 dist와 비교
            bool flag = false; // 사전식으로 출력하기 위한 변수
            if(tmp == dist) { // tmp와 dist가 같은 경우
                for(int i=0; i<k; i++) { // 사전식인지 확인
                    if(path[i] > pathTmp[i]) { // 사전식이 아니면 flag = true
                        flag = true;
                        break;
                    }
                    else if(path[i] < pathTmp[i]) { // 이미 사전식이면
                        flag = false;
                        break;
                    }
                    else // 배열의 같은 자리에 숫자가 같을 경우, 뒤의 원소를 확인
                        continue;
                }
            }
            else { // tmp < dist 인 경우
                flag = true;
            }
            dist = tmp;
            if(flag) { // flag가 true일때만 path를 업데이트
                for(int i=0; i<k; i++) {
                    path[i] = pathTmp[i];
                }
            }
        }
        return; // dfs return
    }

    for(int i=1; i<=n; i++) {
        if(k == 0) { // 처음 픽업 식당
            pathTmp[k] = i;
            bag[i] = true; // i 번째 아이템을 가방에 넣음
            cnt++; // 아이템 수 증가
        }
        // 사전순으로 출력하기 위해 -숫자 먼저 출력하도록 순서를 정함
        else if(bag[i]) { // 가방에 아이템이 있으면 배달
            pathTmp[k] = -i; // 방문하는 집의 번호를 저장
            isDelivered[i] = true; // 이미 완료한 집의 배달 표시
            bag[i] = false; // i번 집의 food를 false로 바꿔줌
            cnt--;
        }
        else if(!isDelivered[i] && !bag[i] && cnt < 2) { // 배달 완료되지 않은 것 중 food가 가방에 없고 cnt < 2이면 food 픽업
            pathTmp[k] = i; // 방문하는 식당의 번호를 저장
            bag[i] = true; // i 번째의 아이템을 가방에 넣음
            cnt++;
        }
        else { // 위 케이스에 해당하지 않으면
            continue;
        }
        dfs(k+1); // 다음 노드 방문
        // dfs 리턴 후 원상 복구
        if(pathTmp[k] > 0) { // 식당을 원상 복구 하므로
            bag[pathTmp[k]] = false; // 가방에서 물건 제거
            cnt--; // 개수 감소
        }
        else { // 집을 원상 복구하므로
            bag[-pathTmp[k]] = true; // 배달한 아이템을 가방에 다시 넣음
            isDelivered[-pathTmp[k]] = false; // 배달 완료 표시를 지움
            cnt++; // 개수 증가
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> rest[i].first >> rest[i].second  >> home[i].first >> home[i].second;

    dfs(0);
    for(int i=0; i<2*n; i++) {
        cout << path[i] << ' ';
    }
    cout << '\n';
    cout << dist;
    cout << '\n';
    cout << a;
}
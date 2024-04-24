#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> tree[10005]; // 인덱스를 번호로 하는 노드의 왼쪽 자식과 오른쪽 자식
int wide[10005][2]; // wide[i][0]: 시작 인덱스, wide[i][1] 끝 인덱스
bool vis[10005]; // 해당 열이 방문되었는지 확인
int p[10005]; // root 노드 찾기 위한 부모 배열

// 중위 순회
void in_order(int v, int depth) {
    if(v == -1) {
        return;
    }
    in_order(tree[v].first, depth+1);
    for(int i=1; i<=n; i++) {
        if(!vis[i]) { // 해당 열을 채우지 않았으면
            if(wide[depth][0] == 0) { // 해당 행에 첫 번째로 나오는 노드이면
                wide[depth][0] = i; // 열 번호 저장
            }
            wide[depth][1] = i; // 노드가 나올 때마다 마지막 인덱스를 갱신
            vis[i] = true; // 해당 열을 방문 처리
            break;
        }
    }
    in_order(tree[v].second, depth+1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1. 트리 생성. pair<int, int> p[10005]
    // 2. 중위 순회 하면서 트리를 테이블에 채우기
    // 3. 1행부터 logN행 까지 순회 하면서 너비 계산, 최대값 갱신

    cin >> n;
    for(int i=0; i<n; i++) {
        int root, left, right;
        cin >> root >> left >> right;
        p[left] = root;
        p[right] = root;
        tree[root].first = left;
        tree[root].second = right;
    }

    // root 노드 찾기
    int stNode = 1;
    for(int i=1; i<=n; i++) {
        if(p[i] == 0) {
            stNode = i;
            break;
        }
    }

    in_order(stNode, 1);

    int mx = 0;
    int mxIdx = 1;
    for(int i=n; i>=1; i--) {
        int width = wide[i][1] - wide[i][0] + 1;
        if(mx <= width) {
            mx = width;
            mxIdx = i;
        }
    }

    cout << mxIdx << ' ' << mx << '\n';

//    for(int i=1; i<=n; i++) {
//        for(int j=1; j<=n; j++) {
//            cout << table[i][j] << ' ';
//        }
//        cout << '\n';
//    }
}
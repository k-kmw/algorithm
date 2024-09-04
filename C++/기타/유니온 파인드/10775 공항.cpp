#include <bits/stdc++.h>
using namespace std;

int G, P;
int p[100005];
int cnt;

void make_set() {
    for(int i=0; i<=G; i++) {
        p[i] = i;
    }
}

int find(int a) {
    if(a == p[a])   return a;
    return p[a] = find(p[a]);
}

void merge(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    if(rootA == rootB)  return;
    p[rootA] = rootB;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1. find(gi)가 사용 중이 아니면 도킹
    // 2. union(gi, gi-1)
    cin >> G >> P;
    make_set();
    for(int i=0; i<P; i++) {
        int g;
        cin >> g;
        int root = find(g); // root를 얻어서 root가 도킹할 수 있는 곳 중 가장 큰 번호
        if(root == 0) { // 1번 게이트에 도킹되었다면, 1번 게이트의 root는 0번.
            break; // 즉 0번이 도킹할 수 있는 가장 큰 번호가 되면 종료
        }
        merge(root, root-1); // 번호가 작은 것을 root로 하여 union
        cnt++;
    }
    cout << cnt << '\n';
}
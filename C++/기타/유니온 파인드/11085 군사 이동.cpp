#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int u, v, w;
    Edge(int u, int v, int w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
    bool operator < (const Edge& a) const {
        return this->w > a.w;
    }
};

int p, w;
int c, v;
vector<Edge> edges;
int parent[1005];

void make_set() {
    for(int i=0; i<p; i++) {
        parent[i] = i;
    }
}

int find(int n) {
    if(n == parent[n])   return n;
    return parent[n] = find(parent[n]);
}

void merge(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    if(rootA == rootB)  return;
    parent[rootA] = rootB;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1. 간선을 내림차순으로 정렬
    // 2. 순서대로 두 개의 지점을 union
    // 3. union한 후 Baekjoon World와 Cube World가 연결되었는지 확인
    // 4. 연결되었다면 가장  최근에 연결한 간선의 가중치 출력
    cin >> p >> w;
    cin >> c >> v;
    for(int i=0; i<w; i++) {
        int st, en, width;
        cin >> st >> en >> width;
        edges.push_back(Edge(st, en, width));
    }
    sort(edges.begin(), edges.end());

    make_set();
    for(auto edge : edges) {
        merge(edge.v, edge.u);
        if(find(c) == find(v)) {
            cout << edge.w << '\n';
            break;
        }
    }
}
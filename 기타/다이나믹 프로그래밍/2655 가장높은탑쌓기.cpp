#include <bits/stdc++.h>
using namespace std;

class Brick {
public:
    int area, height, weight, idx;
    Brick() = default;
    Brick(int area, int height, int weight, int idx) {
        this->area = area;
        this->height = height;
        this->weight = weight;
        this->idx = idx;
    }
    bool operator < (const Brick& a) const {
        return this->area > a.area;
    }
};

Brick bricks[101];
int d[101]; // d[i]: i를 맨 위의 벽돌로 했을 때 높이의 최대값
int pre[101];
vector<int> ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        int a, h, w;
        cin >> a >> h >> w;
        bricks[i] = Brick(a, h, w, i);
    }
    sort(bricks+1, bricks+1+n);

    int mx = 0;
    int lastIdx = 0;
    for(int i=1; i<=n; i++) {
        int best = bricks[i].height;
        int bestIdx = 0;
        for(int j=i-1; j>0; j--) {
            if(bricks[i].weight < bricks[j].weight) {
                if(bricks[i].height + d[j] > best) {
                    bestIdx = j;
                    best = bricks[i].height + d[j];
                }
            }
        }
        d[i] = best;
        pre[i] = bestIdx;
        if(d[i] > mx) {
            mx = d[i];
            lastIdx = i;
        }
    }

    int prior = lastIdx;
    while(prior != 0) {
        ans.push_back(bricks[prior].idx);
        prior = pre[prior];
    }

    cout << ans.size() << '\n';
    for(int a : ans) {
        cout << a << '\n';
    }

//    for(int i=1; i<=n; i++) {
//        cout << bricks[i].area << '\n';
//    }
    return 0;
}
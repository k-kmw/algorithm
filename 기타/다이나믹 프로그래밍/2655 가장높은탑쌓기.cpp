#include <bits/stdc++.h>
using namespace std;

class Brick {
public:
    int area, height, weight;
    Brick() = default;
    Brick(int area, int height, int weight) {
        this->area = area;
        this->height = height;
        this->weight = weight;
    }
    bool operator < (const Brick& a) {
        return this->area > a.area;
    }
};

class Trace {
public:
    vector<Brick> bricks;
    int height;
};

vector<Brick> bricks;
Trace d[105][2]; // d[i][0] i번째 상자 담지 않았을 때 높이 최대, d[i][1] i번째 상자 담았을 때 높이 최대
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        int a, h, w;
        cin >> a >> h >> w;
        bricks.push_back(Brick(a, h, w));
    }
    sort(bricks.begin(), bricks.end());

    d[0][1].bricks.push_back(bricks[0]);
    d[0][1].height = bricks[0].height;
    d[0][0].height = INT_MAX;
    //
    for(int i=1; i<n; i++) {

        // 1. 이전 못쌓고, 현재는 쌓는 경우
        int sz = d[i-1][0].bricks.size();
        if(i == 1 && sz == 0) {
            d[i][1].bricks.push_back(bricks[i]);
            d[i][1].height = bricks[i].height;
        }
        else if(sz > 0 && d[i-1][0].bricks[sz-1].weight > bricks[i].weight) {
            cout << i << ' ' << d[i][1].height << '\n';
            d[i][1].bricks.push_back(bricks[i]);
            d[i][1].height = d[i-1][0].height + bricks[i].height;
        }
        // 2. 이전 쌓고, 현재도 쌓을 수 있는 경우
        sz = d[i-1][1].bricks.size();
        if(sz > 0 && d[i-1][1].bricks[sz-1].weight > bricks[i].weight) {
            d[i][1].bricks = vector(d[i-1][1].bricks);
            d[i][1].bricks.push_back(bricks[i]);
            d[i][1].height = d[i-1][1].height + bricks[i].height;
        }

        // 3. 이전 못쌓고, 현재도 못 쌓는 경우
        sz = d[i-1][0].bricks.size();
        if(sz > 0 && d[i-1][0].bricks[sz-1].weight < bricks[i].weight) {
            d[i][0].bricks = vector(d[i-1][0].bricks);
            d[i][0].bricks = vector(d[i-1][0].bricks);
            d[i][0].height = d[i-1][0].height;
        }

        // 4. 이전 쌓고, 현재는 못 쌓는 경우
        sz = d[i-1][1].bricks.size();
        if(sz > 0 && d[i-1][1].bricks[sz-1].weight < bricks[i].weight) {
            d[i][0].bricks = vector(d[i-1][1].bricks);
            d[i][1].height = d[i-1][1].height;
        }
    }

    cout << d[n-1][1].height << '\n';
//    for (const auto &item: bricks) {
//        cout << item.area << '\n';
//    }
}
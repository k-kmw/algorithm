#include <bits/stdc++.h>
using namespace std;

bool vis[1001][1001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A, B, C;
    cin >> A >> B >> C;
    int sum = A + B + C;

    if(sum % 3 != 0) {
        cout << 0;
        return 0;
    }

    vis[A][B] = true;
    queue< pair<int, int> > q;
    q.push(make_pair(A, B));
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        int a = cur.first;
        int b = cur.second;
        int tmp[] = {a, b, sum - (a+b)};
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(tmp[i] < tmp[j]) {
                    int num1 = tmp[i]*2;
                    int num2 = tmp[j]-tmp[i];
                    if(num1 > 1000 || num2 > 1000) continue;
                    if(vis[num1][num2]) continue;
                    vis[num1][num2] = true;
                    q.push(make_pair(num1, num2));
                }
            }
        }
    }
    if(vis[sum/3][sum/3]) {
        cout << 1;
    } else {
        cout << 0;
    }
}
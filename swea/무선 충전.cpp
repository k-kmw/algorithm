#include <bits/stdc++.h>
using namespace std;

class BC {
public:
    int x, y, c, p;
    BC(int x, int y, int c, int p) {
        this->x = x;
        this->y = y;
        this->c = c;
        this->p = p;
    }
};

int adir[101];
int bdir[101];
int dx[] = {0, 0, 1, 0, -1};
int dy[] = {0, -1, 0, 1, 0};
bool visA[101];
bool visB[101];
int ans;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1. 매초마다 2명의 이용자를 이동시킨다.
    // 2. bc를 순회하며 2명의 이용자가 포함되어 있는 bc를 표시한다.
    // 3. 가능한 bc조합을 순회하며 최대값을 갱신한다. => 2개를 선택하는 것이므로 2중 for문
    int T;
    cin >> T;
    for(int test_case=1; test_case<=T; test_case++) {
        int userAx = 1;
        int userAy = 1;
        int userBx = 10;
        int userBy = 10;
        vector<BC> bcs;
        ans = 0;
        int m, a;
        cin >> m >> a;
        adir[0] = 0;
        bdir[0] = 0;
        for(int i=1; i<=m; i++) {
            cin >> adir[i];
        }
        for(int i=1; i<=m; i++) {
            cin >> bdir[i];
        }

        for(int i=0; i<a; i++) {
            int x, y, c, p;
            cin >> x >> y >> c >> p;
            bcs.push_back(*new BC(x, y, c, p));
        }

        for(int i=0; i<=m; i++) { // 사용자를 이동
            userAx += dx[adir[i]];
            userAy += dy[adir[i]];
            userBx += dx[bdir[i]];
            userBy += dy[bdir[i]];


            fill(visA, visA+a, false);
            fill(visB, visB+a, false);
            for(int j=0; j<bcs.size(); j++) {
                if(abs(userAx - bcs[j].x) + abs(userAy - bcs[j].y) <= bcs[j].c) {
                    visA[j] = true;
                }
                if(abs(userBx - bcs[j].x) + abs(userBy - bcs[j].y) <= bcs[j].c) {
                    visB[j] = true;
                }
            }

            // 사용자1, 사용자2 모두 같은 bc에 있는 경우
            // 사용자1만 bc 위에 있는 경우
            // 사용자2만 bc 위에 있는 경우
            // 사용자1과 사용자2가 다른 bc 위에 있는 경우
            // 둘 다 bc 위에 없는 경우
//            cout << userAx << " " << userAy << '\n';
//            cout << userBx << " " << userBy << '\n';
            int mx = 0;
            for(int k=0; k<a; k++) {
                for(int l=0; l<a; l++) {
                    int sum = 0;
                    if(k == l && visA[k] && visB[l]) { // 사용자1, 사용자2가 같은 bc에 있는 경우
                        sum = bcs[k].p; // 두 명 합친거
                    } else {
                        if(visA[k] && !visB[l]) {
                            sum = bcs[k].p;
                        } else if(!visA[k] && visB[l]) {
                            sum = bcs[l].p;
                        } else if(visA[k] && visB[l]) {
                            sum = bcs[k].p + bcs[l].p;
                        }
                    }
                    mx = max(mx, sum);
                }
            }
//            cout << mx << '\n';
            ans += mx;
        }
        cout << "#" << test_case << " " << ans << '\n';
    }
}
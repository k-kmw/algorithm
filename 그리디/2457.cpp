#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> f;
#define X first
#define Y second

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        int sm, sd, em, ed;
        cin >> sm >> sd >> em >> ed;
        f.emplace_back(sm*100+sd, em*100+ed);
    }

    sort(f.begin(), f.end());
    int cnt = 0;
    int st = 101;
    int en = 301;
    int tmp = 0;
    bool update = false;
    for(int i=0; i<n; i++) {

        if(en >= 1130) { // 1130이 넘으면 cnt 출력하고 종료
            cout << cnt;
            return 0;
        }
//        cout << i << ' ' << f[i].X << ' ' << f[i].Y << '\n';
        if(st <= f[i].X && f[i].X <= en) { // 시작점이 st와 en사이이면 모두 동일하다고 볼 수 있고, 끝나는 시간이 가장 큰 것을 찾음
            tmp = max(f[i].Y, tmp);
        }
        else if(!update){ // 현재 i의 -1까지 가장 긴 원소를 선택후 st와 en 값 변경 후 현재 i로 for문 재수행
            cnt++;
            st = en;
            en = tmp;
//            cout << st << ' ' << en << '\n';
            update = true;
            i--;
            continue;
        }
        else {
            cout << 0;
            return 0;
        }
        update = false;

        if(i==n-1) {
            if(tmp != en) {
                cnt++;
                st = en;
                en = tmp;
            }

            if(en >= 1130) {
                cout << cnt;
            }
            else {
                cout << 0;
                return 0;
            }
        }

    }
}

//아직 못품
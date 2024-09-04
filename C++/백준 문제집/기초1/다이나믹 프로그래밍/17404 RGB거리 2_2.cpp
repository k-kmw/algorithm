#include <bits/stdc++.h>
using namespace std;
int rgb[1001][3];
int d[1001][3];
int ans = 1000 * 1001;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
    }

    for (int first = 0; first < 3; first++) { // first를 통해 첫 번째집의 r,g,b를 결정
        for (int i = 0; i < 3; i++) { // i는 r, g, b
            if (first == i) { // 같을 경우 첫 번째 집을 칠함 first:0 => R, first:1 => G, first:2 => B
                d[1][i] = rgb[1][i];
            }
            else { // 다를 경우 최대값을 설정하여 선택에서 제외되도록 함
                d[1][i] = 1000 * 1001;
            }
        }
        for (int i = 2; i <= n; i++) {
            d[i][0] = min(d[i - 1][1], d[i - 1][2]) + rgb[i][0];
            d[i][1] = min(d[i - 1][0], d[i - 1][2]) + rgb[i][1];
            d[i][2] = min(d[i - 1][0], d[i - 1][1]) + rgb[i][2];
        }
        for (int i = 0; i < 3; i++) {
            if (first == i) { // 마지막 색이 첫 번째와 같으면 continue
                continue;
            }
            else { // 첫 번째 집과 마지막 집 색이 다르면 최소값 갱신
                ans = min(ans, d[n][i]);
            }
        }
    }
    cout << ans << '\n';
}
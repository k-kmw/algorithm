#include <bits/stdc++.h>
using namespace std;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> vec(n+m);
        for(int i=0; i<n; i++) {
            int x;
            cin >> x;
            vec[i] = {x, 0}; //A일 경우
        }
        for(int i=n; i<n+m; i++) {
            int x;
            cin >> x;
            vec[i] = {x, 1}; //B일 경우
        }
        sort(vec.begin(), vec.end()); //같은 숫자이면 B가 A뒤로 옴

        int cnt=0; //먹힐 수 있는 B의 개수
        int ans=0;
        for(int i=0; i<n+m; i++) {
            if(vec[i].second == 0) { //현재 A가 나오면
                ans += cnt; //이때까지 나온 B의 개수만큼 A가 먹을 수 있음
            }
            else
                cnt++; //B일 경우 이때까지 나온 B의 개수를 추가
        }
        cout << ans << '\n';
    }
}
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int m;
        cin >> m;
        int mid;
        cin >> mid;
        vector<int> ans;
        ans.push_back(mid); // 첫 번째 수는 중앙값

        // 1. 현재 중앙값 보다 작으면 maxheap에 현재 중앙값 보다 크면 minheap에 넣기
        // 2. 두 힙의 사이즈가 다르면 사이즈가 큰 것의 top을 중앙값으로 업데이트하고, 그걸 빼서 반대편 힙에 넣기
        priority_queue<int, vector<int>, greater<int> > minheap;
        priority_queue<int> maxheap;
        for(int i=1; i<m; i++) {
            int a;
            cin >> a;
            if(mid > a) { // 현재 중앙값 보다 작으면
                maxheap.push(a);
            } else {
                minheap.push(a);
            }

            if(i % 2 != 0) continue;

            if(maxheap.size() > minheap.size()) { // maxheap에서 top을 꺼냄
                minheap.push(mid);
                mid = maxheap.top();
                maxheap.pop();
                ans.push_back(mid);
            } else if(maxheap.size() < minheap.size()) { // minheap에서 top을 꺼냄
                maxheap.push(mid);
                mid = minheap.top();
                minheap.pop();
                ans.push_back(mid);
            } else {
                ans.push_back(mid);
            }
        }

        cout << ans.size() << '\n';
        int cnt = 0;
        for(auto & a : ans) {
            cnt++;
            cout << a << ' ';
            if(cnt % 10 == 0) {
                cout << '\n';
            }
        }
        cout << '\n';
    }
}
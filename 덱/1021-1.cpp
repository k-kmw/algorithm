#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    deque<int> d;
    for(int i=1; i<=n; i++)  d.push_back(i);
    int cnt=0;
    while(m--) {
        int a;
        cin >> a;
        auto idx = find(d.begin(), d.end(), a) - d.begin();
        while(d.front() != a) {
            if(idx <= d.size()/2) { // 원소의 개수가 홀수개 일 때, 생각 해보면 등호가 필요함
                d.push_back(d.front());
                d.pop_front();
            }
            else {
                d.push_front(d.back());
                d.pop_back();
            }
            cnt++;
        }
        d.pop_front();
    }
    cout << cnt;
}
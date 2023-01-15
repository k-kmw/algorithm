#include <iostream>
#include <deque>
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
        int idx=0;
        for(int i=0; i<d.size(); i++) {
            if(d[i] == a) {
                idx = i;
                break;
            }
        }
//        cout << idx;
        if(a == d.front())
            d.pop_front();
        else if(idx > d.size()/2) {
            while(d.size()-idx) {
                int b = d.back();
                d.pop_back();
                d.push_front(b);
                cnt++;
                idx++;
            }
            d.pop_front();
        }
        else {
            while(idx--) {
                int f = d.front();
                d.pop_front();
                d.push_back(f);
                cnt++;
            }
            d.pop_front();
        }
//        for(int i=0; i<d.size(); i++)    cout << d[i] << ' ';
//        cout << cnt;
//        cout << '\n';
    }
    cout << cnt;
}
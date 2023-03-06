#include <bits/stdc++.h>
using namespace std;
string a;
string b;
int d[1001][1001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;
    unsigned int idxa = 0;
    unsigned int idxb = 0;
    int pre = 0;
    while(true) {
        int tmpa = idxa;
        int tmpb = idxb;
        if(a[idxa] == b[idxb]) {
            d[idxa][idxb] = pre+1;
            cout << idxa << ' ' << idxb << ' ' << d[idxa][idxb] << '\n';
            if(idxa < a.size()-1)
                idxa++;
            if(idxb < b.size()-1)
                idxb++;
        }
        else if(idxb < b.size()-1){
            d[idxa][idxb] = pre;
            idxb++;
        }
        else {
            d[idxa][idxb] = pre;
            idxa++;
        }

        if(idxa >= a.size()-1 && idxb >= b.size()-1) {
            if(a[idxa] == b[idxb]) {
                d[idxa][idxb] = pre + 1;
            }
            else
                d[idxa][idxb] = pre;
            break;
        }
        pre = d[tmpa][tmpb];
    }
    int mx;
    int ans = 0;
    for(int i=0; i<a.size(); i++) {
        mx = *max_element(d[i], d[i]+b.size()+1);
        ans = max(ans, mx);
    }
    cout << ans;
}
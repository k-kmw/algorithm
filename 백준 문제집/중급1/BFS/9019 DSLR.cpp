#include <bits/stdc++.h>
using namespace std;

bool vis[10000];
int a, b;

void printResult(string cmd) {
    for(auto c : cmd) {
        cout << c;
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        fill(vis, vis+10000, false);
        vis[a] = true;
        queue< pair<int, string > > q;
        q.push(make_pair(a, ""));

        while(!q.empty()) {
            auto cur = q.front();
            int num = cur.first;
            auto cmd = cur.second;
            q.pop();

            // D
            int d = (num * 2) % 10000;
            if(!vis[d]) {
                if(d == b) {
                    printResult(cmd + "D");
                    break;
                }
                q.push(make_pair(d, cmd + "D"));
                vis[d] = true;
            }

            // S
            int s = num == 0 ? 9999 : num-1;
            if(!vis[s]) {
                if(s == b) {
                    printResult(cmd + "S");
                    break;
                }
                q.push(make_pair(s, cmd + "S"));
                vis[s] = true;
            }

            // L
            int l = (num%1000)*10 + (num/1000);
            if(!vis[l]) {
                if(l == b) {
                    printResult(cmd + "L");
                    break;
                }
                q.push(make_pair(l, cmd + "L"));
                vis[l] = true;
            }

            // R
            int r = (num%10)*1000 + (num/10);
            if(!vis[r]) {
                if(r == b) {
                    printResult(cmd + "R");
                    break;
                }
                q.push(make_pair(r, cmd + "R"));
                vis[r] = true;
            }
        }
    }
}
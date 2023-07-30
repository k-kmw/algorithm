#include <bits/stdc++.h>
using namespace std;
int l, c;
char alpha[16];
vector<char> pwd;

void dfs(int k, int st) {
    if(k == l) {
        int moem = 0; // 모음 개수
        int jaem = 0; // 자음 개수
        for(int i=0; i<pwd.size(); i++) {
            if(pwd[i] == 'a' || pwd[i] == 'e' || pwd[i] == 'i' || pwd[i] == 'o' || pwd[i] == 'u') {
                moem++;
            }
            else {
                jaem++;
            }
            if(moem >= 1 && jaem >= 2)
                break;
        }
        if(moem >= 1 && jaem >= 2) {
            for (const auto &p: pwd) {
                cout << p;
            }
            cout << '\n';
        }
        return;
    }
    for(int i=st; i<c; i++) {
        pwd.push_back(alpha[i]);
        dfs(k+1, i+1);
        pwd.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> l >> c;
    for(int i=0; i<c; i++)  cin >> alpha[i];
    sort(alpha, alpha+c);
    dfs(0, 0);
}
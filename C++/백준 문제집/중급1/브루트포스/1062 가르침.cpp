#include <bits/stdc++.h>
using namespace std;

int n, k;
map<char, bool> alpha;
string words[51];
int ans;

int countReadableWord() {
    int cnt = 0;
    for(int i=0; i<n; i++) {
        bool isReadable = true;
        for(auto& c : words[i]) {
            if(!alpha[c]) {
                isReadable = false;
                break;
            }
        }
        if(isReadable) {
            cnt++;
        }
    }
    return cnt;
}

void dfs(char st, int cnt) {
    if(cnt == k) {
        // 단어 개수 확인
        ans = max(ans, countReadableWord());
        return;
    }

    for(char c=st; c<='z'; c++) {
        if(alpha[c]) continue;
        alpha[c] = true;
        dfs(c+1, cnt+1);
        alpha[c] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    if(k < 5) {
        cout << 0 << '\n';
        return 0;
    }
    for(int i=0; i<n; i++) {
        cin >> words[i];
    }
    // 접두/접미를 구성하는 5개의 글자 가르치기
    alpha['a'] = true;
    alpha['n'] = true;
    alpha['t'] = true;
    alpha['i'] = true;
    alpha['c'] = true;
    k -= 5;
    // 'a'~'z' 중 가르칠 문자 k-5개를 선택
    dfs('a', 0);

    cout << ans;
}
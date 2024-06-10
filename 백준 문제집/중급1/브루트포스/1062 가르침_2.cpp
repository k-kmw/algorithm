#include <bits/stdc++.h>
using namespace std;

int n, k;
int alpha;
int words[51];
int ans;

int countReadableWord() {
    int cnt = 0;
    for(int i=0; i<n; i++) {
        if((words[i] & alpha) == words[i]) {
            cnt++;
        }
    }
    return cnt;
}

void dfs(int st, int cnt) {
    if(cnt == k) {
        // 단어 개수 확인
        ans = max(ans, countReadableWord());
        return;
    }

    for(int i=st; i<26; i++) {
        if(alpha & (1 << i)) continue;
        alpha |= (1 << i);
        dfs(i+1, cnt+1);
        alpha ^= (1 << i);
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
        string word;
        cin >> word;
        for(int j=4; j<word.size()-4; j++) {
            words[i] |= (1 << (word[j] - 'a'));
        }
    }
    // 접두/접미를 구성하는 5개의 글자 가르치기
    alpha |= (1 << ('a' - 'a'));
    alpha |= (1 << ('n' - 'a'));
    alpha |= (1 << ('t' - 'a'));
    alpha |= (1 << ('i' - 'a'));
    alpha |= (1 << ('c' - 'a'));
    k -= 5;

//    for(int i=0; i<26; i++) {
//        cout << (alpha & (1<<i)) / pow(2, i);
//    }
    // 'a'~'z' 중 가르칠 문자 k-5개를 선택
    dfs(0, 0);
    cout << ans;
}
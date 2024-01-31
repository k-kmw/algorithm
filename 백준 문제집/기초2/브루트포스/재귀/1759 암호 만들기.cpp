#include <bits/stdc++.h>
using namespace std;
int l, c;
char a[16];
char ans[16];
//char moeum[] = {'a', 'e', 'i', 'o', 'u'};

bool checkValid() {
    int cnt1 = 0; // 모음의 수
    int cnt2 = 0; // 자음의 수
    for (int i = 0; i < l; i++) {
        if (ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' || ans[i] == 'u') {
            cnt1++;
        }
        else {
            cnt2++;
        }
    }
    if (cnt1 >= 1 && cnt2 >= 2) {
        return true;
    }
    else {
        return false;
    }
}

void dfs(int k, int st) {

    if (k == l) {
        if (checkValid()) {
            for (int i = 0; i < l; i++) {
                cout << ans[i];
            }
            cout << '\n';
        }
        return;
    }

    for (int i = st; i < c; i++) {
        ans[k] = a[i];
        dfs(k + 1, i + 1);
    }
}

int main() {

    cin >> l >> c;
    for (int i = 0; i < c; i++) {
        cin >> a[i];
    }
    sort(a, a + c);
    dfs(0, 0);
}
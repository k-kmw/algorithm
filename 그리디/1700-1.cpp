#include <bits/stdc++.h>
using namespace std;
int items[101];
int slots[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    for(int i=0; i<k; i++) {
        cin >> items[i];
    }

    int ans = 0;
    for(int i=0; i<k; i++) { // 아이템 사용
        int max = -1;
        int maxIdx;
        bool flag = false;

        for(int j=0; j<n; j++) { // 슬롯 확인
            if(items[i] == slots[j] || slots[j] == 0) { // 빈칸이 있거나 이미 꽂혀 있음
                slots[j] = items[i];
                flag = true;
                break;
            }
            else {
                int idx = find(items+i, items+k, slots[j]) - (items+i); // 슬롯에 아이템이 몇 번째에 있는지 확인
//                cout << items[i] << ' ' << slots[j] << ' ' << idx << '\n';
                if(idx > max) { // 더 나중에 나오는 경우 대체
                    max = idx;
                    maxIdx = j;
                }
            }
        }

        if (!flag) { // 아직 꽂지 않은 경우
//            cout << slots[maxIdx] << '\n';
            slots[maxIdx] = items[i];
            ans++;
        }

    }
    cout << ans;
}
#include <bits/stdc++.h>
using namespace std;
int arr[100001];
int arr2[100001];
int cnt;
int n;

void flip(int a, int b) {
    int st = a;
    int en = b;
    while(st <= en) {
        if (arr[st] != arr2[st] || arr[en] != arr2[en]) {
            if (st == en) {
                arr2[st] = -arr2[st];
                break;
            }
            arr2[st] = arr[en];
        }
        st++;
        en--;
    }
    for(int i=0; i<n; i++) {
        cout << arr2[i] << ' ';
    }
    cout << '\n';
}

void isEqual() {
    bool equal = true;
    for(int i=0; i<n; i++) {
        if(arr[i] != arr2[i]) {
            cnt++;
            equal = false;
        }
    }

    if(equal) {
        if(cnt == 1) {
            cout << "One\n";
        }
        else if(cnt == 2) {
            cout << "Two\n";
        }
    }
    if(cnt >= 3) {
        cout << "Over\n";
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> n;
    while(t--) {
        cnt = 0;
        for(int i=0; i<n; i++) {
            cin >> arr[i];
            arr2[i] = arr[i];
        }

        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                flip(i, j);
                isEqual();
            }
        }
    }
}
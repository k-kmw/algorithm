#include <bits/stdc++.h>
using namespace std;
int n;
int a[10001];

bool next_permutation() {
    int i = n-1;
    while(i > 0 && a[i-1] >= a[i])  i--;
    if(i == 0)  return false;
    int j = n-1;
    while(a[i-1] >= a[j]) j--;
    swap(a[i-1], a[j]);
    j = n-1;
    while(i < j) {
        swap(a[i], a[j]);
        i++;
        j--;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    if(next_permutation()) {
        for(int i=0; i<n; i++) {
            cout << a[i] << ' ';
        }
        return 0;
    }
    cout << -1 << '\n';
}
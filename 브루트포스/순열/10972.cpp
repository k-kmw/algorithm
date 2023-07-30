#include <bits/stdc++.h>
using namespace std;
int n;
int arr[10001];

bool next_permutation() {
    int i = n-1;
    while(i > 0 && arr[i-1] > arr[i]) {
        i--;
    }
    if(i == 0) {
        return false;
    }
    int j = n-1;
    while(i-1 < j && arr[i-1] > arr[j])    j--;
    swap(arr[i-1], arr[j]);

    j = n-1;
    while(j > i) {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    if (next_permutation()) {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << ' ';
        }
    }
    else{
        cout << -1;
    }
}
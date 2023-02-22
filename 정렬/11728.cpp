#include <bits/stdc++.h>
using namespace std;
int arr1[1000000];
int arr2[1000000];
int arr3[2000000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++)
        cin >> arr1[i];
    for(int i=0; i<m; i++)
        cin >> arr2[i];

    int idx1 = 0;
    int idx2 = 0;
    int idx = 0;

    while(true) {
        if(idx1 + idx2 == m+n){
            break;
        } //두 배열을 모두 순회한 경우

        if(idx1 == n) { //배열1이 먼저 끝난 경우
            for(int i=idx2; i<m; i++) {
                arr3[idx] = arr2[i];
                idx++;
            }
            break;
        }
        else if (idx2 == m) { //배열2가 먼저 끝난 경우
            for(int i=idx1; i<n; i++) {
                arr3[idx] = arr1[i];
                idx++;
            }
            break;
        }

        else {
            if (arr1[idx1] > arr2[idx2]) {
                arr3[idx] = arr2[idx2];
                idx2++;
            }
            else {
                arr3[idx] = arr1[idx1];
                idx1++;
            }
            idx++;
        }
    }
    for(int i=0; i<idx; i++) {
        cout << arr3[i] << ' ';
    }
}


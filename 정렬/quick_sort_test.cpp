#include <bits/stdc++.h>
using namespace std;

int n = 10;
int arr[1000001] = {15, 25, 22, 357, 16, 23, -53, 12, 46, 3};

int move(int l, int r) {
    int pivot = l;
    while(true) {
        if(r <= l) {
            swap(arr[pivot], arr[r]);
            break;
        }

        while(arr[l] <= arr[pivot]) l++;
        while(arr[r] >= arr[pivot]) r--;

        swap(arr[r], arr[l]);
    }
    return r;
}

void quick_sort(int l, int r) {
    if(l >= r)  return;
    int pivot = move(l, r);
    quick_sort(l, pivot-1);
    quick_sort(pivot+1, r);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    quick_sort(0, n-1);
    for (int i = 0; i < n; i++) cout << arr[i] << ' ';  // -53 3 12 15 16 22 23 25 46 357
}
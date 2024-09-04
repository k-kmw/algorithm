#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int Y =0;
    int M =0;
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    for(int i=0; i<n; i++) {
        Y += (arr[i]/30+1)*10;
        M += (arr[i]/60+1)*15;
    }

    if(M < Y) {
        cout << "M " << M;
    }
    else if(M > Y) {
        cout << "Y " << Y;
    }
    else {
        cout << "Y M " << M;
    }
}
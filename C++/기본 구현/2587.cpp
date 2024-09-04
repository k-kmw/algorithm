#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num[5], sum =0;
    for(int i=0; i<5; i++) {
        cin >> num[i];
        sum += num[i];
    }
    cout << sum / 5 << '\n';
    sort(num, num+5);
    cout << num[2];
    return 0;

}
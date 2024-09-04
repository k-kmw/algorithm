#include <iostream>
#include <string>
using namespace std;

int freq[10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    int p;
    cin >> a >> b >> c;

    p = a*b*c;
    while(p>0) {
        freq[p%10]++; // 각 자리 수의 값을 구함
        p /= 10; // 다음 자리 수로 이동
    }

    for(int i=0; i<10; i++) {
        cout << freq[i] << '\n';
    }

}
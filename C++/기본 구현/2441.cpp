#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) { // 별과 공백 합쳐서 n
        int j=0;
        for(; j<i; j++) cout << ' ';
        for(; j<n; j++) cout << '*';
        cout << '\n';
    }
}
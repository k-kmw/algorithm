#include <iostream>
#include <algorithm>
using namespace std;

int n, maxvalue, maxindex;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=1; i<10; i++) {
        cin >> n;
        if (n > maxvalue){
            maxvalue = n;
            maxindex = i;
        }
    }
    cout << maxvalue << '\n';
    cout << maxindex;

}
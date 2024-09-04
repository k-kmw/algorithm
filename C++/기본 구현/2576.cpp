#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    int sum=0;
    int min=99, input;
    for(int i=0; i<7; i++) {
        cin >> input;
        if(input % 2 != 0) {
            sum += input;
            if(input < min)
                min = input;
        }
    }
    if(sum == 0) {
        cout << -1;
    }
    else {
        cout << sum << '\n' << min;
    }
    return 0;
}
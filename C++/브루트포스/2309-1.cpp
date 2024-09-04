#include <bits/stdc++.h>
using namespace std;
int tall[10];
int tot;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0; i<9; i++)
        cin >> tall[i];
    sort(tall, tall+9);
    tot = accumulate(tall, tall+9, 0);

    for(int i=0; i<8; i++) {
        for(int j=i+1; j<9; j++) {
            if(tot - (tall[i] + tall[j]) == 100) {
                for(int k=0; k<9; k++) {
                    if(k != i && k!= j) {
                        cout << tall[k] << '\n';
                    }
                }
                return 0;
            }
        }
    }
}
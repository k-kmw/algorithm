#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v;
    int input;
    for(int i=0; i<9; i++) {
        cin >> input;
        v.push_back(input);
    }

    int sum = accumulate(v.begin(), v.end(), 0);
    int remainder = sum - 100;
    int tmp;
    int flag = 0;
    for(int i=0; i<9; i++) {
        for(int j=i+1; j<9; j++) {
//            cout << remainder % v[i] << " ";
            if (remainder - v[i] == v[j]) {
//                cout << v[i] << ' ' << v[j];
//                tmp = v[j];
//                v.erase(remove(v.begin(), v.end(), v[i]), v.end());
//                v.erase(remove(v.begin(), v.end(), v[j]), v.end());
                v[i] += 100;
                v[j] += 100;
                flag = 1;
                break;
            }
            if(flag)    break;
        }
    }
    sort(v.begin(), v.end());
//    v.erase(remove(v.begin(), v.end(), tmp), v.end());
    for(int i=0; i<7; i++) {
        cout << v[i] << '\n';
    }
}
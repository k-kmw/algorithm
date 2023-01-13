#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> vec;
    int n, x;
    cin >> n >> x;
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        vec.push_back(a);
    }
    for(int i=0; i<n; i++) {
        if(vec[i] < x) {
            cout << vec[i] << " ";
        }
    }

}



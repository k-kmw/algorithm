#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[21];
void reverse(int a, int b) {
    for(int i=0; i<(b-a)/2+1; i++) {
        swap(arr[a+i], arr[b-i]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

//    vector<int> v;
//    for(int i=1; i<=20; i++) {
//        v.push_back(i);
//    }
//
//    for(int i=0; i<10; i++) {
//        int a, b;
//        cin >> a >> b;
//        reverse(v.begin()+a-1, v.begin()+b);
//    }
//
//    for(auto e:v) {
//        cout << e << ' ';
//    }

    for(int i=1; i<=20; i++) {
        arr[i] = i;
    }

    for(int i=1; i<=10; i++) {
        int a, b;
        cin >> a >> b;
        reverse(a, b);
    }

    for(int i=1; i<=20; i++) {
        cout << arr[i] << " ";
    }

}
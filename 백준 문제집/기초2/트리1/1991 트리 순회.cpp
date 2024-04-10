#include <bits/stdc++.h>
using namespace std;

int n;
pair<char, char> a[27];

void pre_order(char c) {
    if(c != '.') {
        cout << c;
        pre_order(a[c-'A'].first);
        pre_order(a[c-'A'].second);
    }
}

void in_order(char c) {
    if(c != '.') {
        in_order(a[c-'A'].first);
        cout << c;
        in_order(a[c-'A'].second);
    }
}

void post_order(char c) {
    if(c != '.') {
        post_order(a[c-'A'].first);
        post_order(a[c-'A'].second);
        cout << c;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++) {
        char root, left, right;
        cin >> root >> left >> right;

        a[root-'A'].first = left;
        a[root-'A'].second = right;
    }
    pre_order('A');
    cout << '\n';
    in_order('A');
    cout << '\n';
    post_order('A');
}
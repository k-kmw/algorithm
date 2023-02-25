#include <bits/stdc++.h>
using namespace std;
string serial[51];

bool cmp(string a, string b) {
    if(a.length() < b.length() || a.length() > b.length()) return a.length() < b.length();
    else if(a.length() == b.length()) {
        int suma = 0;
        int sumb = 0;
        for(int i=0; i<a.length(); i++) {
            if(!isalpha(a[i]))
                suma += a[i] - '0';
        }
        for(int i=0; i<b.length(); i++) {
            if(!isalpha(b[i]))
                sumb += b[i] - '0';
        }
        if(suma != sumb)    return suma < sumb;
    }
    return a < b;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++)  cin >> serial[i];

    sort(serial, serial+n, cmp);
    for(int i=0; i<n; i++) {
        cout << serial[i] << '\n';
    }
}
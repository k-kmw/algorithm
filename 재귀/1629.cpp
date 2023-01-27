#include <bits/stdc++.h>
using namespace std;
using ll = long long;

long long pow(ll a, ll b, ll c) {
    if(b==1)    return a % c;
    ll val = pow(a, b/2, c);
    val = val * val % c;
    if(b % 2 == 1)
        return val * a % c;
    return val;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll a, b, c;
    cin >> a >> b >> c;
    cout << pow(a, b, c);
}





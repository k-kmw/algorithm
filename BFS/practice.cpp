#include <bits/stdc++.h>
using namespace std;
int people[500001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int limit;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> people[i];
    cin >> limit;

    sort(people, people+n);
    int i=0;
    int j=n-1;
    int cnt =0;
    while(i <= j) {
        cnt++;
        if(people[j] + people[i] <= limit) {
            i++;
        }
        j--;
    }
    cout << cnt;
}
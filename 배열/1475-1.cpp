#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int num[10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, ans=1;
    cin >> n;

    while(n) {
        num[n%10]++;
        n /= 10;
    }

    for(int i=0; i<10; i++) {
        if(i==6 || i==9) // i=6이거나 i=9일때 예외
            continue;
        ans = max(ans, num[i]); // 6, 9를 제외한 최대 세트수를 구함
    }
    ans = max(ans, (num[6]+num[9]+1)/2); // 6, 9를 포함하여 최대 세트수를 구함
    cout << ans;
}
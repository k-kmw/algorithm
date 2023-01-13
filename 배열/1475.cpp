#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int num[9]; //0~8, 9를 6과 하나로 봄

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    while(n > 0) {
        if(n%10 == 6 || n%10 == 9)  num[6]++; //자리 수가 6이나 9이면 6을 증가시킴
        else    num[n%10]++; // 자리 수 하나 증가
        n/=10; // 다음 자리수
    }
    num[6] = num[6]/2 + num[6]%2; // 6의 경우 몫과 나머지를 더해주면 세트수가 됨
    // or (num[6]+1)/2
    int maxVal = *max_element(num, num+10); // 최대 세트수를 구함
    cout << maxVal;
}
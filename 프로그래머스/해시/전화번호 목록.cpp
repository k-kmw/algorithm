#include<bits/stdc++.h>

using namespace std;
// 어떤 번호가 다른 번호의 접두어인 경우가 있으면 false를 그렇지 않으면 true를 return
// n = 10^6
bool solution(vector<string> phone_book) {
    // 접두사인지 확인 -> 처음에 와야함 substr(0, n)
    sort(phone_book.begin(), phone_book.end());
    for(int i=0; i<phone_book.size()-1; i++) {
        int len = phone_book[i].size();
        if(phone_book[i] == phone_book[i+1].substr(0, len)) {
            return false;
        }
    }
    return true;
    // 문자열 정렬을 했으므로 인접한 것이 substring이 아니면 다른 것은 substring이 될 수 없다.
}

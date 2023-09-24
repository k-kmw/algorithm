#include <bits/stdc++.h>
using namespace std;

// 단어 수학 문제는 N개의 단어로 이루어 짐
// 각 단어는 알파벳 대문자로만 이루어짐
// 각 알파벳 대문자를 0~9 숫자 중 하나로 바꿔서 N개의 수를 합하는 문제
// 같은 알파벳은 같은 숫자로 바꿔야 함
// N개의 단어가 주어졌을 때 합을 최대로 만드는 프로그램 작성

vector<string> words;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        words.push_back(s);
    }

    // 문자에 하나의 숫자를 대응 해줘야 함 -> map 사용
    // 모든 숫자를 모두 해본다
    // 한 번 나왔던 문자가 나올 경우 어떻게 처리?
    // G를 0~9, C를 0~9, F를 0~9

}
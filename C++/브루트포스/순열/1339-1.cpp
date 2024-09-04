#include<bits/stdc++.h>
using namespace std;

// 단어 수학 문제는 N개의 단어로 이루어 짐
// 각 단어는 알파벳 대문자로만 이루어짐
// 각 알파벳 대문자를 0~9 숫자 중 하나로 바꿔서 N개의 수를 합하는 문제
// 같은 알파벳은 같은 숫자로 바꿔야 함
// N개의 단어가 주어졌을 때 합을 최대로 만드는 프로그램 작성
int n;
vector<string> words;
set<char> filter;
string alphabet;
//int converts[30];
map<char, int> converts;
bool vis[10];
long long mx = 0;
long long powCache[10];

long long update() {
    long long tot = 0;
    // 각 words들의 문자열을 숫자로 변환
    // 모두 더함
    for(int i=0; i<words.size(); i++) {
        long long num = 0;
        for(int j=0; j<words[i].size(); j++) {
            num += converts[words[i][j]] * powCache[words[i].size()-j-1]; // AAA -> 9*10^2, pow(10, n) 함수의 시간복잡도 = O(n)
        }
//        cout << num << '\n';
        tot += num;
    }
    return tot;
}

void dfs(int k) {
    if(k == alphabet.size()) {
        mx = max(mx, update());
        return;
    }
    // ABCDEFG
    // A -> 9, B -> 8 ...
    for(int i=9; i>int(9-alphabet.size()); i--) {
        if(vis[i])  continue;
        converts[alphabet[k]] = i;
        vis[i] = true;
        dfs(k+1);
        vis[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1. n개의 단어를 입력 받는다.
    // 2. 단어의 문자들을 set에 넣고 중복을 제거한다
    // 3. 백트래킹으로 set에 있는 모든 문자들을 9~집합 사이즈까지 대응시킨다
    // 4. 각 대응마다 단어들을 숫자로 변환시킨 후 모두 더한다
    // 5. 최대값을 갱신한다
    cin >> n;
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        words.push_back(s);
        for(auto c : s) {
            filter.insert(c);
        }
    }
    for(auto &f : filter) {
        alphabet += f;
    }
    powCache[0] = 1;
    for(int i=1; i<10; i++) {
        powCache[i] = powCache[i-1] * 10;
    }
    dfs(0);
    cout << mx << '\n';
}
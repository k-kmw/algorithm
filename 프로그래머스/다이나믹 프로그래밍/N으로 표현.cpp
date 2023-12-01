#include <bits/stdc++.h>

using namespace std;

// N은 1 이상 9 이하입니다.
// number는 1 이상 32,000 이하입니다.
// 수식에는 괄호와 사칙연산만 가능하며 나누기 연산에서 나머지는 무시합니다.
// 최솟값이 8보다 크면 -1을 return 합니다.

int Ns(int N, int k) {
    int res = N;
    for(int i=1; i<k; i++) {
        res = res * 10 + N;
    }
    return res;
}

set<int> dp[9];
int solution(int N, int number) {
    int answer = 0;
    // 1. 초기 k개의 N으로 만든 수를 dp배열의 k번째 set에 추가
    // 2. dp[k] = dp[i] + dp[k-i] (i=1~k-1)
    // 3. dp배열을 순회하면서 set에 number가 포함되면 k값을 return
    for(int k=1; k<=8; k++) {
        dp[k].insert(Ns(N, k)); // k개의 N으로 만든수 ex) N=5, (k=1 => 5, k=2 => 55, k=3 => 555)

        for(int i=1; i<k; i++) { // dp[k] = dp[i] + dp[k-i] (i=1~k-1)
            for(int j=1; j<k; j++) {
                if(i+j != k)    continue;

                for(auto a : dp[i]) {
                    for(auto b : dp[j]) {
                        dp[k].insert(a+b);
                        if(a >= b)
                            dp[k].insert(a-b);
                        dp[k].insert(a*b);
                        if(b != 0) {
                            dp[k].insert(a/b);
                        }
                    }
                }
            }
        }

        if(dp[k].find(number) != dp[k].end()) { // dp배열을 순회하면서 set에 number가 포함되면 k값을 return
            return k;
        }
    }
    return -1;
}
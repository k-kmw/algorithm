#include<bits/stdc++.h>
using namespace std;
int scores[101];

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int testCaseNum;
        fill(scores, scores+101, 0);
        cin >> testCaseNum;
        for(int i=0; i<1000; i++) {
            int x;
            cin >> x;
            scores[x]++;
        }
        cout << '#' << test_case << ' ';
        int mx = *max_element(scores, scores+100);
        for(int i=100; i>=0; i--) {
            if(mx == scores[i]) {
                cout << i << '\n';
                break;
            }
        }
    }
    return 0;
}
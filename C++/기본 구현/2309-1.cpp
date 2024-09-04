#include <iostream>
#include <algorithm>
using namespace std;

int num[9], result[7];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int total;
    for(int i=0; i<9; i++)  cin >> num[i];

    // 9명중 2명 뺀 모든 조합 고려
    for(int a=0; a<8; a++) { // 처음부터 8번째 까지 고려
        for(int b=a+1; b<9; b++) { // a+1부터 9번째 까지 고려
            total = 0; // 매 실행마다 total 초기화
            for(int c=0, i=0; c<9; c++) { // 처음부터 끝까지 확인
                if (c != a && c != b) { // 만약 a와 b 난쟁이가 아니면
                    result[i++] = num[c]; // 결과에 추가
                }
            }
            for(int i=0; i<7; i++) total += result[i]; // 결과의 합이 100인지 확인
            if (total == 100) // 결과가 맞으면
                break;
        }
        if(total == 100) // 결과가 맞으면
            break;
    }

    sort(result, result+7); // 정렬
    for(int i=0; i<7; i++)
        cout << result[i] << '\n';

}

// 시간 복잡도 n^3 ?
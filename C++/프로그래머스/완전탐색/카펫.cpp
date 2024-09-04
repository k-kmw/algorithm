#include <bits/stdc++.h>
using namespace std;

int width;
int height;

bool check(int brown) {
    if((2*width + 2*height + 4) == brown)   return true;
    return false;
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    // brown수에 따라 yellow의 배치 결정
    // 가능한 yellow의 배치를 모두 검사하고 brown 조건에 만족하는지 검사
    // 1. 초기 가로길이와 세로길이를 각각 yellow개수와 1로 설정
    // 2. 세로길이를 하나씩 증가시키고 가로길이를 비례하여 줄인다
    // 3. brown 개수 조건을 만족하는지 검사하고 맞으면 answer에 추가
    width = yellow;
    height = 1;
    while(true) {
        if(check(brown)) {
            answer.push_back(width+2);
            answer.push_back(height+2);
            break;
        }
        height++;
        if(yellow % height == 0)
            width = yellow / height;
    }
    return answer;
}
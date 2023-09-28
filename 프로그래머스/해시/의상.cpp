#include <bits/stdc++.h>

using namespace std;

// 각 종류별로 최대 1가지 의상만 착용
// 착용한 의상 일부가 겹치더라도, 다른 의상이 겹치지 않거나, 의상을 추가로 더 착용한 경우 서로 다른 방법으로 옷을 착용한 것으로 봄
// 하루에 최소 한 개의 의상을 입음
// 서로 다른 옷의 조합의 수를 return
// clothes [의상의 이름, 의상의 종류]. 길이 최대 30

map<string, vector<string>> clothesMap;

int solution(vector<vector<string>> clothes) {
    for(int i=0; i<clothes.size(); i++) {
        clothesMap[clothes[i][1]].push_back(clothes[i][0]);
    }
    int answer = 1;
    for(auto & c : clothesMap) {
        answer *= (c.second.size()+1); // 안입는 경우를 고려하기 위해 +1
    }
    return answer - 1; // 모든 옷을 안입는 경우를 제외하기 위해 -1
}
#include <bits/stdc++.h>
using namespace std;
// 총 N마리의 폰켓몬 중 N/2마리
// 같은 종류의 폰켓몬은 같은 번호를 가짐
// 최대한 많은 종류의 폰켓몬을 포함해서 N/2마리 선택
// N마리 폰켓몬의 종류 번호가 담긴 배열 nums
// N/2마리의 폰켓몬을 선택하는 방법 중, 가장 많은 종류의 폰켓몬을 선택하는 방법을 찾아,
// 그때의 폰켓몬의 종류 번호의 개수를 return
map<int, int> types;
int solution(vector<int> nums)
{
    int answer = 0;
    for(int i=0; i<nums.size(); i++) {
        types[nums[i]]++;
    }
    // cout << types.size() << '\n';
    answer = min<int>(nums.size()/2, types.size());
    return answer;
}
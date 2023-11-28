#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    // 긴 쪽을 가로로 설정
    // 짧은 쪽을 세로로 설정
    // 1. 긴 쪽에서 최대값을 찾음
    // 2. 짧은 쪽에서 최대값을 찾음
    int width = 0;
    int height = 0;
    for(int i=0; i<sizes.size(); i++) {
        if(sizes[i][0] > sizes[i][1]) {
            width = max(width, sizes[i][0]);
            height = max(height, sizes[i][1]);
        }
        else {
            width = max(width, sizes[i][1]);
            height = max(height, sizes[i][0]);
        }
    }
    answer = width * height;
    return answer;
}
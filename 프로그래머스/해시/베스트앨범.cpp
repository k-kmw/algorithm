#include <bits/stdc++.h>
using namespace std;

// 장르 별로 가장 많이 재생된 노래를 두 개씩 모아 베스트 앨범을 출시
// 속한 노래가 많이 재생된 장르를 먼저 수록
// 장르 내에서 많이 재생된 노래를 먼저 수록
// 고유 번호가 낮은 노래를 먼저 수록
// 노래별 장르를 나타내는 문자열 배열 genres, 노래별 재생 횟수를 나타내는 정수 배열 plays
// 베스트 앨범에 들어갈 노래의 고유 번호를 '순서대로' return

map<string, int> playnum;
vector<pair<int, string>> vec;
map<string, vector<pair<int, int>>> songs;
bool comparator(pair<int, int> & a, pair<int, int> & b) {
    return a.second > b.second;
}
bool comp(pair<int, string> & a, pair<int, string> & b) {
    return a.first > b.first;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    // 1. 장르별 재생 횟수를 map에 저장
    // 2. genres plays를 순회하며 다른 map에 해당 장르의 {고유번호, 나온 횟수}를 리스트로 저장
    // 3. 위 map을 나온 횟수를 기준으로 정렬
    // 4. 장르별 재생 횟수 map을 순회하며 장르 2개씩 고름
    vector<int> answer;
    int len = genres.size();
    for(int i=0; i<len; i++) {
        playnum[genres[i]] += plays[i];
        songs[genres[i]].push_back({i, plays[i]});
    }
    for(auto &song : songs) {
        sort(song.second.begin(), song.second.end(), comparator);
    }
    for(auto& m : playnum) {
        vec.push_back({m.second, m.first});
    }
    sort(vec.begin(), vec.end(), comp);
    for(auto &v : vec) {
        for(int i=0; i<2; i++) {
            if(songs[v.second].size() <= i) break;
            answer.push_back(songs[v.second][i].first);
        }
    }
    return answer;
}
#include <bits/stdc++.h>
using namespace std;
map<string, int> namesMap;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    for(auto& p : participant) {
        namesMap[p]++;
    }
    for(auto& c : completion) {
        namesMap[c]--;
    }
    for(auto& name : namesMap) {
        if(name.second != 0)
            answer += name.first;
    }
    return answer;
}
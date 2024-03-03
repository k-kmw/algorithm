#include <bits/stdc++.h>
using namespace std;

//class Atom {
//public:
//    int x, y;
//    int dir, energy;
//    bool isDie;
//
//    Atom(int x, int y, int dir, int energy) : isDie() {
//        this->x = x;
//        this->y = y;
//        this->dir = dir;
//        this->energy = energy;
//    }
//
//    Atom() : x(), y(), dir(), energy(), isDie() {};
//};

int n;
int ans;
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, -1, 1};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for(int test_case=1; test_case<=T; test_case++) {
        ans = 0;
//        vector< pair< pair<int, int>, pair<int, int> > > atoms;
//        map< pair<int, int>, vector<pair< pair<int, int>, pair<int, int> > > > loc;
        vector<pair<pair<pair<int, int>, pair<int, int> >, bool> > atoms;
        map< pair<int, int>, vector<pair<pair<pair<int, int>, pair<int, int> >, bool> > > loc;
        cin >> n;
        for(int i=0; i<n; i++) {
            int y, x, dir, energy;
            cin >> x >> y >> dir >> energy;
            atoms.emplace_back(make_pair(make_pair(make_pair(2*x, 2*y), make_pair(dir, energy)), false));
        }
        while(atoms.size() >= 2) {

            for(auto& atom : atoms) { // 이동

                int nx = atom.first.first.first + dx[atom.first.second.first];
                int ny = atom.first.first.second + dy[atom.first.second.first];
                if(nx < -2000 || nx > 2000 || ny < -2000 || ny > 2000) {
                    atom.second = true;
                }
                atom.first.first.first = nx;
                atom.first.first.second = ny;
            }

            loc.clear();

            for(auto& atom : atoms) {
//                cout << atom.x << ' ' <<  atom.y << '\n';
                if(atom.second) continue;
                loc[make_pair(atom.first.first.first, atom.first.first.second)].push_back(atom);
            }

            atoms.clear();

            for (const auto &item: loc) {
                if(item.second.size() >= 2) {
                    for(auto& a : item.second) {
                        ans += a.first.second.second;
                    }
                } else {
                    if(-2000 <= item.second[0].first.first.first && item.second[0].first.first.first <= 2000 && -2000 <= item.second[0].first.first.second && item.second[0].first.first.second <= 2000) {
                        atoms.push_back(item.second[0]);
                    }
                }
            }
        }
        cout << "#" << test_case << " " <<  ans << '\n';
    }
}

// 시간초과..?
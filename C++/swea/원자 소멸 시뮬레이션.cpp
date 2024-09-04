#include <bits/stdc++.h>
using namespace std;

class Atom {
public:
    int x, y;
    int dir, energy;
    bool isDie;

    Atom(int x, int y, int dir, int energy) : isDie() {
        this->x = x;
        this->y = y;
        this->dir = dir;
        this->energy = energy;
    }

    Atom() : x(), y(), dir(), energy(), isDie() {};
};

int n;
int ans;
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, -1, 1};
int loc[4001][4001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for(int test_case=1; test_case<=T; test_case++) {
        ans = 0;
        vector<Atom> atoms;
        cin >> n;
        for(int i=0; i<n; i++) {
            int y, x, dir, energy;
            cin >> x >> y >> dir >> energy;
            atoms.emplace_back(*new Atom(2*(x+1000), 2*(y+1000), dir, energy));
        }
        while(true) {

            bool isFinish = true;
            for(auto& atom: atoms) {
                if(!atom.isDie) {
                    isFinish = false;
                    break;
                }
            }
            if(isFinish) {
                break;
            }

            for(auto& atom : atoms) { // 이동
                int nx = atom.x + dx[atom.dir];
                int ny = atom.y + dy[atom.dir];
                if(nx < 0 || nx > 4000 || ny < 0 || ny > 4000) {
                    atom.isDie = true;
                } else if(!atom.isDie){
                    loc[nx][ny]++;
                    atom.x = nx;
                    atom.y = ny;
                }
            }

            for(auto& atom : atoms) {
                if(loc[atom.x][atom.y] >= 2) {
                    for(auto& atom2 : atoms) {
                        if(!atom2.isDie && atom.x == atom2.x && atom.y == atom2.y) {
                            ans += atom2.energy;
                            atom2.isDie = true;
                        }
                    }
                }
                loc[atom.x][atom.y] = 0;
            }
        }
        cout << "#" << test_case << " " <<  ans << '\n';
    }
}
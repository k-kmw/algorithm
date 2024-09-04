#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
pair<int, int> arr[100001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        int sm, sd, em, ed;
        cin >> sm >> sd >> em >> ed;
        arr[i].X = sm*100 + sd;
        arr[i].Y = em*100 + ed;
    }
    sort(arr, arr+n);
//    for(int i=0; i<n; i++) {
//        cout << arr[i].X << arr[i].Y << '\n';
//    }
    int st = 101;
    int en = 301;
    int tmpY = 0;
    int tmpX = 0;
    int ans = 0;
    for(int i=0; i<n; i++) {
        if(arr[i].Y <= 301) continue; // 지는 시간이 301보다 작거나 같으면 추가하지 않음
        else if(arr[i].X >= st && arr[i].X <= en) { // 피는 시간이 st와 en 사이면 모두 동일한 것으로 취급
            if(tmpY < arr[i].Y) { // 최대 지는 시간을 가진 꽃의 정보를 저장
                tmpX = arr[i].X;
                tmpY = arr[i].Y;
            }
            if(i == n-1 && en <= 1130 && tmpX <= en && tmpY > en) { // // 마지막 꽃의 경우 확인 후 바로 갱신. tmpX <= en 등호 붙여줘야 함
                st = tmpX;
                en = tmpY;
//            cout << st << ' ' << en << '\n';
                ans++;
            }
        }
        else{ // 피는 시간이 현재 st와 en 사이가 아니면 지금까지 저장된 tmpX와 tmpY를 st와 en에 갱신
            st = tmpX;
            en = tmpY;
            if(arr[i].X > en) { // 갱신 후 현재 피는 시간이 en보다 크면 조건 만족하지 않음(피는 시간 기준으로 정렬되어 있으므로)
                ans = 0;
                break;
            }
            ans++; // 꽃을 추가
//            cout << st << ' ' << en << '\n';
            i--; // 갱신한 st와 en으로 현재 꽃을 다시 확인
            continue;
        }

        if(i == n-1 && en <= 1130) { // i가 n-1인데 en이 1130이하 이면 조건 만족하지 않음
            ans = 0;
        }
    }

    cout << ans;
}
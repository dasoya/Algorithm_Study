#include "bits/stdc++.h"

using namespace std;

int mt[1005][1005][11][2];
int mp[1005][1005];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main(){

    int n, m, k;
    cin >> n >> m >> k;
    ios::sync_with_stdio(0);
    cin.tie(0);

    char tmp ;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cin >> tmp;
            if(tmp =='0')
            mp[i][j] = 0;
            else mp[i][j] = 1;
        }
    }

    queue<tuple<int,int,int,int>> q;
    q.push({1,1,0,0});
    mt[1][1][0][0] = 1;

    while(!q.empty()){

      auto cur = q.front(); q.pop();
      auto [nx,ny,nk,flag] = cur;

        if(nx == n && ny == m){
            cout <<  mt[n][m][nk][flag];
            return 0;
        }

        for (int i = 0; i < 4; ++i) {

            int nx1, ny1;
            nx1 = nx + dx[i];
            ny1 = ny + dy[i];

            if(nx1 <= 0 || ny1 <= 0 || nx1 > n || ny1 > m) continue;
            if(nk >= k && mp[nx1][ny1] == 1) continue;
            if(mt[nx1][ny1][nk+1][1-flag] != 0 && mp[nx1][ny1] == 1) continue; // 다음 칸이 비워져 있어야함!
            if(mt[nx1][ny1][nk][1-flag] != 0 && mp[nx1][ny1] == 0) continue;


            if(mp[nx1][ny1]==1 && flag==0){ // 낮일 땐 벽을 부숨

                mt[nx1][ny1][nk+1][1-flag] = mt[nx][ny][nk][flag] + 1;
                q.push({nx1,ny1,nk+1,1-flag});
            }
            else if(mp[nx1][ny1]==1 && flag == 1){ // 밤일땐 한턴 기다림
                mt[nx][ny][nk][1-flag] = mt[nx][ny][nk][flag] + 1;
                q.push({nx,ny,nk,1-flag});
            }
            else {
                mt[nx1][ny1][nk][1-flag] = mt[nx][ny][nk][flag] + 1;
                q.push({nx1,ny1,nk,1-flag});
            }

        }

    }

    cout << -1;




//    for(int i = 1; i <= n; ++i) {
//        for(int j = 1; j <= m; ++j) {
//
//            cout << mt[i][j][0] << "";
//        }
//         cout << "\n";
//    }
    return 0;

//
//    int ans = 1000000000;
//
//    for (int i = 0; i < 11; ++i) {
//        if(mt[n][m][i]==0) continue;
//        if(ans > mt[n][m][i])
//            ans = mt[n][m][i];
//    }
//
//    if(ans == 1000000000) cout << -1;
//
//    else cout << ans;



}


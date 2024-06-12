#include "bits/stdc++.h"

using namespace std;


int mt[1005][1005][11];
int mp[1005][1005];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main(){


    int n, m, k;
    cin >> n >> m >> k;

    char tmp ;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cin >> tmp;
            if(tmp =='0')
            mp[i][j] = 0;
            else mp[i][j] = 1;

         //   cout << mp[i][j] << "";
        }
       // cout << "\n";
    }



    queue<tuple<int,int,int>> q;
    q.push({1,1,0});
    mt[1][1][0] = 1;
    mt[1][1][1] = 1;

    while(!q.empty() ){

      auto cur = q.front(); q.pop();
      int nx,ny,nk;
      tie(nx,ny,nk) = cur;

        for (int i = 0; i < 4; ++i) {

            int nx1, ny1;
            nx1 = nx + dx[i];
            ny1 = ny + dy[i];

            if(nx1 <= 0 || ny1 <= 0 || nx1 > n || ny1 > m) continue;
            if(nk >= k && mp[nx1][ny1] == 1) continue;
            if(mt[nx1][ny1][nk+1] != 0 && mp[nx1][ny1] == 1) continue;
            if(mt[nx1][ny1][nk] != 0 && mp[nx1][ny1] == 0) continue;


            if(mp[nx1][ny1]==1){

                mt[nx1][ny1][nk+1]= mt[nx][ny][nk] + 1;
                q.push({nx1,ny1,nk+1});
            }
            else {
                mt[nx1][ny1][nk] = mt[nx][ny][nk] + 1;
                q.push({nx1,ny1,nk});
            }

        }

    }


//    for(int i = 1; i <= n; ++i) {
//        for(int j = 1; j <= m; ++j) {
//
//            cout << mt[i][j][0] << "";
//        }
//         cout << "\n";
//    }



    int ans = 1000000000;

    for (int i = 0; i < 11; ++i) {
        if(mt[n][m][i]==0) continue;
        if(ans > mt[n][m][i])
            ans = mt[n][m][i];
    }

    if(ans == 1000000000) cout << -1;

    else cout << ans;



}


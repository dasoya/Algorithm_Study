//
// Created by dasoya on 1/8/24.
//
#include <iostream>
#include "queue"

using namespace std;

int board[103][103][103];
int dist[103][103][103];

int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0, 1,0, -1,0,0};
int dz[6] = {0,0,0,0,1,-1};

struct triple {
    int x;
    int y;
    int z;
};
int main(){

    int m , n, h;
    cin >> m >> n >> h;

    queue<triple> Q ;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < m; ++k) {


                cin >> board[j][k][i];
               if(board[j][k][i] == 1) {
                    dist[j][k][i] = 1;
                    Q.push({j,k,i});
               }
               else if(board[j][k][i] == -1){
                   dist[j][k][i] = -1;
               }
               else{
                   dist[j][k][i] = 0;
               }

            }
        }
    }

    while(!Q.empty()) {

        auto cur = Q.front(); Q.pop();

        for (int i = 0; i < 6; ++i) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            int nz = cur.z + dz[i];

            //n,m,h 순서 맞춰주기 >= 등호 포함 해주기
            if(nx<0 || nx >= n || ny <0 || ny >=m || nz <0 || nz >=h) continue;
            if (dist[nx][ny][nz] > 0) continue;
            if(dist[nx][ny][nz] == -1) continue;


            Q.push({nx,ny,nz});
            dist[nx][ny][nz] = dist[cur.x][cur.y][cur.z] +1;
        }

    }

    int max = -1;
    for (int i = 0; i < h; ++i) {
        //for 문 범위 순서
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < m; ++k) {

                if(dist[j][k][i]==0) {
                    cout << -1;
                    return 0;
                }
                if(dist[j][k][i]>max) max = dist[j][k][i] ;
              //  cout << dist[j][k][i] << " ";

                }
            //cout << "\n";
        }
      //  cout << "\n";
    }

    cout << max-1;





}
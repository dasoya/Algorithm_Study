//
// Created by dasoya on 1/16/24.
//

#include "iostream"
#include "queue"
#include "tuple"

using namespace std;

char board[33][33][33];
int dist[33][33][33];

int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};


int main(void){

    int l, r ,c;

    while(true){
        cin >> l >> r >> c;

        if(!l&&!r&&!c) break;

        queue<tuple<int,int,int>> Q;

        for (int i = 0; i < l; ++i) {
            for (int j = 0; j < r; ++j) {
                for (int k = 0; k < c; ++k) {
                    cin >> board[j][k][i];
                    dist[j][k][i]=-1;


                    if(board[j][k][i]=='S'){
                        Q.push({j,k,i});
                        dist[j][k][i]=0;
                    }
                }
            }
        }

        bool flag = false;
        while(!Q.empty()){
            int x,y,z;
           tie(x,y,z) = Q.front(); Q.pop();

           if(board[x][y][z]=='E') {
               cout << "Escaped in " << dist[x][y][z] <<" minute(s). \n";
               flag = true;
               break;
           }

            for (int i = 0; i < 6; ++i) {
                int nx = x+dx[i];
                int ny = y+dy[i];
                int nz = z+dz[i];

                if(nx<0||nx>=r||ny<0||ny>=c||nz<0||nz>=l) continue;
                if(board[nx][ny][nz] =='#'|| dist[nx][ny][nz] > -1) continue;

               // cout << nx <<" "<<ny<<" "<<nz<<" \n";

                Q.push({nx,ny,nz});
                dist[nx][ny][nz] = dist[x][y][z] +1;
            }
           // cout << Q.size();
        }

        if(!flag) cout << "Trapped! \n";

    }
}
//
// Created by dasoya on 1/11/24.
//

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

string board[1002];


int main(void){

    int n,m;
    int visit[1002][1002][2];

    cin >> n>>m;

    for (int i = 0; i < n; ++i) {
        cin >> board[i];
    }


    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            visit[i][j][0] = visit[i][j][1] = -1;
    
    queue<tuple<int,int,int>> Q;

    Q.push({0,0,0});
    visit[0][0][0] = visit[0][0][1] = 1;

    while(!Q.empty()){
        int x,y, broken;
        tie(x,y,broken) = Q.front();

        if(x==n-1&& y == m-1) {

            cout << visit[x][y][broken];
            return 0;
        }
        Q.pop();

        int nxdist = visit[x][y][broken] +1;

        for (int i = 0; i < 4; ++i) {

            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(board[nx][ny]== '0' &&   visit[nx][ny][broken] ==-1 ) { //벽을 한번도 안깨고 가는 경우.

                    visit[nx][ny][broken] = nxdist;
                    Q.push({nx,ny,broken});

            }

            if(!broken&& visit[nx][ny][1] == -1 && board[nx][ny] == '1') { //벽이 이미 깨진 경우?
                visit[nx][ny][1] = nxdist;
                Q.push({nx,ny,1});
            }
        }

    }

    cout << -1;
    return 0;



}
//
// Created by dasoya on 1/1/24.
//

#include <bits/stdc++.h>

using namespace std;

#define X first;
#define Y second;

string board[1002]; //string 이라 이자체가 char에대한 배열.
int vis1[1002][1002];
int vis2[1002][1002];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void){

    cin.tie(0);
    ios::sync_with_stdio(0);

    //BFS는 큐
    queue<pair<int,int>> Q1,Q2;
    int m,n;
    cin >> m >> n;
    string k;
    for (int i = 0; i < m; ++i) {
        //2차원 배열의 초기화는 무조건 해줘야함.
        fill(vis1[i],vis1[i]+n,0);
        fill(vis2[i],vis2[i]+n,0);
            cin >> board[i];

    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            k = board[i][j];
            if(k=="J"){
                Q1.push({i,j});
                vis1[i][j]= 1;
            }
            if(k=="F"){
                Q2.push({i,j});
                vis2[i][j]= 1;
            }
        }
    }

    while(!Q2.empty()){
        pair<int,int> cur = Q2.front(); Q2.pop();

        for (int dir = 0; dir < 4; ++dir) {
                int nx = cur.first + dx[dir];
                int ny =( cur.second + dy[dir]);

                if(nx<0||nx>=m||ny<0||ny>=n||board[nx][ny]=='#') continue;
                int a =vis2[nx][ny];
                if(a>0) continue;

                Q2.push({nx,ny});
                int x = cur.X;
                int y = cur.Y;
                vis2[nx][ny] = vis2[x][y]+1;


        }

    }

//    for (int i = 0; i < m; ++i) {
//        for (int j = 0; j < n; ++j) {
//            cout << vis2[i][j] <<",";
//        }
//        cout << "\n";
//    }

    int result = 0;
    bool exit = false;
    while(!Q1.empty()){
        pair<int,int> cur = Q1.front(); Q1.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            int x = cur.X;
            int y = cur.Y;

            if(x==0||x==m-1||y==0||y==n-1) {
                exit = true;
                result = vis1[x][y];
                break;
            }

            if(nx<0||nx>=m||ny<0||ny>=n||board[nx][ny]=='#') continue;
            if(vis1[nx][ny]>0) continue;
            //불이 지나가지 않은 곳과 시간이 적은 곳은 구분해줘야함!!! {벽에 가로막혀 불이 안가거나..등등}
            if(vis2[nx][ny] != 0 && vis2[nx][ny]<=vis1[x][y]+1) continue;



            Q1.push({nx,ny});

            vis1[nx][ny] = vis1[x][y]+1;



        }
        if(exit) break;
    }

//    for (int i = 0; i < m; ++i) {
//        for (int j = 0; j < n; ++j) {
//            cout << vis1[i][j] <<",";
//        }
//        cout << "\n";
//    }

    if(exit){
        cout << result;
    }
    else{
        cout << "IMPOSSIBLE";
    }




}
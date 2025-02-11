//
// Created by dasoya on 2/11/25.
//

#include "bits/stdc++.h"

using namespace std;

int n,m;

int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

int r,c,d;

int board[51][51]; // 0 빈칸

// 북동남서 0123   -1 : 90 반시계 회전 , 후진 : +2 % 4
int main(){

    cin >> n >> m;
    cin >> r >> c >> d;

    //r,c -> row,column, y,x 라는 뜻

    for(int i = 0; i< n; i++){
        for(int j = 0 ;j <m; j++){
            cin >> board[i][j];
        }
    }

    int ans = 0;
 // 청소된 빈칸

    while(true){

        if(board[r][c] == 0) {
            ans++;
            board[r][c] = 2;
        }

        int flag = false;

        for(int i = 0; i < 4; i++) {
            int nr = r+dy[i], nc = c+dx[i];
            if(nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
            if(board[nr][nc]==0)
            {flag = true; break; }
        }

        if(flag){//빈칸이 있는 경우
            if(--d<0) d=3;

            int nr = r+dy[d], nc = c+dx[d];
            if(nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
            if(board[nr][nc]==0){
                r = nr;
                c = nc;
            }

        }else{//빈칸 없는 경우

            int back = (d+2)%4;
            int nr = r+dy[back], nc = c+dx[back];

            if(nr < 0 || nc < 0 || nr >= n || nc >= m || board[nr][nc]==1){
                break;
            }

            r = nr;
            c= nc;

        }


    }

    cout << ans;

}

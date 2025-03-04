//
// Created by dasoya on 2/27/25.
//

#include "bits/stdc++.h"

using namespace std;

char board[11][11];

//0,1,2,3 동 서 남 북
int n,m;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int ans = 11;
pair<int,int> red,blue,hole;

int result = 0; // - >true되면 성공한거

// 그냥 하나씩 종료 조건에 도달할 때까지
// 결과가 false면 구멍에 둘다 떨어진거.
bool tilt(int dir){

    //조건
    //nr이 박스 범위 안에 있어야 넘어감, 벽이면 안됨. nb가 있으면 안됨.
    //nb가 박스

    //b가 구멍에 떨어지면 안됨
    bool rf = true,bf = true;
    while(true){

        pair<int,int> nr = {red.first+dy[dir],red.second+dx[dir]};
        pair<int,int> nb = {blue.first+dy[dir],blue.second+dx[dir]};

        if(rf){

            char nc = board[nr.first][nr.second];
            if(nc =='.'){


                board[red.first][red.second] = '.';
                red = nr;
                board[red.first][red.second] = 'R';
            }
            else if(nc == '#' || (nc=='B'&&!bf))
            {
                rf = false;

            }else if(nc == 'O'){
                if(result == 0)
                    result = 1;

                board[red.first][red.second] = '.';
                red = nr;
                rf = false;
            }
        }

        if(bf){

            char nc = board[nb.first][nb.second];
            if(nc =='.'){

                board[blue.first][blue.second] = '.';
                blue = nb;
                board[blue.first][blue.second] = 'B';
            }
            else if(nc == '#'|| (nc=='R'&&!rf))
            {
                bf = false;

            }else if(nc == 'O'){
                result = -1;

                board[blue.first][blue.second] = '.';
                blue = nb;
                bf = false;
                return -1;
            }
        }


        if(!rf&& !bf)
            break;

    }

    return 0;
}

void back(int idx){

    if(idx==11)
        return;

    for(int dir =0; dir < 4;dir++){

        //보드가 분리되어야함.
        char board1[11][11];
        copy(&board[0][0],&board[0][0]+11*11,&board1[0][0]);
        pair<int,int> red1,blue1;
        red1 = red;
        blue1 = blue;
        result = 0;
        int res = tilt(dir);
//
//        if(dir==1&&idx==4 )//||dir==2&&idx==1 ||dir==1&&idx==2 ||dir==3&&idx==3||
//            for(int i = 0; i < n;i++) {
//                for (int j = 0; j < m; j++) {
//                    cout << board[i][j] << " ";
//                }
//                cout << "\n";
//            }

        if(res != -1 && result==1)
        {

            ans = min(ans,idx);
            copy(&board1[0][0],&board1[0][0]+11*11,&board[0][0]);
            red = red1;
            blue = blue1;
            return;
        }
        else if(res==0) {
            back(idx + 1);

        }

            red = red1;
            blue = blue1;
            copy(&board1[0][0], &board1[0][0] + 11 * 11, &board[0][0]);

    }

}

int main(){

    cin >> n >> m;


    for(int i = 0; i < n;i++)
        for(int j  =0 ; j < m ; j++){
            cin >> board[i][j];
            if(board[i][j]=='R')
                red = {i,j};
            else if(board[i][j]=='B')
                blue = {i,j};
        }

    //백트래킹인가?
    back(1);

    if(ans==11)
        cout << -1;
    else cout << ans;

}
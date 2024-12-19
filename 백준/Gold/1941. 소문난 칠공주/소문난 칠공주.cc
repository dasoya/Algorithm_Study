//
// Created by dasoya on 12/19/24.
//
//
// Created by dasoya on 12/19/24.
//
#include "bits/stdc++.h"

using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
bool mask[25];
string board[5];
bool visited[5][5];
bool vBoard[5][5];
int ans = 0;
int unused = 1;

void backTracking(int t,int sCnt,pair<int,int> cur){

    if(t == 7){

        if(sCnt >= 4){
            ans++;
//            while(!q.empty()){
//                auto cur = q.top(); q.pop();
//                if(!answerBoard[cur.first][cur.second]){
//                    flag = true;
//                    answerBoard[cur.first][cur.second] = unused;
//                }
//            }
           // if(flag) {cout <<"\nans____\n";}

//            for(int i = 0; i < 5 ; i++){
//                for(int j = 0; j < 5 ; j++){
//                    if(answerBoard[i][j])
//                        cout << board[i][j];
//                    else cout << "*";
//                }
//                cout << "\n";
//            }
//            cout << "\n";

            unused++;

        }

        return;
    }


    if(board[cur.first][cur.second]== 'S') sCnt++;
    for(int i = 0; i < 4 ; i++){
        int nx = cur.first + dx[i];
        int ny = cur.second + dy[i];

        if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
        if(visited[nx][ny]) continue;

        backTracking(t+1,sCnt,{nx,ny});
    }
    if(board[cur.first][cur.second]== 'S') sCnt--;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i< 5 ; i++){
        cin >> board[i];
    }

    //25C7
    //2차배열의 뽑기.. 0 1 2
    fill(mask+7,mask+25,true);
    do{
        for(int i = 0; i < 5 ; i++) {
            fill(visited[i], visited[i] + 5, true);
            fill(vBoard[i], vBoard[i] + 5, false);
        }
        int sx,sy;
        for(int m = 0; m < 25 ; m++){
            int i = m/5;
            int j = m%5;

            visited[i][j] = mask[m];
            if(!mask[m]){
                sx = i;
                sy = j;
            }
        }
        //visited가 맞는 지 백트래킹
       // backTracking(0,0,{sx,sy});

       //bfs
        queue<pair<int,int>> q;
        q.push({sx,sy});
        vBoard[sx][sy] =  true;
        int sCnt = 0,cnt = 1;
        while(!q.empty()){

            auto cur = q.front(); q.pop();
            if(board[cur.first][cur.second]== 'S') sCnt++;
            for(int i = 0; i < 4 ; i++){
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];

                if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
                if(visited[nx][ny]||vBoard[nx][ny]) continue;

                cnt++;
                q.push({nx,ny});
                vBoard[nx][ny] =  true;
            }
        }

        if(sCnt >= 4 && cnt ==7)
            ans++;


    }while(next_permutation(mask,mask+25));

    cout << ans;
}
//
// Created by dasoya on 1/22/25.
//


#include "bits/stdc++.h"

using namespace std;

int board[21][21];

//천장면-1,룰, -> 바닥면
int diceRule[6][4] = {
        //동서 북남
        {3,4,2,5},
        {3,4,6,1},
        {6,1,2,5},
        {1,6,2,5},
        {3,4,1,6},//4
        {3,4,5,2}
};

int diceRule2[4]= {3,4,2,5};

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};

int dice[6];
int main(){

    int n,m,x,y,k;
    cin >> n >> m >> y >> x >> k;

    for(int i = 0; i< n; i++)
        for(int j = 0; j < m ; j++){

            cin >> board[i][j];
        }

    int curTop = 1,curBtm = 6;
    while(k--){
        int cmd;
        cin >> cmd;
        int nx = x+ dx[cmd-1];
        int ny = y+ dy[cmd-1];

        if(nx <0 || nx>=m || ny < 0 || ny >= n) continue;
        x = nx;
        y = ny;


        int boardNum = board[y][x];

       // curBtm = diceRule[curTop-1][cmd-1];
        int  nTop;
      //  cout << "t :" <<7-curBtm <<" ";

        int newRule[4];
        copy(diceRule2, diceRule2 + 4, newRule);

        //동서 북남
        //curTop, cmd의 의존해서 바뀜
        //북
        if(cmd==1){
            newRule[0] = curTop;
            newRule[1] = curBtm;
            nTop = diceRule2[1];
        }
        if(cmd==2){
            newRule[0] = curBtm;
            newRule[1] = curTop;
            nTop = diceRule2[0];
        }
        if(cmd==3){
            newRule[2] = curTop;
            newRule[3] = curBtm;
            nTop = diceRule2[3];
        }
        if(cmd==4){
            newRule[2] = curBtm;
            newRule[3] = curTop;
            nTop = diceRule2[2];
        }

        copy(newRule, newRule + 4, diceRule2);

        int nBtm = 7-nTop;

        curBtm =nBtm;
        curTop = nTop;

        if(boardNum==0){
          board[y][x]  =  dice[curBtm-1];
        }else{
            dice[curBtm-1] = board[y][x];
            board[y][x] = 0;
        }

        cout << dice[curTop-1] <<"\n";

    }


}
//
// Created by dasoya on 2/3/25.
//


#include "bits/stdc++.h"

using namespace std;
using Matrix = std::array<std::array<int, 5>, 5>;

int arr[5] = {0,1,2,3,4};

int dx[6] = {0,0,0,0,1,-1,};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {1,-1,0,0,0,0};
int ans = INT_MAX;

Matrix board[5];

//okay
Matrix rotate(Matrix array){

    Matrix newArr;

    for (int i = 0; i <5; ++i) {
        for (int j = 0; j < 5; ++j) {
            newArr[4-j][i] = array[i][j];
        }
    }
    return newArr;
}

int bfs(){

    queue<tuple<int,int,int>> q;
    Matrix dis[5];

    memset(dis,0,sizeof(dis));

    //board에서 3차원으로 길을 찾으면됨
    q.push({0,0,0});
    dis[0][0][0] = 0;

    while(!q.empty()){

        auto [z,x,y] = q.front(); q.pop();

        for(int dir = 0; dir < 6 ;dir++){

            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nz = z + dz[dir];

            if(nx < 0 || ny < 0 || nz < 0 || nx >=5 || ny >= 5 || nz >= 5) continue;
            if(board[nz][nx][ny]==0 || dis[nz][nx][ny] != 0) continue;

            q.push({nz,nx,ny});
            dis[nz][nx][ny] += dis[z][x][y]+1;
            if(nz==4 && nx==4 && ny==4) return dis[nz][nx][ny];
        }
    }

    return INT_MAX;
}

int main() {

    for (int k = 0; k < 5; k++) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> board[k][i][j];
            }
        }
    }
    Matrix newArr[5][4];

    for (int i = 0; i < 5; ++i) {
        newArr[i][0] = board[i];
        for (int j = 1; j < 4; ++j) {
            newArr[i][j] = rotate(newArr[i][j - 1]);
        }
    }

//    for (int k = 0; k < 5; k++) {
//        for (int l = 0; l < 4; ++l) {
//                for (int i = 0; i < 5; i++) {
//                    for (int j = 0; j < 5; j++) {
//                        cout << newArr[k][l][i][j];
//                    }
//                    cout << "\n";
//                }
//                 cout << "\n";
//        }
//        cout << k << "------------\n";
//
//    }



    do{
        //회전한 배열 20개에서
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                for (int k = 0; k < 4; ++k) {
                    for (int l = 0; l < 4; ++l) {
                        for (int m = 0; m < 4; ++m) {

                            //층수, i,j

                            //0,1,2,3,4
                            //i
                            board[0] = newArr[arr[0]][i];
                            board[1] = newArr[arr[1]][j];
                            board[2] = newArr[arr[2]][k];
                            board[3] = newArr[arr[3]][l];
                            board[4] = newArr[arr[4]][m];
                            //0,0하고 4,4를 확인 하면 됨

                            if(board[0][0][0]!=1 || board[4][4][4] !=1) continue;


                            //bfs를 돌릴 수 있음.

//                            for(int k = 0; k <5 ;k++){
//                                for(int i = 0; i <5 ;i++){
//                                    for(int j = 0; j <5 ;j++){
//                                        cout << board[k][i][j];
//                                    }
//                                    cout << "\n";
//                                }
//                                cout << "\n";
//                            }

                           // cout << "----------------\n";

                           ans = min(ans ,bfs());

            }}}
            }
        }

    }while(next_permutation(arr,arr+5));


    if(ans==INT_MAX) cout << -1;
    else cout << ans;
}


//5*4*3*2*1 (순열) * 4*4*4*4*4(회전)
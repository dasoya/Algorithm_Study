//
// Created by dasoya on 2/2/24.
//


#include "iostream"

using namespace std;
int board[128][128];

int white = 0;
int blue = 0;


void func(int n,int r,int c){

    if(n==0){
        //if(board[r][c] == 0) white++;
       // if(board[r][c] == 1) blue++;

        return;
    }

    int ans = board[r][c];
    int half = n/2;
    int flag = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {

            if(ans!=board[r+i][c+j])
            {
             flag =false;
            }

        }
    }

    if(flag) {
        // 다 똑같은 경우
        if (ans == 0) white++;
        if (ans == 1) blue++;
        return;
    }

    func(half,r,c);
    func(half,r+half,c);
    func(half,r,c+half);
    func(half,r+half,c+half);



}

int main(void){
    int n;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }

    func(n,0,0);

    cout << white << "\n" << blue;

}
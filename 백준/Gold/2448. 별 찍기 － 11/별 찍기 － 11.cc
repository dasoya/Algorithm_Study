//
// Created by dasoya on 2/7/24.
//

#include "iostream"

using namespace std;

char board[6300][6300];

// 가로 n 세로 길이는 n*2-1

//   11*11   15칸으로 이루어져 있음.
//   1*1*1
//   *****
void func(int n,int r, int c){

    if(n==3){

       board[r][c] = '*';
       board[r-1][c+1] = '*';
       board[r+1][c+1] = '*';

        for (int i = 0; i < 5; ++i) {
            board[r-2+i][c+2] = '*';
        }

        return
        ;
    }
    int m = n/2;
    func(m,r,c);
    func(m,r+m,c+m);
    func(m,r-m,c+m);

}

int main(void){

    int n;

    cin >>  n;

    func(n,n-1,0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2*n-1; ++j) {
            if(board[j][i] == '*')
                cout << '*';
            else cout << ' ';
        }

        cout <<"\n";

    }
}
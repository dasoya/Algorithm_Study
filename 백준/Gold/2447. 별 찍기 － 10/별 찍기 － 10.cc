//
// Created by dasoya on 2/6/24.
//

#include "iostream"

using namespace std;


char board[6561][6561] = {};

void star(int n,int r,int c){

    int m = n/3;
    if(n==1){
//        if(r== 1&&c==1){
//            cout <<" ";
//        }
//        else cout << "*" ;

        board[r][c] = '*';
        return;
    }

    //9등분씩 그리는 건가?
//    for (int i = 0; i < 3; ++i) {
//        for (int j = 0; j < 3; ++j) {
//            star(m,i,j);
//        }
//        cout<<"\n";
//    }

   // cout<<"\n";
//    //조건문 3개? or 9개?

    star(m,r,c);
    star(m,r,c+m);
    star(m,r,c+2*m);

    //cout << "\n";
    star(m,r+m,c);
    //5번째만 안그림!
    //star(m,)
    star(m,r+m,c+2*m);

    //cout << "\n";
    star(m,r+2*m,c);
    star(m,r+2*m,c+m);
    star(m,r+2*m,c+2*m);
    //cout << "\n";

   // return;
}

int main(void){
    int n;

    cin >> n;
    star(n,0,0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {


            if(board[i][j] == '*')
                cout << '*';
            else cout << " ";

        }

        cout <<"\n";
    }
}
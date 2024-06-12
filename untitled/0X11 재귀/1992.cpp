//
// Created by dasoya on 2/5/24.
//

#include "iostream"

using namespace std;

string board[64];

void func(int n,int r,int c){

    char k = board[r][c];

    if(n==1){
       cout << k ;
       return;
    }

    bool flag = true;

    for (int i = r; i < r + n; ++i) {
        for (int j = c; j < c+ n; ++j) {
            if(k!=board[i][j])
                flag = false;
        }
    }

    if(flag){
        cout << k;
        return;
    }

    int half = n/2;

    cout << "(";
    func(half,r,c);
    func(half,r,c+half);
    func(half,r+half,c);
    func(half,r+half,c+half);

    cout << ")";

    return;

}

int main(void){

    int n;

    cin >> n;
    cin.tie(0);

    for (int i = 0; i < n; ++i) {
        //for (int j = 0; j < n; ++j) {
            cin >> board[i];

       //    cout << board[i][j];
        //}
    }

    func(n,0,0);

}
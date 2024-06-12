//
// Created by dasoya on 1/28/24.
//
#include "vector"
#include "iostream"
#include "queue"

using namespace std;
int board[2200][2200];
int ans[3];

int sum = 0;
void func(int n, int w,int h){ // 0, 1,1

    int flag = board[w][h];

    bool all = true;
    for (int i = w ; i < w+n ; ++i) {
        for (int j = h ; j < h+n ; ++j) {
           if(board[i][j]!=flag) all = false; }}

    if(all || n==1) {

        if(flag == -1)
            ans[0]++;
        else ans[flag+1]++;

       // cout << flag <<"("<<w<<","<<h<<")\n";
        return;
    }

    //9분할 하는 과정


                for (int l = 0; l < 3; ++l) {
                    for (int m = 0; m < 3; ++m) {
                        func(n/3,w+l*n/3,h+m*n/3);
                        sum++;
                       // cout << "func" <<n/3<<"("<<w+l*n/3<<","<<h+m*n/3<<")\n";
                    }
                }


}

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {

            cin >> board[i][j] ;
        }
    }

    func(n,0,0);

    for (int i = 0; i < 3; ++i) {
        cout << ans[i] << "\n";
    }

    // cout <<sum;

}
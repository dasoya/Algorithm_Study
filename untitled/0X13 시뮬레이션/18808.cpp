
#include "bits/stdc++.h"

using namespace std;

int n,m,k;
int r,c;
int board[43][43];

bool match(int *sticker[13], int x, int y){

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if(board[x+i][y+j]==1&&sticker[i][j]==1) return false;
        }
    }

    //그리기

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
           // board[i+x][j+y] = sticker[i][j]; 이 코드는 1이 0으로 덮혀질 가능성 있음...ㄴㄴ..
            if(sticker[i][j] == 1)
                board[x+i][y+j] = 1;
        }

    }

    return true;
}

void turn(int *sticker[13]){

    int tmp[12][12];

    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            tmp[i][j] = sticker[i][j];

    for(int i = 0; i < c; i++)
        for(int j = 0; j < r; j++)
            sticker[i][j] = tmp[r-1-j][i];

    swap(r, c);

//    int newS[13][13];
//
//    for(int i = 0; i<r; i++){
//        for (int j = 0; j < c; ++j) {
//            newS[i][j] = sticker[i][j];
//        }
//
//    }
//
//    for(int i = 0; i < c; i++){ // 0,2
//        for (int j = 0; j < r; ++j) { // 0,0
//            sticker[i][j] = newS[r-1-j][i];
//        }
//    }
//
//
//    swap(r,c);

}

//y 먼저인 걸 잊지마!
void matchSticker(int *sticker[13]){

    // i,j를 순회하면서 맞나 안맞나 보는겨
    //i와 j를 순회한다는건
    for (int dir = 0; dir < 4; ++dir) {

        for (int x = 0; x <= n-r; ++x) {

            for (int y = 0; y <= m - c; ++y) {

                if (match(sticker, x, y)) return;
                // cout << k<<") "<< x <<" "<< y << " : ";

            }
        }

        turn(sticker);
    }


}

int main(){

    ios::sync_with_stdio(0);
    cin >> n >> m >> k;

    while (k--){

        int *sticker[13];
        cin >> r >> c;

        for (int i = 0; i < 13; ++i) {
            sticker[i] = new int[13];
        }

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> sticker[i][j];
               // cout <<  sticker[i][j]<<" ";
            }
           // cout << "\n";
        }

        //matchSticker(sticker);

        for(int rot = 0; rot < 4; rot++){
            bool is_paste = false; // 해당 스티커를 붙였는가?
            for(int x = 0; x <= n-r; x++){
                if(is_paste) break;
                for(int y = 0; y <= m-c; y++){
                    if(match(sticker,x, y)){
                        is_paste = true;
                        break;
                    }
                }
            }
            if(is_paste) break;
            turn(sticker);
        }
    }

    int cnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cnt += board[i][j];

    cout << cnt;

}



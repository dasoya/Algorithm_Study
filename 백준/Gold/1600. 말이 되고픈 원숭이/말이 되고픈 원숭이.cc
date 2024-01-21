//
// Created by dasoya on 1/21/24.
//

#include "iostream"
#include "queue"
#include "tuple"


using namespace std;

//앞의 8번이 night의 이동 경우
int dx[12] = {1,2,2,1,-1,-2,-2,-1,1,-1,0,0};
int dy[12] = {2,1,-1,-2,-2,-1,1,2,0,0,1,-1};


int board[202][202];
int dist1[32][202][202];
//int dist2[202][202];

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int k , w, h;

    cin >> k >> w >> h;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> board[i][j];
        }
    }

    queue<tuple<int,int,int>> Q;

    for (int j = 0; j < 31; ++j) {
        for (int i = 0; i < h; ++i) {
            fill(dist1[j][i],dist1[j][i]+w,-1);
        }
    }

    Q.push({0,0,k});
    dist1[k][0][0] = 0;

    while(!Q.empty()){

        int x,y,ck;

        tie(x,y,ck) = Q.front(); Q.pop();

//        if(x==1&&y==2){
//            cout << ck;
//        }

        for (int i = 0; i < 12; ++i) {

            if(x==h-1 && y==w-1){

                cout << dist1[ck][x][y];
//
                return 0;
            }

            int nx = x + dx[i];
            int ny = y + dy[i];
            int nk = ck;

            if(i<8) {nk--;}

            //메모리 초과 문제 -> Q에 데이터가 계속 쌓이는 듯함. 보통 visit한 곳을 다시 visit하면은 발생하기도하죠...
            if(nx<0 || nx>=h || ny<0 || ny>=w || nk<0 ) continue;
            if(board[nx][ny]==1) continue;
            if(dist1[nk][nx][ny] >= 0) continue; // 근접 시 visit 확인
           // if(i<8&&dist1[nk][nx][ny]>=0) continue; // night 이동 시 visit 확인 분리!


            Q.push({nx,ny,nk});
            dist1[nk][nx][ny] = dist1[ck][x][y]+1;
        }

    }

//    for (int i = 0; i <= k; ++i) {
//        for (int j = 0; j < h; ++j) {
//            for (int l = 0; l < w; ++l) {
//                cout << dist1[k][j][l] <<" ";
//            }
//            cout << "\n";
//        }
//        cout << "\n";
//    }


    cout << -1;


}
//
// Created by dasoya on 3/18/25.
//

#include "bits/stdc++.h"

using namespace std;

int board[10][10];
int n,m; //세로 n 가로 m, 세로 위치를 알려면 /m, 가로 위치 % m

int maxAns = 0;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main(){

    cin >> n >> m;

    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m;j++){
            cin >> board[i][j];
        }

    //bfs로 안전 영역 크기를 구하는데.
    //1을 두는건 백트래킹으로? or 조합.
    //n*m크기 배열에 1 세개. -> 이미 2나 1이 있는 경우는 무시.
    int arr[n*m];

    fill(arr,arr+n*m,0);
    fill(arr+n*m-3,arr+n*m,1);//벽 세개를 채움.



    do{

        int nBoard[10][10];
        memcpy(nBoard,board,10*10* sizeof(int));

        queue<pair<int,int>> q;

        bool flag = false;
        for(int i = 0 ; i < n*m; i++) {

            if (arr[i] == 1 && nBoard[i / m][i % m] != 0)
            {
                flag = true;
                break;
            }

            if (arr[i] == 1 && nBoard[i / m][i % m] == 0)
                nBoard[i / m][i % m] = 1;


            if (nBoard[i / m][i % m] == 2){
                q.push({i/m,i%m});
            }

        }

        if(flag) continue;
        //bfs
        while(!q.empty()){

            auto cur = q.front(); q.pop();

            for(int dir = 0; dir < 4; dir++){

                int ny = cur.first + dy[dir];
                int nx = cur.second + dx[dir];

                if(nx < 0 || ny < 0 || ny >= n || nx >= m) continue;
                if(nBoard[ny][nx]==0){

                    nBoard[ny][nx] = 2;
                    q.push({ny,nx});
                }
            }


        }

        int ans = 0;
        for(int i = 0 ; i < n*m; i++) {

            if (nBoard[i / m][i % m] == 0){
                ans++;
            }

        }


        maxAns = max(ans,maxAns);

//        if(maxAns==ans){
//            for(int i = 0 ; i < n*m; i++) {
//
//                cout << nBoard[i / m][i % m] <<" ";
//                if((i+1)%m==0)
//                    cout << "\n";
//            }
//            cout << "\n_________\n";
//        }
    }while(next_permutation(arr,arr+n*m));


    cout << maxAns;


}
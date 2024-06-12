//
// Created by dasoya on 3/25/24.
//


#include "bits/stdc++.h"

using namespace std;

int dx[4] = {1,-1,0,0};// 우, 좌, 상, 하
int dy[4] = {0,0,1,-1};
vector<tuple<int,int,int>> cctv;
int mat[9][9];
int n, m;
int typeSize[5] = {4,2,4,4,1};

int minRes;
void drawHash(int *arr[9], int dir, int i,int j){


        int nx = i;
        int ny = j;

        while(true) {

            nx = nx + dx[dir];
            ny = ny + dy[dir];

            if(nx<0 || nx>=n || ny <0||ny >=m) return;
            if(arr[nx][ny] == 6) return;

            if(1 <=arr[nx][ny] && arr[nx][ny]<= 5) continue; // arr[nx][ny]!=0 으로 쓸 수도 있음

            arr[nx][ny] = 7;

        }


}

int resultCheck(int *arr[9]){

    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {

            if(1 <= arr[i][j] && arr[i][j]<= 7) continue;

            res++;
        }
    }

    return res;

}



void DrawBytype(int *arr[9],int type,int d, int i, int j){

    if(type == 1){
        drawHash(arr,d,i,j);
        return;
    }

    if(type == 2){

        if(d==1) d++;
        drawHash(arr,d,i,j);
        drawHash(arr,d+1,i,j);
        return;
    }

    if(type == 3){

        //우좌상하 0123
        //우상, 우하, 좌상, 좌하
        //02, 03, 12, 13
         if(d==0||d==1) {//02 13
            drawHash(arr,d,i,j);
             drawHash(arr,d+2,i,j);
        }

        if(d==2) {//03 ,12
            drawHash(arr,0,i,j);
            drawHash(arr,3,i,j);
        }
        if(d==3) {
            drawHash(arr,1,i,j);
            drawHash(arr,2,i,j);
        }
        return;
    }

    if(type == 4){

        for (int dir = 0; dir < 4; ++dir) {
            if(dir==d) continue;
            drawHash(arr,dir,i,j);

        }


    }

    if(type == 5){

        for (int dir = 0; dir < 4; ++dir) {
            drawHash(arr,dir,i,j);
        }
    }
}


void back(int k, int *arr[9]){

    if(k==cctv.size()) {

       int res =  resultCheck(arr);


       if(minRes>res){
           minRes = res;
//           for (int i = 0; i < n; ++i) {
//               for (int j = 0; j < m; ++j) {
//
//                   cout << arr[i][j] <<" ";
//               }
//               cout << "\n";
//           }
//           cout << "\n";
       }
       return ;
    }

    int type, i, j;
    tie(type, i, j) = cctv[k];

    int pre[9][9];

    //값 저장
    for(int l=0; l<n; l++)
        for (int i1 = 0; i1 < m; ++i1) {
            pre[l][i1] = arr[l][i1];
        }

    for (int l = 0; l < typeSize[type-1]; ++l) {
        DrawBytype(arr,type,l,i,j);

        back(k+1,arr);

        //값 복원
        for(int l=0; l<n; l++)
            for (int i1 = 0; i1 < m; ++i1) {
                arr[l][i1] = pre[l][i1];
            }
    }

    return;

}



int main(){

    cin >> n >> m;


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {

            cin >> mat[i][j];

            if(1 <= mat[i][j] && mat[i][j]<= 5){
                cctv.push_back({mat[i][j],i,j});
            }
        }
    }

    int *arr[9];
    for(int k=0; k<n; k++)
        arr[k] = mat[k];

    minRes = n*m;
    back(0,arr);

    cout << minRes;
}
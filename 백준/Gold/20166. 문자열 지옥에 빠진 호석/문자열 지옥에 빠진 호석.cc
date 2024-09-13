//
// Created by dasoya on 9/13/24.
//
#include "bits/stdc++.h"

using namespace std;

string mat[12];

int dx[8] = {1,-1,0,0,1,-1,-1,1};
int dy[8] = {0,0,1,-1,1,-1,1,-1};
int main(){

    int n,m,k;

    cin >> n >> m >> k;

    for(int i =0; i< n; i++){
        cin >> mat[i]; // string 입력은 언제나 주의 할것
    }

    unordered_map<string,int> arr;
    //n*m 각 자리에 대하여
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {

            int curX =  i;
            int curY = j;
            string curS;

            queue<tuple<int,int,string>> Q;
            curS = mat[i][j];
            Q.push({i,j,curS});
            arr[curS]++;
            //5자리 까지 함
            while(!Q.empty()){

                tie(curX,curY,curS) = Q.front();
                Q.pop();

                for(int y=0; y<8;y++){
                   int nx = (curX + dx[y] + n) % n ;
                   int ny = (curY + dy[y] + m) % m ;

                   string nS = curS + mat[nx][ny];
                   if(nS.length()>5) continue;
                   arr[nS]++;
                   Q.push({nx,ny,nS});
                }


            }

        }
    }

    while(k--){
        string query;
        cin >> query;
        cout << arr[query] << "\n";
    }
}
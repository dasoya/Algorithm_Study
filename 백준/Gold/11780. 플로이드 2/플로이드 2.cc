//
// Created by dasoya on 11/4/24.
//

#include "bits/stdc++.h"

using namespace std;
int nxt[102][102];

int main(){

    int mat[102][102];
    int n,m,a,b, cost;

    cin >> n >> m;

    for(int i = 0; i <= n; i++)
        fill(mat[i],mat[i]+n+1,INT_MAX);

    for(int i = 0 ;i < m;i++){
        cin >> a >> b >> cost;
        if(mat[a][b] > cost) {mat[a][b] = cost; nxt[a][b] = b;}
    }

    //1번 거쳐서 갈 수 있없 찾기
    for(int k = 1; k <= n; k++){
        for(int i = 1 ; i <= n ; i++)
            for(int j = 1; j <= n ; j++){
                if(i == j) continue;

                long long temp = (long long)mat[i][k]+mat[k][j];
                if(mat[i][j] >= temp) {
                    mat[i][j] = mat[i][k] + mat[k][j];

                    nxt[i][j] = nxt[i][k];
                }
            }

    }


    for(int i = 1 ; i <= n ; i++){
        for(int j = 1; j <= n ; j++){

            if(mat[i][j]==INT_MAX)  cout << 0 << " ";
            else cout << mat[i][j] << " ";
        }
        cout << "\n";
    }

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1; j <= n ; j++){

            if(mat[i][j]== INT_MAX) cout << 0;
            else{
                vector<int> path;
                int next = nxt[i][j];
                path.push_back(i);
                path.push_back(next);

                while(next != j){
                    next = nxt[next][j];
                    path.push_back(next);
                }

                cout << path.size() <<" ";

                for(int v : path){
                    cout << v << " ";
                }


            }
            cout << "\n";

        }}

}
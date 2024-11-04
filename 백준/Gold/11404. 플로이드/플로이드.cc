//
// Created by dasoya on 11/4/24.
//

#include "bits/stdc++.h"

using namespace std;



int main(){

    int mat[102][102];
    int n,m,a,b, cost;

    cin >> n >> m;

    for(int i = 0; i <= n; i++)
        fill(mat[i],mat[i]+n+1,INT_MAX);

    for(int i = 0 ;i<m;i++){
        cin >> a >> b >> cost;
        if(mat[a][b] > cost) mat[a][b] = cost;
    }

    //1번 거쳐서 갈 수 있없 찾기
    //s,t
    //k 번 노드를 거쳐갈 때 가장 작은 것...
    for(int k = 1; k <= n; k++){
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1; j <= n ; j++){
            if(i == j) continue;

                long long temp = (long long)mat[i][k]+mat[k][j];
                if(mat[i][j] >= temp)
                    mat[i][j] = mat[i][k]+mat[k][j];
            }

        }


    for(int i = 1 ; i <= n ; i++){
        for(int j = 1; j <= n ; j++){

            if(mat[i][j]==INT_MAX)  cout << 0 << " ";
            else cout << mat[i][j] << " ";
        }
        cout << "\n";
    }

}
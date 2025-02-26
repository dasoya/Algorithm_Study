//
// Created by dasoya on 2/26/25.
//
#include "bits/stdc++.h"

using namespace std;


int board[501][501];
vector<vector<pair<int,int>>> tetro;

//x,y가 인접해있는지
bool isAdj(pair<int,int> shape1,pair<int,int> shape2){

    if(shape1.first == shape2.first) return abs(shape1.second-shape2.second) == 1;
    if(shape1.second == shape2.second) return abs(shape1.first-shape2.first) == 1;

    return false;
}

bool isConn(vector<pair<int,int>>& shape){

    bool flag= false;


    for(int i =0; i < 4;i++){
        int cnt = 0;
        for(int j =0; j < 4;j++) {

            if(i==j) continue;

            if (isAdj(shape[i],shape[j])){
                cnt++;
            }

        }
        if(cnt==0) return false;
        if(cnt>=2) flag= true;
    }

    return flag;
}


int main() {

    int n, m;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    //4X4에서 인접해있는, 두 개 이상인 모양 저장
    vector<int> brute(16);

    fill(brute.begin()+12, brute.end(),1);

    do{
        vector<pair<int,int>> shape;
        for (int i = 0; i < 16; ++i) {
            if(brute[i]==1)
                shape.emplace_back(i%4,i/4);
        }

        //현재의 블럭이 주변 불럭이랑 인접해있는지 검사 응..
        if(isConn(shape)){
            tetro.emplace_back(shape);
        }

    }while(next_permutation(brute.begin(),brute.end()));

    int ans = 0;

    for (int i = 0; i < n-3; i++) {
        for (int j = 0; j < m-3; j++) {


            //i,j가 0,0
            for(auto v:tetro){
                int score = 0;
                for(auto p : v){
                    score += board[i+p.second][j+p.first];
                }
                if(score > ans){
                    ans = score;
                }
            }



        }
    }

    cout << ans;


}


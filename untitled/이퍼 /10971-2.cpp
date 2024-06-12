//
// Created by dasoya on 3/24/24.
//

#include "bits/stdc++.h"

using namespace std;

const int INF = 1e8;

vector<bool> visited;
vector<vector<int>> matrix;
int ans = INF;


void back(int n, int cnt, int cur_city, int cost){

    if(cost >= ans)
        return;

    if(cnt == n ){
        if(matrix[cur_city][0] != 0){

            //이게 어찌하여 되는고?
            //시작점을 고정해도 됨..... 왜냐면,,,, 어차피 하나여도 괜찮으니까....
            ans = min (ans, cost+matrix[cur_city][0]);
        }

        return;
    }


    for (int i = 0; i < n; ++i) {
        if(matrix[cur_city][i] && ! visited[i]){
            visited[i] = true;

            back(n,cnt+1,i,cost+matrix[cur_city][i]);
            visited[i] = false;
        }
    }
}


int solution(const int n, const vector<vector<int>>& cost) {
    visited.assign(n, false);
    matrix = cost;

    //연산
    visited[0] = true;
    back(n, 1, 0, 0);

    return ans;
}

int main(){
    int n;
    vector<vector<int>> cost;
    int answer;

    //입력
    cin >> n;
    cost.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    answer = solution(n, cost);

    //출력
    cout << answer;
    return 0;
}
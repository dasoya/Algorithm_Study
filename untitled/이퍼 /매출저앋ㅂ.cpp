//
// Created by dasoya on 3/23/24.
//

#include "bits/stdc++.h"

using namespace std;

vector<vector<int>> dp;

//트리는 팀의 구조를 표시함. tree의 갯수가 팀의 갯수이다..!
vector<vector<int>> makeTree(int n, vector<vector<int>> links){

    vector<vector<int>> tree(n,vector<int>(0));

    for (auto leaf : links) {

        tree[leaf[0]].push_back(leaf[1]);

    }
    return tree;
}

int fillDp(vector<int> &sales, vector<vector<int>> &tree,int node, bool flag){

    if(dp[node][flag] != -1) // 현재 노드의 값이 저장 되어있다면 반환.
        return dp[node][flag];

    if(tree[node].empty()) // 리프 노드라면
        return dp[node][flag] = flag ? sales[node-1] : 0; //참석한다면 sales를 반환, flase라면 0으로 초기화!

    dp[node][flag] = 0;
    bool attend_flag = false;
    int diff = INT32_MAX;

    //부하직원 순회
    for (int i = 0; i < tree[node].size(); ++i) {
        int next_node = tree[node][i];
        int attend = fillDp(sales,tree,next_node,true);
        int absent =  fillDp(sales,tree,next_node, false);

        dp[node][flag] += min(attend,absent);

        if(attend < absent) attend_flag = true; // attend가 이득이라면 참석한다.
        diff = min(diff,attend-absent);
    }

    //팀장 참석
    if(flag) return dp[node][flag] += sales[node-1];
    //팀장 + 부하직원 모두 불참한다면
    if(!attend_flag) return dp[node][flag] += diff;
    return  dp[node][flag];
}

int solution(vector<int> sales, vector<vector<int>> links) {
    int v = sales.size();
    dp.assign(v + 1, vector<int>(2, -1));
    vector<vector<int>> tree = makeTree(v + 1, links); //트리 만들기

    //CEO가 참석하는 경우, CEO가 참석하지 않는 경우

    //Point!  팀장이 출석 안했다면 팀원중에 한명은 출석해야함
    // 출석 했다면 상관 없음.
    return min(fillDp(sales, tree, 1, true), fillDp(sales, tree, 1, false));
}

int main() {
    vector<int> sales = {14, 17, 15, 18, 19, 14, 13, 16, 28, 17};
    vector<vector<int>> links = {{10, 8},
                                 {1,  9},
                                 {9,  7},
                                 {5,  4},
                                 {1,  5},
                                 {5,  10},
                                 {10, 6},
                                 {1,  3},
                                 {10, 2}};
    int ans = solution(sales, links);
    cout << ans;
}
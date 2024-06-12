//
// Created by dasoya on 3/23/24.
//


#include "bits/stdc++.h"

using namespace std;
typedef vector<vector<int>> vi;


vi dp;

vi makeTree(int n, vi links){

    vi tree(n,vector<int>(0));
    for (auto i: links) {
        tree[i[0]].push_back(i[1]);
    }
    return tree;
}

int fillDP(vector<int> sales, vi tree, int node, bool flag){

    if(dp[node][flag] != -1)
        return dp[node][flag];

    if(tree[node].empty()){
        return dp[node][flag] = flag ? sales[node-1] : 0;
    }

    dp[node][flag] = 0;
    bool attend_flag = false;
    int diff = INT32_MAX;

    for (int i = 0; i < tree[node].size(); ++i) {

        int next_node = tree[node][i];
        int attend = fillDP(sales,tree,next_node,true);
        int absent = fillDP(sales,tree,next_node,false);

        dp[node][flag] += min(attend, absent);

        if(attend < absent) attend_flag = true;

        diff = min(diff,attend-absent);
    }

    if(flag) return dp[node][flag] += sales[node-1];

    if(!attend_flag) return dp[node][flag] += diff;

    return dp[node][flag];
}

int solution(vector<int> sales, vector<vector<int>> links) {

    int v = sales.size();

    dp.assign(v+1, vector<int>(2,-1));
    vector<vector<int>> tree = makeTree(v+1,links);

    return min(fillDP(sales,tree,1,true),fillDP(sales,tree,1,false));


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
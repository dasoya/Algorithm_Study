#include <string>
#include <vector>

using namespace std;


vector<vector<int>> dp;


vector<vector<int>> makeTree(int n, vector<vector<int>> links){
    vector<vector<int>> tree(n,vector<int>(0));
    
    for(auto i:links){
        tree[i[0]].push_back(i[1]);
    }
    return tree;
    
}

int fillDp(vector<vector<int>> &tree,vector<int> &sales,int node,bool flag){
    
    if(dp[node][flag]!=-1) return dp[node][flag];
    
    if(tree[node].empty()){ // 리프 노드일때
        
        dp[node][flag]  = flag ? sales[node-1] : 0;
        return dp[node][flag] ;
    }
    
    dp[node][flag] = 0 ;
    bool attend_flag = false;
    int diff = INT32_MAX;
    for(int i =0; i< tree[node].size();i++){
        
        int next_node = tree[node][i];
        
        int attend = fillDp(tree,sales,next_node,true);
        int absent = fillDp(tree,sales,next_node,false);
        
        dp[node][flag] += min(attend, absent);
        
        if(attend < absent) attend_flag = true;
        
        diff = min(diff,attend-absent);
        
    }
    
    
    
    if(flag) {
        dp[node][flag] += sales[node-1];
        return dp[node][flag];
    }
    
    if(!attend_flag){
        dp[node][flag] += diff;
            return dp[node][flag];
    }
        
    return dp[node][flag];
    
}

int solution(vector<int> sales, vector<vector<int>> links) {
    int answer = 0;
    int v = sales.size();

    dp.assign(v+1,vector<int>(2,-1));
    vector<vector<int>> tree;
    tree = makeTree(v+1, links);
    
    answer = min(fillDp(tree,sales,1,true),fillDp(tree,sales,1,false));
    
    return answer;
}
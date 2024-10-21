//
// Created by dasoya on 10/21/24.
//

#include "bits/stdc++.h"

using namespace std;
vector<int> adj[1001];
int indegree[1001];

int main(){

    int n,m;
    cin >> n >> m;

    while(m--){
        int count,input,pre = -1;
        cin >> count ;
        while(count--){
            cin >> input;
            if(pre != -1) {
                adj[pre].push_back(input);
                indegree[input]++;
            }
            pre = input;
        }
    }

    queue<int> q;
    for(int i = 1; i<=n;i++)
        if(indegree[i]==0) q.push(i);

    vector<int> ans;
    while(!q.empty()){

        int cur = q.front(); q.pop();
        ans.push_back(cur);

        for(auto nxt : adj[cur]){
            indegree[nxt]--;
            if(indegree[nxt]==0) q.push(nxt);
        }
    }

    if(ans.size() != n) cout <<"0";
    else{
        for(auto i : ans){
            cout << i <<"\n";
        }
    }
}
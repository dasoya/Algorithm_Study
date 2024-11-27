//
// Created by dasoya on 11/27/24.
//
#include "bits/stdc++.h"

using namespace std;

int p[55];
vector<int> adj[54];

int main(){

     int n;
     cin >> n;

     int root = -1;
     for(int i = 0 ; i< n ; i++){
         cin >> p[i];
         if(p[i] == -1) root = i;
         else adj[p[i]].push_back(i);
     }

     int d;
     cin >> d;

     queue<int> q;
     int ans = 0;

     if(root != d) q.push(root);
//     if(adj[root].size()==0) ans++;
//     else if(adj[root].size()==1 &&adj[root][0] == d) ans++;

     while(!q.empty()){
         int cur = q.front(); q.pop();
         if(adj[cur].size()==0) ans++;
         else if(adj[cur].size()==1 &&adj[cur][0] == d) ans++;

         for(int nxt : adj[cur]){
            if(nxt == d) continue;
            q.push(nxt);
         }
     }

    cout << ans;



}
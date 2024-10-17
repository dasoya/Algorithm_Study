//
// Created by dasoya on 10/17/24.
//

#include "bits/stdc++.h"

using namespace std;

int levelByNode[10001];
int col[10001];
int lc[10001];
int rc[10001];
int pn[10001];
int idx = 1;
vector<int> level[1000];

void inorder(int cur){

    if(lc[cur] != -1) inorder(lc[cur]);
    col[cur] = idx++;
    if(rc[cur] != -1) inorder(rc[cur]);
}

void indexlevel(int root){

    queue<int> q;
    q.push(root);
    levelByNode[root] = 1;
    level[1].push_back(col[root]);

    while(!q.empty()){
        int cur = q.front(); q.pop();

       if(lc[cur] != -1)
       {
           q.push(lc[cur]);
           levelByNode[lc[cur]] = levelByNode[cur]+1;
           level[levelByNode[lc[cur]]].push_back(col[lc[cur]]);
       }
       if(rc[cur] != -1)
       {
           q.push(rc[cur]);
           levelByNode[rc[cur]] = levelByNode[cur]+1;
           level[levelByNode[rc[cur]]].push_back(col[rc[cur]]);}
       }

}

int main(){

    cin.tie(0);

    int n,p,l,r;

    cin >> n;

    for(int i = 0 ; i<n;i++){
        cin >> p >> l >> r;

         lc[p] = l;
         rc[p]= r;
         pn[l] = p;
         pn[r] = p;
    }

    int root = 1;
    for(int i = 1 ; i<=n;i++){
        if(pn[i]==0){
            root = i;
            break;
        }
    }


    inorder(root); //root가 1이라는 보장 없음.
    indexlevel(root);

    int ansL=0,ansWidth=0;

    int idx = 1;
    while(!level[idx].empty()){
        int rightest = *max_element(level[idx].begin(),level[idx].end());
        int leftest = *min_element(level[idx].begin(),level[idx].end());

        if(ansWidth < rightest -leftest +1){
            ansL = idx;
            ansWidth = rightest -leftest +1;
        }
        idx++;
    }

    cout << ansL <<" "<< ansWidth;
}
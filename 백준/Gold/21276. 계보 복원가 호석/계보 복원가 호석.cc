//
// Created by dasoya on 10/21/24.
//

#include "bits/stdc++.h"

using namespace std;

vector<int> adj[1001];
vector<string> child[1001];

int indegree[1001];

int main(){

    int n,m;
    map<string,int> StToidx;
    vector<string> names;
    cin >> n;
    string input,x,y;
    for(int i =0;i<n;i++){
        cin >> input;
        StToidx[input] = i;
        names.push_back(input);
    }

    cin >> m;

    while(m--){
        cin >> x >> y;
        adj[StToidx[y]].push_back(StToidx[x]);
        indegree[StToidx[x]]++;
    }

    vector<int> roots;
    vector<string> roots_name;


    for(int i =0;i<n;i++){
        if(indegree[i]==0) {
            roots_name.push_back(names[i]);
            roots.push_back(i);
        }
    }

    //위상 정렬 방식으로 root 에서 하나씩 제거.

    for(int root : roots){
        queue<int> q;
        q.push(root);

        while(!q.empty()){
            int cur = q.front(); q.pop();

            for(auto ch : adj[cur]){

                indegree[ch]--;
                if(indegree[ch]==0) {
                    q.push(ch);
                    child[cur].push_back(names[ch]);
                }

            }

        }
    }


    cout << roots.size() << "\n";
    std::sort(roots_name.begin(), roots_name.end());
    for(auto k : roots_name){
        cout << k <<" ";
    }
    cout <<"\n";

    vector<string> sortedName(names);
    std::sort(sortedName.begin(), sortedName.end());

    for(auto s : sortedName){

        cout << s <<" " << child[StToidx[s]].size() <<" ";

        sort(child[StToidx[s]].begin(), child[StToidx[s]].end());

        for(auto ch : child[StToidx[s]]){
            cout << ch <<" ";
        }
        cout << "\n";
    }

}
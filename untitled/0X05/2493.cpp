//
// Created by dasoya on 22.09.23.
//

#include "bits/stdc++.h"

using namespace std;

#define X first
#define Y second

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n ;
    cin >> n;

    stack<pair<int,int>> tower;

    tower.push({100000001,0});

    for (int i = 0; i < n; ++i) {

        int height;
        cin >> height;

        while(tower.top().X < height){
            tower.pop();
        }
        cout << tower.top().second << " ";
        tower.push({height,i+1});

    }
    

}
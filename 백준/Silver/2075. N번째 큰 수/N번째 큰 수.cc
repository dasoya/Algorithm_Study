//
// Created by dasoya on 10/3/24.
//


#include "bits/stdc++.h"

using namespace std;

int arr[1501][1501];
int idx[1501];

int main(){

    int n;
    cin >> n;

    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int temp;
    
    for(int i = 0 ;i < n; i++){
        for(int j = 0 ; j  < n ; j++){
            cin >> temp;
            arr[i][j] = temp;
            idx[j] = n-1;
        }
    }

    priority_queue<pair<int,int>> pq;

    for(int j = 0; j < n ; j++){

        pq.push({arr[n-1][j],j});
    }

    while(n!=1){

        int j = pq.top().second;
        pq.pop();

        idx[j]--;
        pq.push({arr[idx[j]][j],j});
        n--;
    }

    cout << pq.top().first;
}
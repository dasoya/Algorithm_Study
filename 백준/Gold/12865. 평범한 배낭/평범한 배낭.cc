//
// Created by dasoya on 6/25/24.
//


#include "bits/stdc++.h"

using namespace std;

int main(){

    int n,k;

    pair<int,int> arr[105];


    cin >> n >> k;

    vector<vector<int>> dp(n+1,vector<int>(k+1,0));

    for (int i = 1; i <= n; ++i) {
       cin >> arr[i].first >> arr[i].second; // w, v
    }

  //  sort(arr,arr+n);


    for (int i = 1; i <= n; ++i) {

        
        for (int j = 0; j <= k; ++j) {
            dp[i][j] = dp[i-1][j];

            if(j>=arr[i].first)
            dp[i][j] = max(dp[i-1][j],dp[i-1][j-arr[i].first]+arr[i].second);
               // cout << dp[i][j] <<"\n";
        }
    }

  //  for (int j = 0; j <= k; ++j)
    cout << dp[n][k]; // << " ";
}
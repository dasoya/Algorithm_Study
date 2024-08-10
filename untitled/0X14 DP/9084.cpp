//
// Created by dasoya on 5/5/24.
//
#include "bits/stdc++.h"

using namespace std;

int main(){

    int t;

    cin >> t;

    while(t--){

        int n,  m;
        int coins[25];
        cin >> n ;

        for (int i = 0; i < n; ++i) {
            cin >> coins[i];
        }

        cin >> m;

        int dp[10004];

        fill(dp,dp+10004,0);

        dp[0] = 1;

        for(int i = 0; i < n; i++){
            for (int j = coins[i]; j <= m; ++j) {
                dp[j] += dp[j-coins[i]]; //j에 추가
            }
        }

        cout << dp[m] << "\n";


    }
}

//4 1,1,1,1 2,1,1 2,2

//  1 2 3 4 5
//1 1 2 1 3 1
//2 1 2 2 3                  dp[j] += dp[j-coins[i]]

//  4 5 6 7 10 14 15 20 21 22
//5 0 1 0 1 1  1   1  1 1   2

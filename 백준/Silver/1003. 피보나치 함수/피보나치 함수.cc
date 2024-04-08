//
// Created by dasoya on 4/8/24.
//


#include "bits/stdc++.h"
using namespace std;


int dp[42][2];


int main(){

    int t = 0;

    cin >> t;

    while(t--){
        int k;
        cin >> k;

        dp[0][0] = 1;
        dp[0][1] = 0;
        dp[1][0] = 0;
        dp[1][1] = 1;

        for (int i = 2; i <= k; ++i) {
            dp[i][0] = dp[i-1][0] + dp[i-2][0];
            dp[i][1] = dp[i-1][1] + dp[i-2][1];
        }

        cout << dp[k][0] << " " << dp[k][1] << "\n";
    }

}
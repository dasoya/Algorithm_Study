//
// Created by dasoya on 7/27/24.
//

#include "bits/stdc++.h"
#include "iostream"

using namespace std;

int main(){

    int n,k;
    cin >> n >> k;

    //nCk = n!/k!(n-k)!
    //nCk = n-1Ck-1 + n-1Ck
    //2C1 == 1C0 + 1C1

    int dp[1005][1005];

    for (int i = 1; i <= n; ++i) {

        dp[i][0] = dp[i][i] = 1;

        for (int j = 1; j < i; ++j) {
            dp[i][j] = (dp[i-1][j] + dp[i-1][j-1])%10007 ;
        }
    }

    cout << dp[n][k];




}
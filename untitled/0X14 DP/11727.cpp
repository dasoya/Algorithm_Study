//
// Created by dasoya on 4/11/24.
//

#include "bits/stdc++.h"

using namespace std;

int main(){

    int mod = 10007;

    int n;
    cin >> n;

    int dp[1003];

    dp[0]=0;
    dp[1]=1;
    dp[2]=3;

    for (int i = 3; i <= n; ++i) {
        dp[i] = (dp[i-1] + dp[i-2]*2) %mod;

    }

    cout << dp[n];



}
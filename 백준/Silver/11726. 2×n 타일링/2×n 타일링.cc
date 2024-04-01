//
// Created by dasoya on 4/1/24.
//


#include "bits/stdc++.h"

using namespace std;

int main(){

    int n ;

    cin >> n;


    int dp[1001];


    dp[1] = 1;
    dp[2] = 2;
    int mod = 10007;
    for (int i = 3; i <=n; ++i) {

        dp[i] = (dp[i-1]+dp[i-2])%mod;
    }

    cout << dp[n];

}
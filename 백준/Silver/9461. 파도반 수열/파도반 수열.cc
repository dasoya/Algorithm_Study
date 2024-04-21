//
// Created by cse_123 on 2024-04-21.
//

#include "bits/stdc++.h"

using namespace std;

int main(){


    int t;

    cin >> t;

    long long dp[105];

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    dp[6] = 3;
    dp[7] = 4;
    dp[8] = 5;
    dp[9] = 7;
    //1, 1, 1, 2, 2, 3, 4, 5, 7,  |9, 12, 16 21
    //1  1  1  11 2  21 31 41 52 |72 93 124 165
    for(int i=10; i<=100;i++){
        dp[i] = dp[i-1] + dp[i-5];
    }
    while(t--){

        int n;

        cin >> n;
        cout << dp[n]<<"\n";

    }

}
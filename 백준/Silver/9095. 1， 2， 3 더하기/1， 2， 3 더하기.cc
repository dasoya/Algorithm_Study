//
// Created by dasoya on 3/28/24.
//


#include "iostream"
#include "bits/stdc++.h"

using namespace std;


int main(){

    int dp[11] = {0,};

    int t;

    cin >> t;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4; //111.12.21.3

    while (t--){

        int n;

        cin >> n;

        for(int i = 4; i <= n ; i++){
            //점화식으로 dp[4]를 만드는 법 = dp[3](1을 더해서 4가 되는 수) + dp[2] + dp[1]
            //111+1,12+1,21+1,3+1 dp[3]
            //11+2,2+2dp[2]
            //1+3 dp[3]
            if(dp[n] != 0) continue;
            dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
        }

        cout << dp[n] << "\n";

    }

}
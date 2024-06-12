//
// Created by dasoya on 4/14/24.
//
#include "bits/stdc++.h"

using namespace std;

int main(){
    
    int n;
    
    cin >> n;

    long long dp[92][2];


    dp[1][0] = 0;//
// Created by dasoya on 4/14/24.
//
#include "bits/stdc++.h"

    using namespace std;

    int main(){

        int n;

        cin >> n;

        long long dp[92][2];


        dp[1][0] = 0;
        dp[1][1] = 1; //1
        dp[2][0] = 1; //10
        dp[2][1] = 0;



        for (int i = 3; i <=n; ++i) { //101 100
            dp[i][1] = dp[i-1][0];
            dp[i][0] = dp[i-1][0]+dp[i-1][1];
        }

        cout << dp[n][0] + dp[n][1];

    }
    dp[1][1] = 1; //1
    dp[2][0] = 1; //10
    dp[2][1] = 0;



    for (int i = 3; i <=n; ++i) { //101 100
        dp[i][1] = dp[i-1][0];
        dp[i][0] = dp[i-1][0]+dp[i-1][1];
    }

    cout << dp[n][0] + dp[n][1];
    
}
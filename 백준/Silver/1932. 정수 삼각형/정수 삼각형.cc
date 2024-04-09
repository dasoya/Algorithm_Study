//
// Created by dasoya on 4/9/24.
//

#include "bits/stdc++.h"
using namespace std;


int main(){

    int n;

    cin >> n;

    long long dp[200000];

    int tri[200000];


    for (int i = 0; i < n*(n+1)/2 ; ++i) {
        cin >> tri[i];
    }


    dp[0] = tri[0];

    long long res = dp[0];

    int k = 1 ; //층 수
    int nf = 3;
    for (int i = 1; i < n*(n+1)/2; ++i) {

        if(nf == i){
            k++;
            nf = (k+1)*(k+2)/2;
            dp[i] = dp[i-k]  + tri[i];
            res = max(res,dp[i]);
            continue;
        }
        else if (nf-1 == i ){
            dp[i] = dp[i-k-1]  + tri[i];
            res = max(res,dp[i]);
            continue;
        }


        int max_p = max(dp[i-k] ,dp[i-k-1]);
        dp[i] = max_p + tri[i];
        res = max(res,dp[i]);



    }



    cout << res;



}


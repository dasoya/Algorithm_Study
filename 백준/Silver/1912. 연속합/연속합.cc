//
// Created by dasoya on 4/15/24.
//


#include "bits/stdc++.h"

using namespace std;

int main(){

    int n;
    cin >> n;

    int arr[100004];
    int dp[100004];


    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
       dp[i]=   arr[i];
    }

    for (int i = 1; i < n; ++i) {
        dp[i] = max(dp[i],dp[i-1]+arr[i]);
    }

    cout << *max_element(dp,dp+n);

    //10 6  9 10 15 21
    //0 -4 -1
    //0  0  3 1 5 6 -35 12 21 -1
    //vector<vector<int>> dp(1,vector<int>(2,0));

//    dp[0][0] = arr[0];
//    dp[0][1] = 0;
//    int result = dp[0][0];
//    for (int i = 1; i < n; ++i) {
//        dp.push_back(vector<int>(i,0));
//        for(int j=0; j< i ;j++){
//            dp[i][j] = dp[i-1][j] + arr[i];
//            result = max(result,dp[i][j]);
//        }
//        result = max(result,arr[i]);
//    }


}
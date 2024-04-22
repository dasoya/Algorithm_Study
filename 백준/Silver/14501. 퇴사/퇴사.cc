//
// Created by cse_123 on 2024-04-22.
//


#include "bits/stdc++.h"

using namespace std;

int main(){

    int n;

    cin >> n;

    int dp[20]; // 1. 전역 변수로 선언하면 초기화 안해도 되지만 아니면 초기화해야함.
    int arr[17][2];

    fill(dp,dp+20,0);

    for (int i = 1; i <= n; ++i) {
        cin >> arr[i][0] >> arr[i][1];
    }

    for (int i = n; i >= 1 ; --i) {

        if(arr[i][0]+i <= n+1){
            dp[i] = max(dp[i+arr[i][0]]+arr[i][1], dp[i+1]);
        }
        else dp[i] = dp[i+1];

    }

    cout << *max_element(dp,dp+n+1);

}
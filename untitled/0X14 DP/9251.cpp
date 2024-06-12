//
// Created by dasoya on 5/3/24.
//
#include "bits/stdc++.h"

using namespace std;


int dp[1005][1005];//i와 j 공통 부분 배열의 수가 들어감

int main(){

    string input1, input2;

    cin >> input1 >> input2;

    //ACAYKP
    //CAPCAK

    for (int i = 1; i <= input1.length(); ++i) {
        for (int j = 1; j <= input2.length(); ++j) {
            if(input1[i-1]==input2[j-1])  dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }

    cout << dp[input1.length()][input2.length()];

}
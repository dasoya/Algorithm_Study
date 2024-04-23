//
// Created by dasoya on 4/23/24.
//

#include "bits/stdc++.h"

using namespace std;

long long dp[15000005];
int t[15000005];
int p[15000005];

int main(){

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> t[i] >> p[i];
    }

    for (int i = n; i > 0; --i) {

        if(i+t[i]<=n+1){

            //이번이 선택 됐을 때 -> t[i]만큼의 다음 수 부터 선택지를 볼 수 있음
            // 선택 안됐을 때 -> 바로 다음 부터 보면 됨!
            dp[i] = max(dp[i+t[i]]+p[i],dp[i+1]);
        }
        //dpi가 선택 안 됐을 때? 다음으로 넘어간다.!
        else dp[i] = dp[i+1];
    }

    cout << *max_element(dp+1,dp+n+1);
}
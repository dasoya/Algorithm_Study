//
// Created by dasoya on 3/30/24.
//

#include "bits/stdc++.h"

using namespace std;

int main(void){

    int n;

    cin >> n;

    vector<int> stair(n+1,0);

    for (int i = 1; i <= n; ++i) {
        cin >> stair[i];
    }

    int dp[301][3];

    dp[1][1] = stair[1];
    dp[1][2] = 0;
    dp[2][1] = stair[2];
    dp[2][2] = stair[1] + stair[2];

    // 3번째 계단에 오는 경우의 수
    // 2번째 전에서 or 1번째 전에서(바로 전에서 오면 안 된다는 조건 있음.)
    for (int i = 3; i <= n; ++i) {

        dp[i][1] = max(dp[i-2][2],dp[i-2][1]) + stair[i];
        dp[i][2] = dp[i-1][1] + stair[i];

    }

    cout << max(dp[n][1],dp[n][2]);



}//
// Created by dasoya on 3/30/24.
//

#include "bits/stdc++.h"

using namespace std;

int main(void){

    int n;

    cin >> n;

    vector<int> stair(n+1,0);

    for (int i = 1; i <= n; ++i) {
        cin >> stair[i];
    }

    int dp[301][3];

    dp[1][1] = stair[1];
    dp[1][2] = 0;
    dp[2][1] = stair[2];
    dp[2][2] = stair[1] + stair[2];

    // 3번째 계단에 오는 경우의 수
    // 2번째 전에서 or 1번째 전에서(바로 전에서 오면 안 된다는 조건 있음.)
    for (int i = 3; i <= n; ++i) {

        dp[i][1] = max(dp[i-2][2],dp[i-2][1]) + stair[i];
        dp[i][2] = dp[i-1][1] + stair[i];

    }

    cout << max(dp[n][1],dp[n][2]);



}
//
// Created by dasoya on 3/24/24.
//

using namespace std;

const int MOD= 1000000007;

int solution(int n){

    if(n%2==1) return 0;

    long long dp[5001] = {0,};

    dp[0] = 1;
    dp[2] = 3;

    //3*n 타일링의 근본

    for (int i = 4; i <= n; i += 2) {
        dp[i] = dp[i-2] *3;


        //j는 새로운 고려하는 뭉텅이 타일링의 갯수.
        for (int j = i-4 ; j >= 0 ; j -= 2) {
            dp[i] += dp[j] *2;
        }

        dp[n] %= MOD;
    }

    return dp[n];
}
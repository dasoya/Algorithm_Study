//
// Created by dasoya on 4/5/24.
//


#include "bits/stdc++.h"

using namespace std;

int main(){

    int dp[1000005], arr[1000005];//arr에는 그 전의 수 저장.

    int n;
    cin >> n;

    dp[1] = 0;
    dp[2] = 1; arr[2] = 1;
    dp[3] = 1; arr[3] = 1;

    for (int i = 4; i <= n; ++i) {

        dp[i] = dp[i-1]+1; arr[i] = i-1;
        if(i%2==0) {

            if(dp[i/2] < dp[i]) {
                dp[i] = dp[i/2]+1;
                arr[i] = i/2;
            }
        }

        if(i%3==0) {

            if(dp[i/3] < dp[i]) {
                dp[i] = dp[i/3]+1;
                arr[i] = i/3;
            }
        }

    }

    cout << dp[n] << "\n" ;

    int i = n;
   do {

        cout << i << " ";
        i = arr[i];
    }while(i>=1);

  //  cout << 1;

}
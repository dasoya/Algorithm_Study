
#include "bits/stdc++.h"

using namespace std;

int dp[100005];

int main(){

    int n;

    cin >> n;

    dp[1] = 1;

    int k = 1;//최대 제곱수.

    //1 2 3 4 5 6 7 8 9 10 11 12 13
    //1 2 3 1 2 3 4 2 1 2  3 4  2

    for(int i = 1; i<=n;i++){
        dp[i] = i;
        for (int j = 1; i >= j*j; ++j) {
            dp[i] = min(dp[i],dp[i-j*j]+1);
        }
    }


    cout << dp[n];

//    for (int i = 1; i <= n; ++i) {
//        cout << dp[i] <<" ";
//    }


}
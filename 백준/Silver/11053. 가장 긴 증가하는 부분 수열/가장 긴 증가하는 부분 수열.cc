//
// Created by cse_123 on 2024-04-19.
//
#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
    int n;

    cin >> n;

    int arr[1005],dp[1005];

    for(int i=0; i<n;i++){
        cin >> arr[i];
        dp[i] =1;
    }

    dp[0] = 1; //max
  //  dp[0][1] = arr[0]; //max 된 마지막 값

    for(int i=1; i<n;i++){


        for(int j = 1;j<=i;j++ ) {
            if (arr[i - j] < arr[i]) {

                dp[i] = max(dp[i],dp[i - j]+ 1) ;


            }
        }

    }

    cout << *max_element(dp,dp+n);


    return 0;


}

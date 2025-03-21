//
// Created by dasoya on 3/21/25.
//

#include "bits/stdc++.h"

using namespace std;

int board[20][20];

int main(){

    int n;
    cin >> n;

    for(int i =0 ; i< n;i++){
        for(int j =0 ; j< n;j++) {
            cin >> board[i][j];
        }
    }

    int arr[n];

    fill(arr,arr+n/2,0);
    fill(arr+n/2,arr+n,1);

    int ans = INT_MAX;

    do{

        int a = 0,b=0;

        for(int i = 0 ; i < n ;i++)
        {
            for(int j = 0 ; j < n ; j++) {

                if(i==j) continue;
                if (arr[i]) {
                    if(arr[j]) {
                        b += board[i][j];
                       // cout << "B" << i <<j<<"("<< board[i][j]<<") ";
                    }
                } else {
                    if(!arr[j]) {
                        a += board[i][j];
                       // cout << "A" << i <<j<<"("<< board[i][j]<<") ";
                    }
                }
            }
        }

      //  cout << abs(a-b) <<": " << a << " "<< b <<"\n ";
        ans = min(ans,abs(a-b));

    }while(next_permutation(arr,arr+n));

    cout << ans;
}
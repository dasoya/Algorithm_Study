//
// Created by dasoya on 8/13/24.
//

#include "bits/stdc++.h"

using namespace std;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(0);
    long long n, k;

    cin >> n >> k;

    int jari = 1, pow10 =10;

    for (int i = 1; i <= n; ++i) {


        if(i%pow10==0) {jari++; pow10 *=10;}

        k -= jari;

        if(k<=0){

            string cur = to_string(i) ;
            cout << cur[jari-1 +k];
            return 0;
        }
    }

    //  910     1  1
    //        1 1  0

    cout << -1;
   //15 9 2*

   //123
   // 0-1
   //1 10
   //1 0-1

   // 10

}
//
// Created by dasoya on 7/31/24.
//
#include "bits/stdc++.h"

using namespace std;

int main(){


    cin.tie(0);

    int n ;

    cin >> n ;

    //n!을 구하고 0 500 번연산
    //1 2 3 4   5   6   7 8  9  10
    //1 2 6 24 120 720 5040  40320
    // %10
    //1 2 6 4  2    2    14

    int ans  = 0;

    while(n){//10의 개수..... -> 2*5의 개순데 5의 갯수만 세면 된다?
        //n이 1 이상일 때
        ans += n/5;
        n/=5;//계속 5로 나누다 보면 몫이 0이됨.

        //10은 소인수가 아니까 소인수의 갯수를 세야 정확함,,,,

    }

    cout << ans;


}
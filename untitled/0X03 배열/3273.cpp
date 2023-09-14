//
// Created by dasoya on 13.09.23.
//

#include "bits/stdc++.h"

using namespace std;

int main(){
    int n,x;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cin >> x;

    // cnt 안에는 x-i 가 들어가는데, x는 2백만 까지 나올 수 있는 인덱스 범위 예외처리 신경써야함.!
    int cnt[2000001], result =0;

    fill(cnt,cnt+2000001,0);

    for(int i : arr){

        if(x <= i)
            continue;

        if(cnt[x-i] == 1) {
       // cout << x-i << "| ";
        result++;}
        else cnt[i]++;

    }

    cout << result;

}
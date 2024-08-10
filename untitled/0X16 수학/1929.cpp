//
// Created by dasoya on 7/14/24.
//

#include "bits/stdc++.h"

using namespace std;

int main(){


    cin.tie(0);
    int m, n;

    cin >> m >> n;

    vector<bool> arr(1000003, true);
    arr[1]= false;
    //에라토스 체
    // 일정한 범위에서 소수를 구하기 쉽게 만든것
    // 간단하게 배수를 소수가 아니라고 판단하면 됨.
    // 루트 엔 이하로만 소수가 존재함.
    for (int i = 2; i*i <= n; ++i) {

        if(!arr[i])
            // 제곱 이후엔 괜찮음
        for (int j = i*i ; j <= n; j+=i) {
            arr[j] = false;
        }
    }

    for (int i = m; i <= n; ++i) {
        if(arr[i])
            cout<< i << "\n";
    }

}
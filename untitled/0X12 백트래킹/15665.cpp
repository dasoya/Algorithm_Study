//
// Created by dasoya on 3/2/24.
//

#include "bits/stdc++.h"

using namespace std;


int arr[9],vec[9];

int m,n;
void func(int k){

    if(k==m){
        for (int i = 0; i < m; ++i) {
            cout << vec[i] << " ";
        }
        cout << "\n";
        return;
    }

    int pre = 0; //pre 는 바로 직전의 요소만 고려함. vec[k-1]과 완전히 다름. vec[k-1]은 재귀적으로 호출된 모든 변경 요소에 반응.

    for (int i = 0; i < n; ++i) {

        if(pre != arr[i]){
            vec[k] = arr[i];
            pre = vec[k];
            func(k + 1);
        }

    }

}

int main(){



    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    sort(arr,arr+n);

    func(0);

}
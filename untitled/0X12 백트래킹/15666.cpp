//
// Created by dasoya on 3/3/24.
//
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

    // 백트래킹은 m 칸에 숫자를 하나씩 채워나가면서 완성함. 바로 이전 수열은 지금까지 똑같은 같은 숫자를 선택한 수열들임.
    for (int i = 0; i < n; ++i) {

        if(pre != arr[i] && (k==0 || k != 0 && vec[k - 1] <= arr[i])){
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
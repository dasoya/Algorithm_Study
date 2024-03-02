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
    int pre = 0;

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
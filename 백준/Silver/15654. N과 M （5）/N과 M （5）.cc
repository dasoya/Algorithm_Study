//
// Created by dasoya on 2/19/24.
//
#include "bits/stdc++.h"

using namespace std;

int ans[9];
int arr[9];
int issued[9];
int n, m;
void func(int k){

    if(k==m){
        for (int i = 0; i < m; ++i) {
            cout << ans[i] <<" ";
        }

        cout <<"\n";
        return;
    }

    for (int i = 0; i < n; ++i) {
        if(!issued[i]) {
            ans[k] = arr[i];
            issued[i] = true;
            func(k + 1);
            issued[i] = false;
        }
    }
}
int main(void){

    cin >> n >> m ;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    sort(arr,arr+n);
    func(0);


}
//
// Created by dasoya on 2/21/24.
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

            ans[k] = arr[i];
            func(k + 1);

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
//
// Created by dasoya on 2/20/24.
//
//
// Created by dasoya on 2/19/24.
//
#include "bits/stdc++.h"

using namespace std;

int ans[9];
int arr[9];
int issued[9];
int n, m;

vector<int> vec;
void func(int k){

    if(k==m){
        for (int i = 0; i < m; ++i) {
            cout << ans[i] <<" ";
        }

        cout <<"\n";
        return;
    }

    for (int i = 0; i < n; ++i) {
        if(!issued[i]){
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
    //func(0);

    for (int i = 0; i < n; ++i) {
        vec.push_back( i < m ?  0 : 1);
    }

    do {
        for (int i = 0; i < n; ++i) {
            if (vec[i] == 0)
                cout << arr[i] << " ";
        }
        cout << "\n";
    } while(next_permutation(vec.begin(),vec.end()));



}
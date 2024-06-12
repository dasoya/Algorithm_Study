//
// Created by dasoya on 2/17/24.
//


#include "bits/stdc++.h"

using namespace std;

int arr[9];
int n, m;
void func(int k){

    if(k==m){
        for (int i = 0; i < m; ++i) {
            cout << arr[i] <<" ";
        }

        cout <<"\n";
        return;
    }

    for (int i = 0; i < n; ++i) {
        if(k==0 || arr[k-1] <= i+1) {
            arr[k] = i + 1;
            func(k + 1);
        }
    }
}
int main(void){



    cin >> n >>m ;
    func(0);


}
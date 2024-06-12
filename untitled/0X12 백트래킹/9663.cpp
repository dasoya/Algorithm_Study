//
// Created by dasoya on 2/11/24.
//

#include "bits/stdc++.h"

using namespace std;

int n;
int issued1[17];
int issued2[30];
int issued3[30];
int sum =0;

void func(int cur){

    if(cur==n){
        sum++;
        return;
    }

    for (int i = 0; i < n; ++i) {
        if(!issued1[i] && !issued2[i+cur] && !issued3[i-cur+n-1]){

            issued1[i] = true;
            issued2[i+cur] = true;
            issued3[i-cur+n-1]=  true;

            func(cur+1);
            issued1[i] = false;
            issued2[i+cur] = false;
            issued3[i-cur+n-1]= false;

        }

    }

}

int main(void){

    cin >> n;

    func(0);

    cout << sum;
}
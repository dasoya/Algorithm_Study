//
// Created by dasoya on 7/29/24.
//
#include "bits/stdc++.h"

using namespace std;

int main(){

    cin.tie(0);
    int x ;

    cin >> x;

    int index = 0, max = x;
    for (int i = 1; i <= max; ++i) {

        if(x <= i){
            index = i;
            break;
        }

        x-= i;
    }
    //int left,right = 0;//left+right = i
    //짝수면

    if(index%2==0){
        cout << x << "/" << index+1 - x;
    }else{
        cout << index+1 - x  << "/" << x;
    }
}

//1번, 2번, 3번, 4번, 5번.

// 1/1 → 1/2 → 2/1 → 3/1 → 2/2 -> 1/3
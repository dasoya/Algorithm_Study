//
// Created by dasoya on 13.09.23.
//

#include "bits/stdc++.h"

using namespace std;

int main(){

    int result = 1 ,i;

    for (int j = 0; j < 3; ++j) {
        cin >> i;
        result *= i;
    }
//0123 -> 3102
    string s = to_string(result);

    int arr[10] = {0,};

    for(char i : s){
        int temp =  i - '0';

        arr[temp]++;
    }

    for (int j = 0; j < 10; ++j) {
        cout << arr[j] << "\n";
    }


//    for(int &i: arr){
//    // arr[i]를 뽑으면 안됨 ㅠ
//        cout << i << "\n";
//    }

}
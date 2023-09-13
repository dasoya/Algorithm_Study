//
// Created by dasoya on 13.09.23.
//


#include "bits/stdc++.h"

using namespace std;

int main(){

    int n;
    cin >> n;

    int arr[9] = {};

    string s = to_string(n);

    for (int i = 0; i < s.length(); ++i) {
        int num = s[i] - '0';

        if(num == 9) arr[6]++;
        arr[num]++;
    }
    int temp = arr[6]%2;
    arr[6] /=2 ;
    arr[6] += temp;


    cout << *max_element(arr,arr+9);
}
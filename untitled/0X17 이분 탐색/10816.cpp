//
// Created by dasoya on 8/15/24.
//


#include "bits/stdc++.h"

using namespace std;
vector<int> arr;
int n;

int upper_idx(int k){

    int str = 0, end= n;

    while(str<end){

        int idx = (str+end)/2 ;
        int m = arr[idx];
        if( m > k) {
            end = idx ;

        }
        else {
            str = idx+1;
        }
    }

    return str;
}

int down_idx(int k){

    int str = 0, end= n;

    while(str<end){//str과 end가 같아진 순간 종료

        int idx = (str+end)/2 ;
        int m = arr[idx];
        if( m >= k) {
            end = idx;
        }
        else {
            str = idx+1;
        }
    }

    return str;
}

int main(){

    cin.tie(0);

    int m;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    std::sort(arr.begin(), arr.end());
    cin >> m;

    int k ;
    while(m--){

        cin >> k;
        cout << upper_idx(k) - down_idx(k) <<  " ";

    }

}
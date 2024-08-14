//
// Created by dasoya on 8/13/24.
//


#include "bits/stdc++.h"

using namespace std;
vector<int> arr;
int n;

int check(int k){

    int str = 0, end= n-1;

    while(str<=end){

        int idx = (str+end)/2 ;
        int m = arr[idx];
        if( m == k)
        {
            return 1;
        }
        else if(m > k){

            end = idx-1;


        }
        else {
            str = idx+1;
        }
    }

    return 0;
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
        cout << check(k) <<  "\n";

    }

}
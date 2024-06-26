//
// Created by dasoya on 6/23/24.
//

#include "iostream"

using namespace std;

int main(){


    int n,k;

    int arr[11];
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int res = 0;

    for (int i = n-1; i >=0 ; --i) {
        res += k/arr[i];
        k %= arr[i];
    }

    cout << res;


}
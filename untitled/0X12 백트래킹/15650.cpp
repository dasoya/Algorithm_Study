//
// Created by dasoya on 2/12/24.
//

#include "bits/stdc++.h"

using namespace std;
vector<int> arr;

int main(){

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        arr.push_back( i < m ?  0 : 1);
    }

    do {
        for (int i = 0; i < n; ++i) {
            if (arr[i] == 0)
                cout << i + 1 << " ";
        }
        cout << "\n";
    } while(next_permutation(arr.begin(),arr.end()));

}
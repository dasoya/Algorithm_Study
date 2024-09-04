//
// Created by dasoya on 8/29/24.
//

#include "bits/stdc++.h"
int m , n;
int mat[105][10005];
using namespace std;


void compress(int a[]){

    vector<int> v(a,a+n);
    sort(v.begin(),v.end());

    v.erase(unique(v.begin(),v.end()),v.end());

    for (int i = 0; i < n; ++i) {
        a[i] = lower_bound(v.begin(),v.end(),a[i]) - v.begin();
    }

}

bool compare(int a[], int b[]){

    for (int j = 0; j < n; ++j) {
        if(a[j]!=b[j]) return false;

    }

    return true;
}

int main(){

    cin >> m >> n;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> mat[i][j];
        }
        compress(mat[i]);
    }


    int ans = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = i+1; j < m; ++j) {
           if( compare(mat[i],mat[j])) ans++;
        }
    }


    cout << ans;


}
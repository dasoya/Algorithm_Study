//
// Created by dasoya on 2/24/24.
//

//
// Created by dasoya on 2/22/24.
//
//
// Created by dasoya on 2/21/24.
//

#include "bits/stdc++.h"

using namespace std;


int ans[9];
int arr[9];
int issued[9];
int n, m;


using namespace std;

void func(int k,int st){

    if(k==m){

        for (int i = 0; i < m; ++i) {
           cout << ans[i] <<" ";

        }

        cout <<"\n";
        return;
    }
    int pre = 0;
    for (int i = st; i < n; ++i) {
        if(pre != arr[i] ) {
            ans[k] = arr[i];
            pre = ans[k];
            func(k + 1,i+1);

        }

    }
}
int main(void){

    cin >> n >> m ;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    sort(arr,arr+n);
    func(0,0);


}
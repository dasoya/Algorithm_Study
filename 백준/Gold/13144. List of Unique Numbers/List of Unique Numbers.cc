

//
// Created by dasoya on 9/4/24.
//

#include "bits/stdc++.h"

using namespace std;

bool check[100005];

int main(){
    int n;
    cin >> n;

    int arr[100005];
    for(int i =0; i< n ; i++) cin >> arr[i];

    long long ans = n;
    int en = 0;

    for(int st=0;st<n;st++){// 투포인터 포문은 죄악이다. 난 무조건 while문으로 간다.

        while(en<n&&!check[arr[en]]){
            check[arr[en]] = true;
            ans += en-st;
            en++;
            if(en==n) break;
        }

        if(en==n) break;
        check[arr[st]] = false;
      //  ans++;
    }

    cout << ans;
}
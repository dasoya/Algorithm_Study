//
// Created by dasoya on 9/7/24.
//

#include "bits/stdc++.h"

using namespace std;

int main(){


    int n,d,k,c;

    cin >> n >> d >> k >> c;

    int arr[30005];
    for(int i = 0; i< n;i++) cin >> arr[i];

    int check[3001];

    int st=0,en = 0,tot=0;
    int ans = 0;

    //c를 포함하고 k개를 최대한 채울 수 있는 경우
    //c를 포함하지 않고 k
    while(st<n){

        while(en<st+k){
            if(!check[arr[en%n]]){
                tot++;
            }

            check[arr[en%n]]++;
            en++;
        }

       if(tot+1 >= ans) {
           if (!check[c]) tot++;// 쿠폰 초밥이 있는 지 없는 지 체크
           ans = max(ans,tot);
           if (!check[c]) tot--; // ans만 바꾸고 초기화
       }

        if(check[arr[st]] == 1) tot--;
        check[arr[st]]--;
        st++;

    }

    cout << ans;
}
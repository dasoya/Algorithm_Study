//
// Created by dasoya on 9/3/24.
//

#include "bits/stdc++.h"
using namespace std;

int main(){

  int n,s;
  
  cin >> n >> s;
  int a[100005];

    for (int i = 0; i < n; ++i) {

        cin >> a[i];
    }

 //   sort(a,a+n); 문제 조건상 sort를 하면 안됨. 
    int en=0;
    int sum = a[0];
    int ans = 0x7fffffff;

    //1 2 3 4 5 5 7 8 9 10
    for(int st=0;st<n;st++){

        while(en<n&& sum < s){
            en++;
            if(en==n) break;
            sum += a[en];
        }
        if(en==n) break;

        if(en>=st)
        ans = min(ans,en-st+1);
        sum -= a[st];
    }

    if(ans==0x7fffffff) cout << 0;
    else cout << ans;

}
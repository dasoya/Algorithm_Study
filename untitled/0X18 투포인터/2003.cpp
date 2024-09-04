//
// Created by dasoya on 9/3/24.
//

#include "bits/stdc++.h"

using namespace std;

int main(){

    int n,m;
    cin >> n >> m;
    int a[10005];
    for(int i=0;i<n;i++) cin >> a[i];

    int st=0,end =0,tot= a[0];
    long long ans =0;
    while(st<n){

        while(end<n&&tot <m){ end++;

            if(end==n)break;
            tot+=a[end];
        }
        if(end==n)break;

        if(tot==m) ans++;
        tot-=a[st++];
    }

    cout << ans;
}
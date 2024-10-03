//
// Created by dasoya on 10/3/24.
//

#include "bits/stdc++.h"

using namespace std;

int main(){

    int ans = 0;

    int n;
    cin >> n ;
    int x;
    priority_queue<int,vector<int>, greater<>> pq;

    for (int i = 0; i < n; ++i) {
         cin >> x;
         pq.push(x);
    }
    int a,b;

    while(pq.size()>1){

        a = pq.top(); pq.pop();
        b = pq.top(); pq.pop();

        ans += a+b;
        pq.push(a+b);

    }

    cout << ans;

}

//10
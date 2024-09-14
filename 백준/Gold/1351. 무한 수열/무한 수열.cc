//
// Created by dasoya on 9/13/24.
//


#include "bits/stdc++.h"
typedef long long ll;
using namespace std;
long long n,p,q;
unordered_map<long long,long long> m;
long long solve(ll n){

    if(n == 0) return 1;
    if(m.find(n)!=m.end()) return m[n];
    m[n] = solve(n/p) + solve(n/q);
    return m[n];
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    //Ai = i/p + i/q;
    cin >> n >> p >> q;

    m[0] =1;

    cout << solve(n);


}
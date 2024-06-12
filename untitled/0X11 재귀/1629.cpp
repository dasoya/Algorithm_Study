//
// Created by dasoya on 1/30/24.
//


#include "iostream"
#include "math.h"
using namespace std;

using ll = long long;

ll func(ll a,ll b, ll c){

    if(b==1)
        return a % c ;

    ll val = func(a,b/2,c);

    val = val * val % c;
    if(b%2==0) return val;
    return val * a % c ;
}

int main(void){

    ll a,b,c;
    cin >> a>> b>> c;

    cout << func(a,b,c);


}
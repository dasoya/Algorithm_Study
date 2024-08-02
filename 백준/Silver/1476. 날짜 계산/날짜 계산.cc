//
// Created by dasoya on 8/2/24.
//


#include "bits/stdc++.h"

using namespace std;

int main(){

    int e,s,m;

    cin >> e >> s >> m ;
    //15 28 19

    int x =1;

    if(e==15) e =0;
    if(s==28) s = 0;
    if(m==19) m =0;


    for (int i = 1; i <= 15*28*19; ++i) {

        if(i%15==e &&  i%28==s && i%19==m){
            x = i;
            break;
        }
    }

    cout << x;

}
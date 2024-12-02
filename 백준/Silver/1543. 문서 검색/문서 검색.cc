//
// Created by dasoya on 12/2/24.
//

#include "bits/stdc++.h"

using namespace std;

int main(){

    string s, sep;

    getline(cin,s);
    getline(cin,sep);

    int ans = 0;
    int pos = 0;

    while(pos < s.size()){

        int nxt = s.find(sep,pos);
        if(nxt == -1){
            nxt = s.size();
        }
        else{//if(nxt - pos > 0)
            ans++;
        }

        pos = nxt + sep.size();
    }

    cout << ans;
}
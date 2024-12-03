//
// Created by dasoya on 12/3/24.
//

#include "bits/stdc++.h"

using namespace std;

const string arr[8] = {"c=","c-","dz=","d-","lj","nj","s=","z="};

int main(){
    
    cin.tie(0);
    ios::sync_with_stdio(0);

    string s;

    cin >> s;

    int ans = s.size();

    for(int i = 0; i < 8 ; i++) {
        int pos = 0;
        while (pos < s.size()) {
            int nxt = s.find(arr[i],pos);
            if(nxt == -1) break;
            ans--;
            pos =  nxt + arr[i].size();
        }
    }

    cout << ans;
}
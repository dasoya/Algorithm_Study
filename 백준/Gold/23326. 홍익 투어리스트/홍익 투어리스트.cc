//
// Created by dasoya on 9/22/24.
//


#include "bits/stdc++.h"

using namespace std;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(0);
    int n,q;
    cin >> n >> q;
    set<int> s;

    int temp;
    for(int i = 1; i<=n; i++){
        cin >> temp;

        if(temp) s.insert(i);
    }

    int idx = 1;
    //1 다음 N
    while(q--){

        cin >> temp;

        if(temp == 1){
            cin >> temp;
            if(s.find(temp) == s.end()) s.insert(temp);
            else s.erase(temp);
        }
        else if (temp == 2){
            cin >> temp;
            idx += temp;
            idx %= n;
            if(idx==0) idx = n;

        }
        else{

            if(s.empty()) {
                cout<< -1 <<"\n";
                continue;
            }

            auto it = s.lower_bound(idx);
            int distance = 0;
            if(it == s.end()){
                it = s.begin();
                distance = n - idx + *it;
            }else {
                distance = *it - idx;
            }

            cout << distance << "\n";
        }
    }
}
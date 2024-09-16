//
// Created by dasoya on 9/16/24.
//


#include "bits/stdc++.h"

using namespace std;



int main(){

    cin.tie(0);
    ios::sync_with_stdio(0);

    int t = 0;

    cin >> t;

    while(t--){

        int n;
        cin >> n;

        multiset<int> s;
        while(n--){
            char pt;
            int num;
            cin >> pt >> num;

            if(pt =='I'){
                s.insert(num);
            }
            else if(pt =='D') {

                if(s.empty()) continue;

                if(num == -1) s.erase(s.begin());
                else if(num == 1) s.erase(prev(s.end()));

            }
        }

        if(s.empty()) cout << "EMPTY"<<"\n";
        else cout << *prev(s.end())  <<" "<<*s.begin()<<"\n";
    }

}
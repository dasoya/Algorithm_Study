//
// Created by dasoya on 29.09.23.
//
#include "bits/stdc++.h"
#include <iostream>
#include <sstream>

using namespace std;

int main(){

    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    while(t--){
        string p, x;
        cin >> p;

        int n;
        cin >> n ;
        cin >> x;
        deque<int> DQ;

        istringstream  ss1(x.substr(1,x.size()-2));
        string num;

        while(getline(ss1,num,',')) DQ.push_back(stoi(num));

        bool dir = true;
        bool err = false;
        for (int i = 0; i < p.length(); ++i) {
            if(p[i]=='R'){
                dir = !dir;
            } else if(p[i]=='D'){
                if(DQ.empty())
                    {
                    cout << "error" << "\n";
                    err = true;
                    break;
                    }

                if(dir){
                    DQ.pop_front();
                } else DQ.pop_back();
            }
        }
        if(!err) {
            cout << "[";

            for (int i = 0; i < DQ.size(); ++i) {
                if(dir)
                    cout << DQ[i];
                else cout << DQ[DQ.size()-i-1];
                if(i != DQ.size()-1)
                    cout << ",";
            }
            cout << "]" << "\n";
        }

    }
}

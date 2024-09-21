//
// Created by dasoya on 9/21/24.
//

#include "bits/stdc++.h"

using namespace std;

set<int> probByLevel[102];
int probLevel[100'002];

int main(){

    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,p,l,q,maxl=0,minl=102;

    cin >> n;
    while(n--){
        cin >> p >> l;
        probByLevel[l].insert(p);
        probLevel[p] =l;
        maxl = max(maxl,l);
        minl = min(minl,l);
    }

    cin >> q;

    string query;
    int x;
    while(q--){

        cin >> query;

        if(query == "recommend"){
            cin >> x;

            if(x==1) {

                cout << *prev(probByLevel[maxl].end()) <<"\n";
            }else{

                cout <<  *probByLevel[minl].begin() <<"\n";
            }

        }
        else if(query == "add"){

            cin >> p >> l;

            probByLevel[l].insert(p);
            probLevel[p] = l;
            maxl = max(maxl,l);
            minl = min(minl,l);
        }
        else {
            cin >> p; // 문제 번호
            int l = probLevel[p];
            probByLevel[l].erase(p);
            if(maxl==l){
                for (int i = maxl; i > 0 ; --i) {
                    if(probByLevel[i].empty()) continue;
                    maxl = i;
                    break;
                }
            }

            if(minl==l){
                for (int i = minl; i <101 ; ++i) {
                    if(probByLevel[i].empty()) continue;
                    minl = i;
                    break;
                }
            }
        }



    }

}


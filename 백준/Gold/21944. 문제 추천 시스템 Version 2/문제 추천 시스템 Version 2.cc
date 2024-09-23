//
// Created by dasoya on 9/23/24.
//


#include "bits/stdc++.h"

using namespace std;

int n,m;

int plv[100005]; //문제의 난이도
int pgr[100005]; //문제의 종류
set<int> pg[103][103]; //G에 해당하는 Probelm이 표시됨
set<int> lp[103];// 몇 난이도인 문제


int main(){

    cin >> n ;
    int p,l,g;

    while(n--){
        cin >> p >> l >> g;
        plv[p] = l;
        pg[g][l].insert(p);
        pgr[p] = g;
        lp[l].insert(p);
    }

    string cmd;
    int x;

    cin >> m;
    while(m--){

        cin >> cmd;
        if(cmd == "recommend"){
            cin >> g >> x;
            if(x == 1){
                for(int i = 100; i >0; i--){
                    if(pg[g][i].empty()) continue;
                    cout << *prev(pg[g][i].end()) << "\n";
                    break;
                }
            }

            if(x == -1){
                for(int i = 1; i <= 100; i++){
                    if(pg[g][i].empty()) continue;
                    cout << *pg[g][i].begin() << "\n";
                    break;
                }
            }
        } else if(cmd == "recommend2"){
            cin >> x;
            if(x == 1){
                for(int i = 100; i > 0; i--){
                    if(lp[i].empty()) continue;
                    cout << *prev(lp[i].end()) << "\n";
                    break;
                }
            }

            if(x == -1){
                for(int i = 0; i <= 100; i++){
                    if(lp[i].empty()) continue;
                    cout << *lp[i].begin() << "\n";
                    break;
                }
            }
        }
        else if(cmd == "recommend3"){
            cin >> x >> l;
            bool flag = false;
            if(x == 1){
                for(int i = l; i <= 100; i++){
                    if(lp[i].empty()) continue;
                    cout << *lp[i].begin() << "\n";
                    flag = true;
                    break;
                }
            }

            if(x == -1){
                for(int i = l-1 ; i > 0; i--){
                    if(lp[i].empty()) continue;
                    cout << *prev(lp[i].end()) << "\n";
                    flag = true;
                    break;
                }
            }

            if(!flag) cout << -1 << "\n";
        }else if(cmd == "add"){

            cin >> p >> l >> g;
            plv[p] = l;
            pg[g][l].insert(p);
            pgr[p] = g;
            lp[l].insert(p);
        }
        else {
            cin >> p;
            lp[plv[p]].erase(p);
            pg[pgr[p]][plv[p]].erase(p);
        }


    }

}


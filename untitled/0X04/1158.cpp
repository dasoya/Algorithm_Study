//
// Created by dasoya on 20.09.23.
//

#include "bits/stdc++.h"

using namespace std;

int main(){

    list<int> a = {};
    int n, k;
    cin >> n >>k;
    for (int i = 0; i < n; ++i) {
        a.push_back(i+1);
    }

    cout << "<";

     auto t = a.begin();
     bool init = false;
     while(!a.empty()){

         for (int i = 0; i < k-1; ++i) {

//if(!init&&t==a.begin()){ init = true; continue;}

             if(t!=a.end()) t++;

             if(t==a.end()) {
                 t = a.begin();
             }
         }

         if(!init) { init = true;} else cout <<" ";
         cout << *t ;
         t= a.erase(t);
         if(t==a.end()) {
             t = a.begin();
         }
         if (!a.empty())
             cout << ",";
     }
     cout << ">";

}
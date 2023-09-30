//
// Created by dasoya on 29.09.23.
//

#include <bits/stdc++.h>

using namespace std;


int result;
deque<int> DQ;

void fun2(){
    if(!DQ.empty()){
        DQ.push_back(DQ.front());
        DQ.pop_front();
        result++;
    }
}

void fun3(){
    if(!DQ.empty()){
        DQ.push_front(DQ.back());
        DQ.pop_back();
        result++;
    }
}

int find_idx(int k){

    for (int i = 0; i < DQ.size(); ++i) {
        if(DQ[i] == k)
            return i;
    }
}

int main(){

    int n,m,k;
    cin >> n >> m;
    vector<int> v;
    v.assign(0,n);


    for (int i = 1; i <= n; ++i) {
        DQ.push_back(i);
    }

    for (int i = 0; i < m; ++i) {
        cin >> k ;

        while(k!=DQ.front()){

           if(find_idx(k) <= DQ.size()/2){
               fun2();
           }
           else fun3();
        }

        DQ.pop_front();
    }

    cout << result;
}


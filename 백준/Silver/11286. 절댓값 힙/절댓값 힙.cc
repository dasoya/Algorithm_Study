//
// Created by dasoya on 10/2/24.
//

#include "bits/stdc++.h"

using namespace std;


class cmp {

public:
    bool operator() (int a,int b){

        if( abs(a) == abs(b)) return a > b; //a > 0 && b < 0;

        return  abs(a) > abs(b);

    }
};



int main(){

    int n;
    cin >> n;

    priority_queue<int,vector<int>,cmp> q;
    int x;

    while(n--){

        cin >> x;

        if(x==0){
            if(q.empty())     cout  << "0\n";
            else
            {
                cout << q.top() << "\n";
                q.pop();
            }
        }else q.push(x);
    }

}
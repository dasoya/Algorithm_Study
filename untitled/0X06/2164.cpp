//
// Created by dasoya on 26.09.23.
//
#include <bits/stdc++.h>

using namespace std;

int main(void){

    int n;

    queue<int> q;
    cin>>n;

    for (int i = 1; i <= n; ++i) {
        q.push(i);
    }

    int k=0;
    while(q.size()!=1){
        if(k==0)  q.pop();
        else {q.push(q.front()); q.pop();}

        k++;
        k%=2;
    }

    cout << q.front();

}
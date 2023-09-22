//
// Created by dasoya on 22.09.23.
//

#include "bits/stdc++.h"

using namespace std;

int main(){

    int n ;
    cin >> n;

    vector<int> v, result;
    v.assign(n,0);


    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    for (int i = 0; i < n; ++i) {
        stack<int> st;
        for (int j = 0; j < i; ++j) {
            st.push(v[j]);
        }
        int k = 0;
        while(1){
            if(st.top() >= v[i]){

                cout << i-k<<" ";
                break;
            }
            k++;
            st.pop();

            if(st.empty())
                cout << 0 <<" ";
        }
    }
    

}
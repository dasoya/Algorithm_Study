//
// Created by dasoya on 22.09.23.
//
#include "bits/stdc++.h"

using namespace std;

int main(){

    int n ;
    cin >>n ;
    vector<int> v;
    v.assign(n,0);

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    stack<int> st;
    int k = 0;
    vector<char> result;

    for (int i = 1; i < n+1;   i++) {


        result.push_back('+');
        st.push(i);

        while(!st.empty()&&v[k]==st.top())
        {
            st.pop();
            result.push_back('-');
            k++;
        }

    }

    if(k == n){
    for(auto i :result){
        cout << i<< "\n";
    }}
    else cout << "NO";

}
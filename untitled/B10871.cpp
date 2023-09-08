//
// Created by dasoya on 08.09.23.
//

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x;
    cin >> n >> x;

    vector<int> vec;


    while(n--){
        int temp;
        cin>> temp;
        if(temp < x)
         vec.push_back(temp);
    }

    for(int &i: vec){
        cout << i << " ";
    }
}

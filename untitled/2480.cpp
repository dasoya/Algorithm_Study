//
// Created by dasoya on 11.09.23.
//

#include "bits/stdc++.h"

using namespace std;

int main(){

    int a[7] = {0,};
    int max_index = 0;
    for (int i = 0; i < 3; ++i) {
        int temp;
        cin >> temp;
        if(temp > max_index)
            max_index = temp;
        a[temp]+=1;

    }

    int index = max_element(begin(a),end(a)) - begin(a);


    if(a[index] == 3) cout << 10000 + index*1000;
    if(a[index] == 2) cout << 1000+ index*100;
    if(a[index] == 1) cout << max_index*100;


}
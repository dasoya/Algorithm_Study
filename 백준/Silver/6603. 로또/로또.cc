

//
// Created by dasoya on 3/4/24.
//

#include "bits/stdc++.h"

using namespace std;
int arr[13];
int k ;

int main(){

    while (true){

        cin >> k;

        if(k==0)
            break;

        int combi[13];

        for (int i = 0; i < k; ++i) {
            cin >> arr[i];
            combi[i] = i < 6 ? 0: 1; // true일 때 0인게 중요.
        }



        do{


            for (int i = 0; i < k; ++i) {

                if(combi[i] == 0)
                   cout << arr[i] <<" ";
            }
            cout << "\n";
        }
        while(next_permutation(combi,combi+k));
        cout << "\n";

    }
}
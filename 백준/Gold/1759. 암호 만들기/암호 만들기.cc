//
// Created by dasoya on 3/5/24.
//

//
// Created by dasoya on 3/4/24.
//

#include "bits/stdc++.h"

using namespace std;
char arr[16];
int l, c;

int main(){



        cin >> l >> c;

        int combi[16];

        for (int i = 0; i < c; ++i) {
            cin >> arr[i];
            combi[i] = i < l ? 0: 1; // true일 때 0인게 중요.
        }

        sort(arr,arr+c);


        do{

            string ans = "";
            bool flag = false;
            int cnt = l;
            for (int i = 0; i < c; ++i) {

                if(combi[i] == 0) {
                    ans += arr[i];

                    if(arr[i] == 'a' || arr[i] == 'e' ||arr[i] == 'i'||arr[i] == 'o'||arr[i] == 'u'){
                        flag = true;
                        cnt--;
                    }

                }

            }


            if(flag && cnt >= 2) {
                cout << ans;
                cout << "\n";
            }

        }
        while(next_permutation(combi,combi+c));
        cout << "\n";

    }

//
// Created by dasoya on 3/22/24.
//

#include "bits/stdc++.h"

using namespace std;

char wheel[26] ;
bool alphabet[26];

int main(void){

    int n,k;

    cin >> n >> k;

    int index = 0;
    int s;
    char c;

    fill(wheel,wheel+n,'?');

    for (int i = 0; i < k; ++i) {
        cin >> s >> c;
        index += s;
        index %= n;

        //같은 바퀴가 나오는 경우 넘겨줌
        if (wheel[index] == c) {
            continue;
        }

       if(wheel[index] != '?') {
           cout << "!";
           return 0;
       }

        if(alphabet[c-'A']){
            cout << "!";
            return 0;
        }
       wheel[index] = c;
       alphabet[c-'A'] = true;

    }


    for (int i = index; ; ) {

        cout << wheel[i];

        i--;
        if(i<0) i = n-1;

        if(i==index) break;

    }

}
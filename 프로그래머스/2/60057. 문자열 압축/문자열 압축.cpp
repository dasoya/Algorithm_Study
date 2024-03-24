//
// Created by dasoya on 3/24/24.
//
#include <string>
#include <vector>
#include "iostream"
using namespace std;

int compression(string s,int n){

    string cs = "";
    string pre = "";
    int count = 0;

    for(int i = 0 ; i < s.length(); ){

        string cur = "";
        for(int j = i; j < i+n ; j++){

            if(j==s.length()) break;
            cur += s[j];

        }


        if(pre == "") {pre = cur; count++; }
        else if(pre == cur) {
            count++;

        }
        else{

            if(count > 1){

                cs += to_string(count);

            }

            cs += pre;
            pre = cur;
            count = 1;
        }


        i += n;

    }

    if(count > 1){

        cs += to_string(count);

    }

    cs += pre;

    return cs.length();

}

int solution(string s) {
    int answer = 1001;

    for(int i = 1; i <= s.length() ;i++){

        int k = compression(s,i);
        if(answer > k) answer = k;
    }

    return answer;
}



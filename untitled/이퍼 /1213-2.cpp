//
// Created by dasoya on 3/24/24.
//
#include "bits/stdc++.h"

using namespace std;

const int SIZE = 26;


vector<int> countAlphabet(string text){

    vector<int> count(SIZE,0);

    for (int i = 0; i < text.size(); ++i) {

        count[text[i]-'A']++;


    }

    return count;
}

string makePanl(vector<int>&count){

    string part1 = "", part2 = "", part3 = "";

    for (int i = 0; i < SIZE; ++i) {
        if(count[i] %2 ==1){
            if(part2.size() == 1) return "I'm Sorry Hansoo";

            part2 = (char)(i+'A');
        }

        for (int j = 0; j < count[i]/2; ++j) {
            part1 += (char)(i+'A');
            part3 = (char)(i+'A') + part3;
        }


    }

    return part1+part2+part3;

}

string solution(string str) {
    // 연산 + 출력
    vector<int> count = countAlphabet(str);
    return makePanl(count);
}

int main() {
    string input;
    cin >> input;

    cout << solution(input);

    return 0;
}
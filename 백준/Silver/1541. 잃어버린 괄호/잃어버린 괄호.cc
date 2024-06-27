//
// Created by dasoya on 6/27/24.
//

#include "bits/stdc++.h"

using namespace std;

int main(){

    cin.tie();

    string input;
    cin >> input;

    int s, e = 0;
    string operand = "";

    int res = 0;
    int minRes = 0;
    bool flag = false; // false면 + true -를 의미

    for (int i = 0; i < input.length(); ++i) {

        if(input[i] == '+')
        {

            if(flag){
                minRes += stoi(operand);
            }
            else{
                res  += stoi(operand);
            }

            operand= "";

        }
        else if (input[i] == '-'){

            if(flag){
                minRes += stoi(operand);
            }
            else{
                res  += stoi(operand);
            }

            flag = true;
            operand= "";
        }
        else
        {
            operand += input[i];
        }

    }

    if(flag){
        minRes += stoi(operand);
    }
    else{
        res  += stoi(operand);
    }


    cout << res - minRes;




}

//55-(50+40)
//1 - 2 -2
//덧셈은 더하고 - 붙일 수 있는 뭉텅이는 부치고.
//최소 - 이후 쁠러스가 나오면 다 -로 처리.
//
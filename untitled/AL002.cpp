//
// Created by dasoya on 06.09.23.
//

#include <bits/stdc++.h>
//#include "iostream"
using namespace std;

int func2(int arr[], int N){

    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j < N; ++j) {
            if(arr[i]+arr[j]==100 )
                return 1;
        }
    }

    return 0;
}


int func3(int n){

    for (int i = 1; i < n; ++i) {
        int temp = i*i;
        if(n == temp)
            return 1;

        if(n<temp)
            return 0;
    }



}

int func4(int n){
    int temp = 1;

    for (int i = 2; i <= n; i=i*2) {
        if(n<i)
            return temp;
        else if (n==i)
            return n;

        temp = i;
    }
    return temp;
}

int main(){
    int arr[3] = {1,52,48};

//    cout << func2(arr,3);
//
//    cout << func3(9);
//    cout << func3(693953651);
//    cout << func3(756580036);

    cout << func4(5) <<'\n';
    cout << func4(97615282)<<'\n';
    cout << func4(1024);

}
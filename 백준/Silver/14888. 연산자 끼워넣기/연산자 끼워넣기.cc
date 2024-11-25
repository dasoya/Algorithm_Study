//
// Created by dasoya on 11/25/24.
//


#include "bits/stdc++.h"

using namespace std;

int n;
int mxa = INT_MIN, mia=INT_MAX;
bool visited[15];
int arr[12];
vector<int> moduler;

int calc(int a,int b,int m){

    if(m==0)
        return a+b;
    if(m==1)
        return a-b;
    if(m==2)
        return a*b;
    else return a/b;
}

void back(int idx,int num){

    if(idx==n){
        mxa = max(mxa,num);
        mia = min(mia,num);
        return;
    }

    for(int i = 0; i < n-1;i++){

        if(visited[i]) continue;

        visited[i] = 1;
        int val = calc(num,arr[idx],moduler[i]);
        back(idx+1,val);
        visited[i] = 0;

    }
}


int main(){


    int c[4];//덧 뺄 곱 나눗셈

    cin >> n;



    for(int i = 0; i< n;i++)
        cin >> arr[i];

    cin >> c[0] >> c[1]>> c[2] >> c[3];




    for(int i = 0; i < 4;i++){
        for(int j = 0; j < c[i] ;j++) {
            moduler.push_back(i);
        }
    }

    for(int k = 0; k < moduler.size();k++){
        visited[k] = 1;
        back(2,calc(arr[0],arr[1],moduler[k]));
        visited[k] = 0;
    }

    cout << mxa << "\n" << mia;
}
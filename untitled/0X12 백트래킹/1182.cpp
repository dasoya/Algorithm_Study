//
// Created by dasoya on 2/11/24.
//
#include "bits/stdc++.h"

using namespace std;

int n,s;
int arr[21];
int ans = 0;

//백트래킹 k로 for문을 하나 순회할수 있다는것..?
void func(int k,int tot){

    if(k==n){
        if(tot==s) {
            ans++;

        }
        return;
    }

    func(k+1,tot);
    func(k+1,tot+arr[k]);
}
int main(void){

    cin.tie(0);

    cin >> n >> s;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    func(0,0);

    if(s==0) ans--;

    cout << ans;

}
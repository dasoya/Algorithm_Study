//
// Created by dasoya on 8/30/24.
//

#include "bits/stdc++.h"

using namespace std;

int main(){


    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int arr[100005];

    cin >> n;

    for (int i = 0; i < n; ++i) {

        int temp = 0;
        cin >> arr[i];


    }

    long long ans_sum = 50000000000;
    pair<long long,long long> ans = {0,0};

    for (int i = 0; i < n; ++i) {

        //idx-1 , idx ,idx+1
        long long idx = lower_bound(arr,arr+n,-arr[i]) - arr;

        if(idx > 0 && abs(arr[idx-1]+arr[i]) < abs(ans_sum) && i != idx-1)
        {
            ans.first = arr[idx-1];
            ans.second = arr[i];
            ans_sum = ans.first+ans.second;
        }

        if(idx < n && abs(arr[idx]+arr[i]) < abs(ans_sum)&& i != idx){

            ans.first = arr[i];
            ans.second = arr[idx];
            ans_sum = ans.first+ans.second;
        }

        if(idx+1< n && abs(arr[idx+1]+arr[idx]) < abs(ans_sum) && i != idx+1){

            ans.first = arr[idx+1];
            ans.second = arr[i];
            ans_sum = ans.first+ans.second;
        }

    }
    if(ans.first>ans.second) swap(ans.first,ans.second);

    cout << ans.first <<" "<< ans.second ;
}

//vector<int> v(n,0);
//v[0] = 1;
//v[1] = 1;
//
//do{

//long long sum = 0;
//pair<int,int> p;
//for (int i = 0; i < n; ++i) {
//
//if(v[i]==1)
//{
//sum += arr[i];
//if(p.first == 0) p.first = arr[i];
//else{ p.second = arr[i]; break;}
//}
//
//}
//
//if(sum < 0) sum*=-1;
//ans_sum = min(sum,ans_sum);
//if(sum == ans_sum) ans = p;
//
//} while(prev_permutation(v.begin(),v.end())); // 조합을 구할땐 1을 맨 끝에 두거나, prev_해야함.
//
// Created by dasoya on 10/3/24.
//


#include "bits/stdc++.h"

using namespace std;

int main(){

    int n,x;
    cin >> n;
    int sz = 0,mid = 0;
    cin.tie(0);
    ios::sync_with_stdio(0);

    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<>> minHeap;

    while(n--){
        cin >> x;
        sz++;

        if(maxHeap.empty()) {
            mid = x;
            maxHeap.push(x);
            cout << mid <<"\n";
            continue;
        }

        if(maxHeap.size() <= minHeap.size()){
            //max heap에 들어가야 하는데
            if(!minHeap.empty() && minHeap.top() < x){
               int k =  minHeap.top(); minHeap.pop();
               maxHeap.push(k);
               minHeap.push(x);
            }
            else{
                maxHeap.push(x);
            }
        }
        else {
            if(!maxHeap.empty() && maxHeap.top() > x){
                int k =  maxHeap.top(); maxHeap.pop();
                minHeap.push(k);
                maxHeap.push(x);
            }
            else{
                minHeap.push(x);
            }
        }

        mid = maxHeap.top();
        cout << mid <<"\n";
    }
}


#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K) {
    long long answer = 0;
    
    //최소 힙
    priority_queue<long long,vector<long long>,greater<>> pq;
    
    for(auto a : scoville){
        
        pq.push(a);
    }
    bool flag = false;
    
    while(true){
        long long cur =  pq.top(); pq.pop();
        
        if(cur >= K){
            break;
        }
        
        if(pq.size() < 1){
            flag = true;
            break;
        }
        
        long long second = pq.top(); pq.pop();
    
        answer++;
        pq.push(cur+second*2);
    }
    
    if(flag) answer = -1;
    
    return answer;
}
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> priorities, int location) {
    int idx = 0;
    
    queue<int> arr;
    priority_queue<int> pq;
    
    for(int i = 0 ; i < priorities.size();i++){
        arr.push(i);
        pq.push(priorities[i]);
    }
    
    while(!arr.empty()){
        
        //max를 알아야함.
        int cur_top = pq.top();
        
        int cur = arr.front();
        
        if(cur_top == priorities[cur]){
            pq.pop();
            arr.pop();
            idx++;
            
            if(cur==location)
                break;
            
        }else{
            arr.pop();
            arr.push(cur);
            
        }
        
        
        //location의 순번을 알면 
    }
    
    
    

    
    return idx;
}
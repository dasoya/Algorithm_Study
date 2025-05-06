#include <string>
#include <vector>
#include <iostream>
#include "bits/stdc++.h"
using namespace std;

bool rExist[35];


int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    //lost를 기준으로 lost 양 옆에서 왼쪽에 있는
    //1 2 3 4 5
    //  x   x
    sort(lost.begin(),lost.end());
    for(int r : reserve){
        rExist[r-1] = true;
    }
    
   for (int i = 0; i < lost.size(); ) {
    int l = lost[i];
    if (rExist[l - 1]) {
        rExist[l - 1] = 0;
        lost.erase(lost.begin() + i); // 인덱스로 안전하게 삭제
    } else {
        ++i; // 지우지 않을 때만 인덱스 증가
    }
}
    
    int k = 0; //lost의 인덱스
    for(int i = 0; i < n;i++){
        
        if(k<lost.size()&&lost[k]-1==i){
            
            if(i-1 >=0 && rExist[i-1]){
                
                rExist[i-1] = 0;
                answer++;
                      cout <<"l";
            }
            else if( i+1 <n && rExist[i+1]){
                rExist[i+1] = 0;
                answer++;
                cout <<"r";
            }
            
            k++;
            
        }else{
            answer++;
        }
        
    }
    
    
    return answer;
}
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    
    int cur = num/w + 1;
    if(num%w==0) cur-= 1;
    int curIdx;
    //cur는 꺼내야되는 상자가 몇층인지
    if(cur%2 ==1) {
        curIdx = num%w;
        if(curIdx == 0) curIdx = w;
    }else{
          curIdx = w-num%w;
        if(num%w == 0) curIdx = 1;
    }
    
    
    int total =  n/w ;
    if(n%w==0) total-= 1;
    
     cout << total << " " << cur <<" << \n";
    int totalLast = n%w;
    if(totalLast == 0) totalLast = w;
    
    if((total+1)%2 == 1){
       
        cout << totalLast << " " << curIdx;
        
        if(totalLast>=curIdx){
            return total - cur +1 +1;
        }
        return total - cur+1;
        
    }else{
        
        
        totalLast = w-n%w;
        if(n%w == 0) totalLast = 1;
        
        cout << totalLast << " " << curIdx;
        if(totalLast <= curIdx){
            return total - cur +1+1;
        }
        return total - cur+1;
        
        
    }
    

}
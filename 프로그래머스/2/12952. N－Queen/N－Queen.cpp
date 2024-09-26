#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<bool> col(13,false);
vector<bool> dig1(2*12,false); //우상향 col + row 
vector<bool> dig2(2*12,false); //우하향 

int answer = 0;

void backtracking(int row,int n){
    
    if(row == n) {
        answer++;
        return;
    }
    
   for(int i = 0;i < n; i++){
        
        if(col[i] || dig1[i+row] || dig2[i-row+n-1]) continue;
        
        col[i] = 1;
        dig1[i+row] = 1;
        dig2[i-row+n-1] = 1;
        
        backtracking(row+1,n);
        
        col[i] = 0;
        dig1[i+row] = 0;
        dig2[i-row+n-1] = 0;
        
    }
    
    return;
}


int solution(int n) {
  

    int row = 0;
    
    backtracking(0,n);
    
    return answer;
}
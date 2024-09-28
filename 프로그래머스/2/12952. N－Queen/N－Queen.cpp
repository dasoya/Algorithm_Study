#include <string>
#include <vector>

using namespace std;

vector<int> col(14,0);
vector<int> dig1(25,0);//우상향
vector<int> dig2(25,0);//우 하향


int back(int row,int n){
    
    if(row==n){
        return 1;
    }
    
    int ans = 0; 
    for(int i = 0; i < n; i++){
        
        if(col[i] || dig1[i+row] || dig2[i-row+n]) continue;
        
        col[i] = 1;
        dig1[i+row] = 1;
        dig2[i-row+n] = 1;
        
        ans += back(row+1,n);
        
        col[i] = 0;
        dig1[i+row] = 0;
        dig2[i-row+n] = 0;
        
        
    }
    
    return ans;
    
}

int solution(int n) {
    int answer = 0;
    
    answer = back(0,n);
    return answer;
}
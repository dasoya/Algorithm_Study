#include <string>
#include <vector>
#include <stack>

using namespace std;

bool check[100001];


//1 2 3 2 3
//4 3 1 1 0
//stack
//1 2 
// 

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(),0);
    
    stack<pair<int,int>> s; //가격, 산 기간
    s.push({prices[0],0});
    
    for(int i = 1 ; i < prices.size(); i++){  
        pair<int,int>  cur = s.top();
        
       if(s.empty() || cur.first <= prices[i]){
           s.push({prices[i],i});
           continue;
       }
    
       while(!s.empty()){
           cur = s.top();
           if(cur.first > prices[i]){
               answer[cur.second] = i-cur.second;
               s.pop(); 
           }
           else{
               break;
           }
       } 
        
       s.push({prices[i],i});
        
    }
    
      while(!s.empty()){
           pair<int,int> cur = s.top();
       
            answer[cur.second] = prices.size()-1 -cur.second;
            s.pop(); 
           
         
       } 
    
    return answer;
}
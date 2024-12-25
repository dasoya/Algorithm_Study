#include <string>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

int n;
int maxUser=0, maxAmount=0;
vector<vector<int>> emoticonsFee;

int getDiscountFee(int fee,int percent){
    
    cout <<  (int)((1-0.01*percent)*fee);
   // return ((1- percent*0.01)*fee);// (fee-fee*percent/100); //85점
   // return (int)((1- percent*0.01)*fee); // 85점
   // return (int)(1- percent*0.01)*fee; //0점
   // return (1-percent/100)*fee;//0점
    return fee - percent*fee*0.01;
    
}

void solve(vector<vector<int>> users,int cnt, vector<int> q){
    if(cnt==n){
        
        int purchasedUser = 0, totalAmount = 0;  
        
        for(auto user : users){
            int userAmount = 0;
            
            for(int i = 0 ; i < n ; i++){
                if(user[0] <= q[i])
                    userAmount += emoticonsFee[i][q[i]/10 -1];
            }
            
            if(userAmount >= user[1]){
                purchasedUser++;
            }
            else{
                totalAmount += userAmount;
            }
        
        }
        
        
        if(maxUser < purchasedUser){
            maxUser = purchasedUser;
            maxAmount = totalAmount;
        }else if(maxUser == purchasedUser){ 
               if(maxAmount < totalAmount){
                    maxUser = purchasedUser;
                    maxAmount = totalAmount;
               }
        }
        
        return;
    }
        
    for(int per = 10 ; per <= 40; per+=10){
    
        q.push_back(per);
        solve(users,cnt+1,q);
        q.erase(q.end()-1);
    }    
    
}


vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer(2,0);
    //가입자 수를 최대로 증가 시켜야함.  -> 할인율이 높으면 구매 비용이 싸져서 안삼. 너무 낮으면 할인을 안해서 안삼
    //매출 증가
    
    // 답은 구매자랑 매출
    //이모티콘마다 비율 존재 -> 10 20 30 40
    //유저마다  서비스 이용 여부 
    //2^14의 이모티콘 할인율 *100
    
    for(auto e : emoticons){  
       vector<int> temp;
      for(int per = 10 ; per<= 40; per+=10){
        temp.emplace_back(getDiscountFee(e,per));
      }
       emoticonsFee.push_back(temp);
    }
    
    n = emoticons.size();
    
    vector<int> q;
    solve(users,0,q);
    
    
    answer[0] = maxUser;
    answer[1] = maxAmount;

    
    return answer;
}
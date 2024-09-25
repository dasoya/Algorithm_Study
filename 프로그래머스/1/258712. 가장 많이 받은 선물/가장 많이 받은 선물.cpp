#include <string>
#include <vector>
#include <map>
#include <bits/stdc++.h>

using namespace std;
map<string,int> giftN; //선물지수
int mat[52][52];
int nextMonth[52];
map<string,int> friendIndex;
int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    int k =0;
    for(auto f:friends){
        friendIndex[f] = k;
        k++;
    
    }
    for(auto s:gifts){
        string giver, receiver;
        
        bool flag = false;
        for(auto c:s){
            
            if(c == ' ') {
                flag = true;
                continue;
            }
            if(!flag)  giver += c;
            else  receiver += c;
            
        }
        
       int gi = friendIndex[giver];
       int ri = friendIndex[receiver];
        
        if(gi!=-1&&ri != -1)
            mat[gi][ri] +=1;
        else cout << "index error";
        
        giftN[giver]++;
        giftN[receiver]--;
    }
    
    for(int i =0 ;i< friends.size() ;i++){
        for(int j = i+1; j < friends.size() ; j++){
        
            if(mat[i][j] > mat[j][i]){
                 nextMonth[i]++;
            }else if (mat[i][j] <mat[j][i]){
                 nextMonth[j]++;
            }else{
                
                if(giftN[friends[i]] > giftN[friends[j]]){
                    nextMonth[i]++;
                }else if (giftN[friends[i]] < giftN[friends[j]]){
                    nextMonth[j]++;
                }
                
            }
            
          
        } 
    }
    
    answer = *max_element(nextMonth,nextMonth+friends.size());
    return answer;
}
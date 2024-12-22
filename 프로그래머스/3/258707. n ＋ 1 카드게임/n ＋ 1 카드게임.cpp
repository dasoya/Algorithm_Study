#include <string>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

int maxCnt = 0;
int n;

bool match(set<int>& a,set<int>& b){
    
    for(auto ai : a){
        
        int target = n+1 - ai;
        auto it = b.find(target);
        
        if(it != b.end()){
            
            b.erase(*it);
            a.erase(ai);
            return true;
        }
        
    }
    
    return false;
}




int solution(int coin, vector<int> cards) {
    int answer = 1;
    n = cards.size();
    
    int pos = n/3;
    set<int> hands,draws; // 손에 있는 카드 패, 가능한 카드패. 
    
    for(int i = 0 ; i < pos ; i++)
        hands.insert(cards[i]);
    
    //카드를 넣으면서 한라운드 씩 전진! 
    for(int i = pos; i < n ; i+=2){
        
        draws.insert(cards[i]);
        draws.insert(cards[i+1]);
        
        if(match(hands,hands)){
            
        }
        else if(coin >=1 && match(hands,draws)){
            coin--;
        }
        else if (coin >=2 && match(draws,draws)){
            coin -= 2; 
        }
        else 
            break;
        
        answer++;
    }
    

    return answer;
}
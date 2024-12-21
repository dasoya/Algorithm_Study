#include <string>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
int maxScore = 0;
vector<vector<int>> aList, bList;
vector<int> aCandi,bCandi;
bool visited[6];

void sumCal(int cnt,int sum,vector<int> list,bool isA,vector<vector<int>> dice){
    
    if(cnt == list.size()){
        if(isA) aCandi.push_back(sum);
        else bCandi.push_back(sum);
        
        return;
    }
    
    for(int i = 0 ; i < 6 ; i++){
       // if(visited[i]) continue;
        visited[i] = true;
        sumCal(cnt+1, sum + dice[list[cnt]][i],list,isA,dice);
        visited[i] = false;
    }
    
}

vector<int> diceCal(vector<vector<int>> dice){
    

    vector<int> ans;
    
         cout << aList[0].size() << " | ";
      
        for(int t = 0; t < aList.size();t++){
            
            for(auto c: aList[t]){
                cout << c << " ";
            }
              //aCandi를 구함. a에서 나올수 있는 합 구함. 백트래킹 
            sumCal(0,0, aList[t],true,dice);
          
            sumCal(0,0,bList[t],false,dice);

            int aScore = 0;
            
            cout << "{"<<aCandi.size()<<"," <<aCandi.size()*bCandi.size() <<"}";

            for(int i = 0; i < aCandi.size();i++){
                for(int j = 0; j < bCandi.size();j++){

                    if(aCandi[i] > bCandi[j])
                        aScore++;

                }
            }
            
            cout << " : ";
            cout << aScore << "  ";

            if(aScore > maxScore){
                maxScore = aScore;
                ans = aList[t];
                
            }
            
            aCandi.clear();
            bCandi.clear();
    }
    
    return ans;
    
    
}

vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    int n = dice.size();
    
    //nCn/2 
    // 6^(n) 중에서 a가 이긴 경우..
    // A가 승리하는 경우. 
    
 // true a false b
    bool arr[n]; 
    fill(arr,arr+n/2,false);
    fill(arr+n/2,arr+n,true);
    //42. 40 38 
    do{ 
        //이기거나 비겼을 때는 실제 스코어를 계산해야함. 

        //각 주머니에서 뽑아서 승리의 경우를 계산해야하는뎅.
        //뽑은걸 짝을 맞춰서 곱하기가 로직이 안그려짐. -- > 재귀/백트래킹을 한번 써보자.
        
        //n개의 주머니에서 하나씩 뽑아서 더한 모든 경우의수를 못구하겠음. 
        //aList, bList 정리.
        vector<int> tempA,tempB;
         for(int i = 0; i< n; i++){ 
             
            if(arr[i]) tempA.emplace_back(i);
            else tempB.emplace_back(i);
         }
        
        aList.push_back(tempA);
        bList.push_back(tempB);
        
    }while(next_permutation(arr,arr+n));
    
    
    
    answer = diceCal(dice);
    
    for(int i = 0;i < answer.size();i++){
        answer[i]++;
    }
    
    
    return answer;
}
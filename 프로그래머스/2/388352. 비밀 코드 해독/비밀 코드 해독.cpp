#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;
    
    vector<int> arr;
    
    for(int i = 0; i < 5; i++){
        arr.emplace_back(0);
    }
    for(int i = 5; i < n; i++){
        arr.emplace_back(1);
    }
    
    do{
       
        //앞의 다섯개를 뽑는다고 했을 때
        //현재 arr에서 0인게 비밀코드임
        //q[i]를 검사한 ans가 ans[i] 갯수와 같아야함

        bool flag = true;
        for(int i = 0 ; i < q.size();i++){
            int anst = 0;
            for(int j = 0; j < 5; j++){
               if(arr[q[i][j]-1] == 0){
                   anst++;
               }
            }
            if(ans[i]!=anst){
                flag = false;
                break;
            }       
        }
        
        if(flag){
            answer++;
        }
        
        
        
    }while(next_permutation(arr.begin(),arr.end()));
    
    
    return answer;
}
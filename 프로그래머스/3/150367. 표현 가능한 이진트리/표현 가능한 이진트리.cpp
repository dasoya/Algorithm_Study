#include <string>
#include <vector>
#include<bits/stdc++.h>
using namespace std;


bool check(string& n,int root,int gap){
    
    if(gap < 1){
        return true;//리프노드는 상관없이 true
    }
    
    //root/2
    char temp = '0';
    char temp2 = '0';
    
    if(root-gap-1 >= 0) 
       temp = n[root-1-gap];
    if(root+gap-1 < n.length()) 
       temp2 = n[root-1+gap];
    
    if(n[root-1] == '0' && (temp == '1'|| temp2 == '1'))
        return false;
    
    return check(n,root-gap,gap/2) && check(n,root+gap,gap/2);
    
}


int solve(long long num){
    
    //10진수를 2진수로 변환, 2로 나누면됨. 
    
    string n = "";
    
    while(num != 0){
        
        if(num % 2 == 1) n =  "1"+n;
        else n = "0" +n;
        
        num /= 2;
   
    }   //1 3 7 
        //2-1 4-1 8-1

    
    int root = 1;
    int idx = 1;
    
    while(root <= n.length()){
        root *=2;
    }
    
    int temp =  n.length();
    for(int i = temp; i < root-1; i++){
        n = "0" +n;
    }
    
    root /= 2;
    
    
   
    //cout << n << " " << root<<"\n";
    
    if(check(n,root,root/2)) return 1;
    return 0;
    
}


vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for(auto number : numbers){
        answer.push_back(solve(number));
    }
    
    return answer;
}
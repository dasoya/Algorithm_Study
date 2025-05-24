#include <string>
#include <vector>
#include "bits/stdc++.h"
using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    
    int pIndex = -1;
    
    if(pat.size() > myString.size()) return 0;
    
    for(int i = 0; i< myString.size() - pat.size() +1 ;i++)
    {
        pIndex = i;
        for(int p = 0 ; p < pat.size(); p++)
        {
            if(pat[p] >= 'A' && pat[p] <= 'Z')
            {
                pat[p] -= 'A' -'a';
            }
            
             if(myString[i+p] >= 'A' && myString[i+p] <= 'Z')
            {
               myString[i+p]-= 'A' -'a';
            }
            
            
            if(pat[p] != myString[i+p])
            {
                pIndex = -1;
            }
        }
        
        if(pIndex != -1){
            return 1;
        }
    }
    
    return answer;
}
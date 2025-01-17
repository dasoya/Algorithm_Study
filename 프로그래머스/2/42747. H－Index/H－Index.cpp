#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    std::sort(citations.begin(),citations.end());
        
    //인용 횟수는 중복이 있음.
    for(int i = 0 ; i < citations.size() ;i++){
        int h = citations.size()- i ;       
        int ci = citations[i];

        if(ci >= h && i <= h){
            answer = max(h,answer);
        }
    }
    return answer;
}
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    unordered_set<int> s;
    
    for(auto num : nums){
        s.insert(num);
    }
    
    answer = min(nums.size()/2, s.size());
    
    return answer;
}
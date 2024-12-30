#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(auto com : commands){
        
        vector<int> arr(array.begin()+com[0]-1,array.begin()+com[1]);
        
        sort(arr.begin(),arr.end());
        
        answer.push_back(arr[com[2]-1]);
    }
    return answer;
}
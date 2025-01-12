#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    int pre = -1;
    for(int i = 0 ; i< arr.size(); i++){
        
        if(arr[i]== pre) continue;
        pre = arr[i];
        answer.emplace_back(arr[i]);
        
    }

    return answer;
}
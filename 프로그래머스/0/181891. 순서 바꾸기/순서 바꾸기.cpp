#include <string>
#include <vector>
#include "bits/stdc++.h"
using namespace std;

vector<int> solution(vector<int> num_list, int n) {
    vector<int> answer;
    
    for(int i = 0 ; i< n ; i++){
      num_list.push_back(num_list[0]);
      num_list.erase(num_list.begin());
    }
    return num_list;
}
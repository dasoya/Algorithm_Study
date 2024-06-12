//
// Created by dasoya on 3/15/24.
//

#include "bits/stdc++.h"

using namespace std;

int n;
int arr[11][11];
int _visit[11];
vector<int> result;
int cost;
int min_cost = 20000000;

void func(int k){

    if(k==n){

            if(arr[result[k-1]][result[0]] == 0) return;
            cost = 0;

            for (int i = 0; i < int(result.size())-1; ++i) {
                cost  += arr[result[i]][result[i+1]];
                //cout << result[i]<<"("<< arr[result[i]][result[i+1]] <<");";
            }


            cost += arr[result[k-1]][result[0]];
            //cout << cost << ":";
            //cout << "\n";
            if(cost<=min_cost){
                min_cost = cost;
            }

        return;
    }


    for (int j = 0; j < n; ++j) {

                if(_visit[j])
                    continue;

                if(k != 0 && result[k-1] == j)
                    continue;

                if(k != 0 &&arr[result[k-1]][j] == 0) continue;

                    _visit[j] = 1;
                    result.push_back(j);
                    func(k + 1);
                    _visit[j] = 0;
                    result.pop_back();


            }
}

int main(){


    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j] ;
        }
    }

    func(0);

    cout << min_cost;

}
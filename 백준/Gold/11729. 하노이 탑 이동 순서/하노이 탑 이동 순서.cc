//
// Created by dasoya on 1/31/24.
//


#include "iostream"
#include "vector"


using namespace std;
vector<pair<int,int>> ans;

void hanoi(int a,int b, int n){

    if(n==1) {
        ans.push_back({a,b});

        return;
    }

    hanoi(a,6-a-b,n-1);

    //n번째 판을 옮겨줌
    ans.push_back({a,b});

    hanoi(6-a-b,b,n-1);

}

//1 2 3

int main(void){

    int n;
    cin >> n;

    hanoi(1,3,n);

    cout << ans.size()<< "\n";

    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i].first <<" " << ans[i].second << "\n";
    }
}
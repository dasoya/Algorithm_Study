
// 팀에서 한명씩은 출석 해야함. 팀의 개수와 체크하는 배열 필요
// 팀장의 갯수가 팀의 갯수.
// 최대 두개의 팀에 소속 가능.
// 최소 매출액을 만들어야 함. 백트래킹?
// 단순히 팀에서 최소 팀원이 최고가 아님.
#include "bits/stdc++.h"

using namespace std;

int endK = 0;
set<int> teamCount;
vector<int> attend;
int minSale = 100000;
bool check_team[300001];
pair<int,int> memb[300001];

//k는 참석하는 팀 갯수?
void func(int k, int sum,vector<int> sales){

    if(k == endK){
        if(minSale >= sum) {
            minSale = sum;
            cout << sum <<": "  ;

            for(auto i : attend){
                cout << i <<" ";
            }
            cout << "\n";

        }
        return;
    }


    for (int i = 1; i <= sales.size(); ++i) {

        int teamCount = 1;
        if(memb[i].first != 0) teamCount = 2;
        //if() continue;
        //i 번째 직원이 몇번째 팀에 있고, 그 팀의 참석 여부를 걸러야함.
        if (!check_team[memb[i].second] || (memb[i].first != 0 && !check_team[memb[i].first])){

            //i번째 직원을 attend 시킴
            attend.push_back(i);
            if(!check_team[memb[i].second] ){
                check_team[memb[i].second] = true;
                k += memb[i].second;
            }
            if(memb[i].first != 0 && !check_team[memb[i].first]) {
                check_team[memb[i].first] = true;
                k += memb[i].first;
            }

            sum += sales[i-1];
            func(k,sum,sales);

            sum-=sales[i-1];
            attend.pop_back();

            if(check_team[memb[i].second] ){
                check_team[memb[i].second] = false;
                k -= memb[i].second;
            }
            if(memb[i].first != 0 && check_team[memb[i].first]) {
                check_team[memb[i].first] = false;
                k -= memb[i].first;
            }
        }
    }

    return;

}

int solution(vector<int> sales, vector<vector<int>> links) {
    int answer = 0;

    for(auto i : links){

        teamCount.insert(i[0]);
        memb[i[0]].first = i[0]; // 자신의 팀장인 팀번호
        memb[i[1]].second = i[0]; // 자신이 팀원인 팀번호
    }

    for (auto i : teamCount) {

        endK += i;

    }

    func(0,0,sales);
    answer = minSale;

    return answer;
}

int main(){


    vector<int> sales ={10,10,1,1};
    vector<vector<int>> links = { {3, 2}, {4,3}, {1, 4}};
    cout << solution(sales,links);
}
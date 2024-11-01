//
// Created by dasoya on 10/31/24.
//

#include "bits/stdc++.h"

using namespace std;


vector<int> p(1003,-1);

int find(int x){
    if(p[x] < 0) return x;
    return  p[x] = find(p[x]);
}

bool is_diff_group(int u,int v){
    u = find(u); v = find(v);
    if(u==v) return 0; //두 그릅이 같으면 넘어가고
    if(p[u]==p[v]) p[u]--; // 다른데 그룹 넘버의 p가 같으면
    if(p[u]<p[v]) p[v] = u;
    else p[u] = v;
    return 1;
}

pair<int,int> coordinates[1005];
vector< tuple<long long, int, int> > edge;
int e = 0;

long long distance(int a, int b){

    long long dx = coordinates[a].first - coordinates[b].first;
    long long dy = coordinates[a].second - coordinates[b].second;

    return dx*dx+dy*dy;
}

int main(){
    int n,m,x,y;

    cin.tie(0);
    int cnt = 0;
    double ans = 0;

    cin >> n >> m;

    for(int i = 0; i < n;i++){
        cin >> x >> y;
        coordinates[i+1] = {x,y};
    }

    int a,b;
    while(m--){
        cin >> a >> b;
        if(is_diff_group(a,b))
            cnt++;
    }

    for(int i = 1; i <= n;i++)
        for(int j = 1; j <= n;j++){

            if(i>=j) continue;
            edge.push_back({distance(i,j),i,j});
            e++;
        }

    
    sort(edge.begin(),edge.end());

    long long cost;
    for(int i =0; i<e ; i++){

        tie(cost,a,b) =  edge[i];
        if(!is_diff_group(a,b)) continue;

        ans += sqrt(cost);
        cnt++;
        if(cnt == n-1) break;

    }

    cout << fixed; //소수점 고정
    cout.precision(2);
    cout << ans;

}
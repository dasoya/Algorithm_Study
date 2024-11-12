//
// Created by dasoya on 11/12/24.
//

#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<ll,int> pi;

int n,m,a,b;
ll c;
ll INF = INT64_MAX/2;
vector<pi> adj[100001];
ll d[100001];
ll low = 1 ,hi =0 ;

//비용, 수치심 반환
bool solve(ll lim){

    priority_queue<pi,vector<pi>,greater<>> pq;

    fill(d,d+n+1,INF);
    d[a] = 0;
    pq.push({d[a],a});

    while(!pq.empty()){
        pi cur = pq.top(); pq.pop();
        if(cur.first != d[cur.second]) continue;
        for(pi nxt : adj[cur.second]){
            if(nxt.first > lim) continue;
            if(d[nxt.second] <= d[cur.second]+nxt.first) continue;
            d[nxt.second] = d[cur.second]+nxt.first;
            pq.push({d[nxt.second],nxt.second});
        }
    }


    if(d[b] <= c) return 1;
    else return 0;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> m >> a >> b >> c;

    //내가 가진 돈 하에서 한 경로의 최댓값이 최소가 되는 경로
    while(m--){
        int u,v;
        ll w;
        cin >> u >> v >> w;
        adj[u].emplace_back(w,v);
        adj[v].emplace_back(w,u);
        hi = max(w,hi);
    }

    // 매개 변수 탐색 -> 비용을 만족하면서 최초 수치심.
    //수치심이 이분 탐색
    ll mid;
    while(low < hi){
        mid = (low+hi)/2;
        if(solve(mid)){
            hi = mid;
        } else{
            low = mid+1; // 여기서 mid +1 을 하는 이유는 일단 무한 루프에 안 빠지기 위해서.
            //low 와 hi는 꼭 mid일 필요 없음. 근데 mid값을 최정적으로 결정시켜주기 위해서 좀더 타이트하게 미드가 될 수 있는 값을 결정해주는데
            //이미 mid는 solve를 해봄. 그니까 low 는 mid +1 이 되도 괜찮고 high는 mid -1 이되도 괜찮음.
        }
    }

    if(!solve(low)) cout << -1;
    else cout << low;


}

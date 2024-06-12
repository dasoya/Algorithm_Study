//
// Created by dasoya on 1/17/24.
//

#include "iostream"
#include "queue"

using namespace std;

int board[100002];
int visit[100002];

int main(void){
    int t = 0;

    cin.tie(0);

    cin >> t;

    while(t--){
        int n;
        cin >> n;

        fill(visit+1,visit+n+1,0);

        for (int i = 1; i <= n; ++i) {
            cin >> board[i];
        }

        for (int i = 1; i <= n; ++i) {

            if(visit[i]==-1) continue;

            int cur = i;
            while(true){
                visit[cur] = i;
                cur = board[cur];
                // 이번 방문에서 지나간 학생에 도달했을 경우
                if(visit[cur] == i){
                    while(visit[cur] != -1){
                        visit[cur] = -1;
                        cur = board[cur];
                    }
                    break;
                }
                    // 이전 방문에서 지나간 학생에 도달했을 경우
                else if(visit[cur] != 0) break;
            }
        }

        
       int cnt = 0;

        for (int i = 1; i <= n; ++i) {

            if(board[i] != -1) cnt++;
            
        }

        cout << cnt << "\n";

    }


}
//
// Created by dasoya on 10/1/24.
//

#include <bits/stdc++.h>
using namespace std;

int heap[100005];
int sz = 0; // heap에 들어있는 원소의 수



void push(int x){

    sz++;
    heap[sz] = x;
    int cur = sz;
    while(cur != 1) {
        int p = cur/2;
        if(heap[p] > heap[cur]) { //
            swap(heap[p],heap[cur]);
            cur = p;
        }
        else{ break;}
    }

  //cout << heap[1] << " ";

}

int top(){

    return heap[1];
}

void pop(){

    if(sz==0) return;

    heap[1] = heap[sz];
    heap[sz] = 0;
    sz--;

    int cur  = 1;

    while(true) {

        if(cur*2>sz) break;

        int ch1 = cur*2;
        int ch2 = cur*2+1;
        int min_child = ch1;

        if(ch2 <= sz && heap[ch2] < heap[ch1] )
            min_child = ch2;
        if(heap[min_child] >= heap[cur]) break;
        
        swap(heap[min_child],heap[cur]);
        cur = min_child;
    }
}




void test(){
    push(10); push(2); push(5); push(9); // {10, 2, 5, 9}
    cout << top() << '\n'; // 2
    pop(); // {10, 5, 9}
    pop(); // {10, 9}
    cout << top() << '\n'; // 9
    push(5); push(15); // {10, 9, 5, 15}
    cout << top() << '\n'; // 5
    pop(); // {10, 9, 15}
    cout << top() << '\n'; // 9
}

int main(){
    //test();
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n,x ;

    cin >> n;

    while(n--){

        cin >> x;
        if(x==0){
            if(sz == 0) cout << 0<<"\n";
            else {
                cout << top() << "\n";
                pop();
            }
        }else{
            push(x);
        }
    }
}
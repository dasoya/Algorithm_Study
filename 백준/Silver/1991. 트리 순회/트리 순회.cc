//
// Created by dasoya on 10/8/24.
//
#include "bits/stdc++.h"

using namespace std;
int lc[27],rc[27];

void postorder(int cur){

    if(lc[cur] !=0) postorder(lc[cur]);
    if(rc[cur] !=0) postorder(rc[cur]);
    cout << (char)(cur +'A'-1);
}


void inorder(int cur){

    if(lc[cur] !=0) inorder(lc[cur]);
    cout << (char)(cur +'A'-1);
    if(rc[cur] !=0) inorder(rc[cur]);

}

void preorder(int cur){

    cout << (char)(cur +'A'-1);
    if(lc[cur] !=0) preorder(lc[cur]);
    if(rc[cur] !=0) preorder(rc[cur]);

}

int main(){

    int n;
    cin >> n;

    for(int i = 0; i < n ; i++){
        char p, l,r;
        cin >> p >> l >> r;

        if(l != '.') lc[p-'A'+1] = l-'A'+1;
        if(r != '.') rc[p-'A'+1] = r-'A'+1;
    }

    preorder(1) ;
    cout << "\n";
    inorder(1);
    cout << "\n";
    postorder(1);


}
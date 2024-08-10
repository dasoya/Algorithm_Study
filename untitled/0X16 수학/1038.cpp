
#include "bits/stdc++.h"

using namespace std;

vector<bool> arr(10,0);

int main(){

    int n;
    cin >> n;
    int cnt = 0;
    //최대.
    //9876543210
    //순열로 접근하면, 1자리, 2자리,

    for (int i = 1; i <= 10; ++i) {
        arr[10-i] = true;

        do{
            if(n!=cnt){
                cnt++;
                continue;
            }

            for(int j=0; j<=9;j++ )
            {
                if(arr[j]) cout << 9-j;//감소하는 수여야함.
            }
            return 0;
        }while(next_permutation(arr.begin(),arr.end()));

    }
    cout << -1;


}
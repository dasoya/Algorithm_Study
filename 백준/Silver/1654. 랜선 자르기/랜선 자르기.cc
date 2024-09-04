//
// Created by dasoya on 8/24/24.
//

#include "iostream"

using namespace std;

int arr[10005];
int k,n;

bool getNum(long long mid){

    long long sum = 0;
    for (int i = 0; i <k ; ++i) {
      sum += arr[i]/mid;
    }

    return sum >= n;
}


int main(){

    //int n;

    cin >> k >> n;

    for (int i = 0; i <k ; ++i) {
        cin >> arr[i];
    }

    //최대 길이를 구하는건데. n은 랜선의 길이가 길어질 수록 감소
    long long st =1;
    long long end =0x7FFFFFFF;//왜 롱롱인지 범위 체크 한번더 해주시고


    while(st<end){
        long long mid = (st+end+1)/2;
        if(getNum(mid)){
           st = mid ;
        }
        else {
            end = mid - 1;
        }
    }

    cout << st;
}


#include "bits/stdc++.h"

using namespace std;



bool row[9][10] ;
bool col[9][10];
bool square[9][10];

//bool check_row(int k){
//
//    int missingIndex = -1;
//    int num = 45;
//
//    for (int i = 0; i < 9; ++i) {
//        if(matrix[k][i] == 0) {
//
//            if(missingIndex != -1) return false;
//            missingIndex = i;
//
//        } else num -= matrix[k][i];
//    }
//
//    if (missingIndex != -1) {
//        matrix[k][missingIndex] = num;
//    }
//
//    row[k] = true;
//
//    return true;
//}
//
//bool check_col(int k){
//
//    int missingIndex = -1;
//    int num = 45;
//
//    for (int i = 0; i < 9; ++i) {
//        if(matrix[i][k] == 0) {
//
//            if(missingIndex != -1) return false;
//            missingIndex = i;
//
//        } else num -= matrix[i][k];
//    }
//
//    if (missingIndex != -1) {
//        matrix[missingIndex][k] = num;
//    }
//
//    col[k] = true;
//
//    return true;
//}
//
//bool check_square(int k){
//
//    //0 1 2
//    //3 4 5
//    //6 7 8
//
//    pair<int,int> missingIndex = {-1,-1};
//    int num = 45;
//
//    for (int i = k/3*3 ; i < k/3*3+3; ++i) {
//        for (int j = k%3*3 ; j < k%3*3+3; ++j) {
//
//            if(matrix[i][j] == 0){
//
//                if(missingIndex.first != -1) return false;
//                missingIndex = {i,j};
//
//            }
//            else num -= matrix[i][j];
//
//        }
//    }
//
//    if (missingIndex.first != -1) {
//        matrix[missingIndex.first][missingIndex.second] = num;
//    }
//
//    square[k] = true;
//
//    return true;
//}
int getSqureIndex(int i,int j)
{
    return (i/3)*3 + j/3;
}

bool fill(int idx, vector<vector<int>> *arr){

    if(idx == 81){
        return true;
    }

    int r = idx / 9;
    int c = idx % 9;

    if ((*arr)[r][c]) {
        return fill(idx + 1, arr);
    }

    for (int num = 1; num <= 9; ++num) {


        if(!row[r][num] && !col[c][num]  && !square[getSqureIndex(r, c)][num] ) {
            (*arr)[r][c] = num;
            row[r][num] = true;
            col[c][num] = true;
            square[getSqureIndex(r, c)][num] = true;

            if(fill(idx+1, arr)){
                return true;
            }

            (*arr)[r][c] = 0;
            row[r][num] = false;
            col[c][num] = false;
            square[getSqureIndex(r, c)][num] = false;
        }
    }

    return false;
}



int main(void) {

    int input;
    vector<vector<int>> answer (9,vector<int>(9));
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> input;
            answer[i][j] = input;

            if(answer[i][j]){
                row[i][answer[i][j]] = true;
                col[j][answer[i][j]] = true;
                square[getSqureIndex(i,j)][answer[i][j]] = true;
            }
        }
    }


    fill(0,&answer);

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << answer[i][j] << " ";
        }
        cout << "\n";
    }

}
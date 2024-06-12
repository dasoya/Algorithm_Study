//
// Created by dasoya on 3/24/24.
//

#include "bits/stdc++.h"

using namespace std;
const int MAX = 9;


bool check_row[MAX][MAX+1];
bool check_col[MAX][MAX+1];
bool check_squre[MAX][MAX+1];

int getSqureIndex(int row, int col){
    return (row/3) *3 +col / 3;
}

bool fillSudoku(int idx, vector<vector<int>> &sudoku){

    if(idx == MAX *MAX){
        return true;
    }

    int row = idx / MAX;
    int col = idx % MAX;

    if(sudoku[row][col]){
        return fillSudoku(idx+1,sudoku);
    }

    for (int i = 1; i <= MAX ; ++i) {

        if(!check_row[row][i] && !check_col[col][i] && !check_squre[getSqureIndex(row,col)][i]){

            check_row[row][i] = true;
            check_col[col][i] = true;
            check_squre[getSqureIndex(row,col)][i] = true;

            sudoku[row][col] = i;

           if( fillSudoku(idx + 1, sudoku)){
               return true;
           }


            check_row[row][i] = false;
            check_col[col][i] = false;
            check_squre[getSqureIndex(row,col)][i] = false;

            sudoku[row][col] = 0;

        }

    }
    return false;
}

vector<vector<int>> solution(vector<vector<int>> sudoku){
    vector<vector<int>> answer(MAX, vector<int>(MAX));
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            answer[i][j] = sudoku[i][j];
            if (sudoku[i][j]) { //스도쿠 상태 보고, check배열들 초기화
                check_row[i][sudoku[i][j]] = true;
                check_col[j][sudoku[i][j]] = true;
                check_squre[getSqureIndex(i, j)][sudoku[i][j]] = true;
            }
        }
    }
    fillSudoku(0, answer);
    return answer;
}

int main() {
    vector<vector<int>> sudoku(MAX, vector<int>(MAX));
    //입력
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cin >> sudoku[i][j];
        }
    }

    //연산
    auto output = solution(sudoku);

    //출력
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cout << output[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
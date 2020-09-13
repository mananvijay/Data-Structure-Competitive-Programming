#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define n 9
bool isSafeRow(int board[n][n], int row, int num){
    for(int i = 0; i < n; i++){
        if(board[row][i] == num){
            return false;
        }
    }
    return true;
}

bool isSafeCol(int board[n][n], int col, int num){
    for(int i = 0; i < n; i++){
        if(board[i][col] == num){
            return false;
        }
    }
    return true;
}

bool isSafeGrid(int board[n][n], int row, int col, int num){
    int rowf = row - (row%3);
    int colf = col - (col%3);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i+rowf][j+colf] == num){
                return false;
            }
        }
    }
    return true;
}
bool isSafe(int board[n][n], int row, int col, int num){
    if(isSafeRow(board, col, num && isSafeCol(board, row, num) && isSafeGrid(board, row, col, num))){
        return true;
    }
    return false;
}
bool findEmptySpace(int board[n][n], int &row, int &col){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == 0){
                row = i;
                col = j;
                return false;
            }
        }
    }
    return true;
}
bool solveSudoku(int board[n][n]){
    int row, col;
    if(!findEmptySpace(board, row, col)){
        return true;
    }
    
    for(int i = 1; i <= 9; i++){
        if(isSafe(board, row, col, i)){
            board[row][col] = i;
            if(solveSudoku(board)){
                return true;
            }
            board[row][col] = 0;
        }
    }
}
int main()
{
    int board[9][9];
    for(int i = 0; i < n; i++){
        string s;
        cin>> s;
        for(int j = 0; j < n; j++){
            board[i][j] = s[j] - '0';
        }
    }
    
     solveSudoku(board);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<board[i][j];
        }
        cout<<endl;
    }
    return 0;
}

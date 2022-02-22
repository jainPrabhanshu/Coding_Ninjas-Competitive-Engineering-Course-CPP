/*
Question : Sudoku Solver

Coding Ninjas has provided you a 9*9 sudoku board. The board contains non zero and zero values. Non zero values lie in the range: [1, 9]. Cells with zero value indicate that the particular cell is empty and can be replaced by non zero values.
You need to find out whether the sudoku board can be solved. If the sudoku board can be solved, then print true, otherwise print false.

Input Format:
There are nine lines in input. Each of the nine lines contain nine space separated integers. These nine lines represent the sudoku board.

Output Format:
The first and only line of output contains boolean value, either true or false, as described in problem statement.
Constraints:
The cell values lie in the range: [0, 9]
Time Limit: 1 second 
Note:
Input are given in a way that backtracking solution will work in the provided time limit.

Sample Input 1:
9 0 0 0 2 0 7 5 0 
6 0 0 0 5 0 0 4 0 
0 2 0 4 0 0 0 1 0 
2 0 8 0 0 0 0 0 0 
0 7 0 5 0 9 0 6 0 
0 0 0 0 0 0 4 0 1 
0 1 0 0 0 5 0 8 0 
0 9 0 0 7 0 0 0 4 
0 8 2 0 4 0 0 0 6

Sample Output 1:
true
*/

#include<bits/stdc++.h>
using namespace std;
#define n 9

bool isEmpty(int board[n][n],int &row ,int &col){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]==0){
                row=i;
                col=j;
                return true;
            }
        }
    }
    return false;
}
bool rowSafe(int board[n][n],int row,int num){
    for(int i=0;i<n;i++){
        if(board[row][i]==num){
            return false;
        }
    }
    return true;
}
bool colSafe(int board[n][n],int col,int num){
    for(int i=0;i<n;i++){
        if(board[i][col]==num){
            return false;
        }
    }
    return true;
}
bool boxSafe(int board[n][n],int row,int col,int num){
    int rowfactor=row-(row%3);
    int colfactor=col-(col%3);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i+rowfactor][j+colfactor]==num){
                return false;
            }
        }
    }
    return true;
}

bool isSafe(int board[n][n],int row,int col,int num){
    if(rowSafe(board,row,num)&&colSafe(board,col,num)&&boxSafe(board,row,col,num)){
        return true;
    }
    return false;
}

bool sudokuSolver(int board[n][n]){
    int row,col;
    if(!isEmpty(board,row,col)){
        return true;
    }
    for(int i=0;i<=n;i++){
        if(isSafe(board,row,col,i)){
            board[row][col]=i;
            if(sudokuSolver(board)){
                return true;
            }
            board[row][col]=0;
        }
    }
    return false;
}

int main(){
    
    // write your code here
    int board[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>board[i][j];
        }
    }
    if(sudokuSolver(board)){
        cout<<"true";
    }else{
        cout<<"false";
    }
    return 0;
}
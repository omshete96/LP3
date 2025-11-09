#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printBoard(const vector<vector<int>>& board, int N){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<board[i][j]<<" ";
        }cout<<endl;
    }
}

bool isSafe(const vector<vector<int>>& board, int row, int col, int N){
    // Check column
    for(int i=0; i<N; i++){
        if(i != row && board[i][col] == 1) return false;
    }

    // Check top-left diagonal
    for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
        if(board[i][j]==1) return false;
    }

    // Check top-right diagonal
    for(int i=row-1, j=col+1; i>=0 && j<N; i--, j++){
        if(board[i][j]==1) return false;
    }

    // Check bottom-left diagonal
    for(int i=row+1, j=col-1; i<N && j>=0; i++, j--){
        if(board[i][j]==1) return false;
    }

    // Check bottom-right diagonal
    for(int i=row+1, j=col+1; i<N && j<N; i++, j++){
        if(board[i][j]==1) return false;
    }

    return true;
}

bool solveNQueens(vector<vector<int>>& board, int row, int N){
    if(row >= N) return true;

    // If this row already has a queen placed, just move to next row
    if(find(board[row].begin(), board[row].end(), 1) != board[row].end()){
        return solveNQueens(board, row + 1, N);
    }

    // Try placing queen in each column
    for(int col = 0; col<N; col++){
        if(isSafe(board, row, col, N)){
            board[row][col] = 1;
            if(solveNQueens(board, row + 1, N)){
                return true;
            }
            board[row][col] = 0;
        }
    }

    return false;
}

int main(){
    int N;
    cout<<"Enter size of board (N): ";
    cin>>N;

    vector<vector<int>> board(N, vector<int>(N,0));

    int firstRow, firstCol;
    cout<<"Enter position of first queen (row and column, 0-based index): ";
    cin>>firstRow>>firstCol;

    if(firstRow >= N || firstCol >= N || firstRow < 0 || firstCol < 0){
        cout<<"Invalid position!"<<endl;
        return 0;
    }

    board[firstRow][firstCol] = 1;

    // Verify the pre-placed queen is safe
    if(!isSafe(board, firstRow, firstCol, N)){
        cout<<"Invalid initial position (conflicts with itself)!"<<endl;
        return 0;
    }

    if(solveNQueens(board, 0, N)){
        cout<<"N-Queens solution: "<<endl;
        printBoard(board, N);
    }
    else{
        cout<<"No solution exists with first queen at the given position."<<endl;
    }

    return 0;
}
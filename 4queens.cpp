#include<iostream>
using namespace std;
#define N 4
int ld[30] ={0}; //left diagonal
int rd[30] ={0}; //right diagonal
int c[30] ={0}; //column

bool solveNQuil(int board[N][N], int col)
{
    if (col >= N) return true; //if all queens placed
    bool res = false;

    // Placing the Queens in all rows one by one
    for (int i = 0; i < N; i++)
    {
        if ((ld[i - col + N - 1] != 1 && rd[i + col] != 1) && c[i] != 1)
        {
            board[i][col] = 1;
            ld[i - col + N - 1] = 1;
            rd[i + col] = 1;
            c[i] = 1;

            // Recur with the next column
            res = solveNQuil(board, col + 1);

            // If the result is true, return immediately
            if (res)
                return true;

            // If the result is false, backtrack
            board[i][col] = 0;
            ld[i - col + N - 1] = 0;
            rd[i + col] = 0;
            c[i] = 0;
        }
    }

    // If no placement leads to a solution, return false
    return res;
}


void solveNQ()
 {
     int board[N][N] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
     if(solveNQuil(board,0)== false){
        cout<<"Solution does not exist";
        //
     }

     for(int i = 0;i<N;i++){
        for(int j=0;j<N;j++)
            cout<<" "<<(board[i][j] == 1?'Q':'.')<<" ";
        cout<<endl;
     }
 }

int main()
{
    solveNQ();
    return 0;

}

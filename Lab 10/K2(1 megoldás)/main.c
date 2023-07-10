#define N 8//tábla méret;
#include<stdbool.h>
#include<stdio.h>

void PrintSolution(int board[N][N])
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            printf("%d ",board[i][j]);
        }
        printf("\n");
    }
}

bool IsSafe(int board[N][N],int row,int col)
{
    int i,j;

    //Sor ellenőrzés;
    for(i=0;i<col;i++)
    {
    if(board[row][i]){return false;}
    }

    //tábla felső része
    for(i=row,j=col;i>=0 && j>=0;i--,j--)
    {
        if(board[i][j]){return false;}
    }

        //tábla alsó része
    for(i=row,j=col;i<N && j>=0;i++,j--)
    {
        if(board[i][j]){return false;}
    }
    return true;
}


bool SolveNUntil(int board[N][N],int col)
{
    if(col>=N){return true;}

    for(int i=;i<N;i++)
    {
       if(IsSafe(board,i,col))
       {
           board[i][col]=1;
           if(SolveNUntil(board,col+1))
            {return true;}
           board[i][col]=0;
       }
    }
    return false;
}


bool SolveNQ()
{
	int board[N][N] = { { 0, 0, 0, 0, 0 },
						{ 0, 0, 0, 0, 0 },
						{ 0, 0, 0, 0, 0 },
						{ 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0 }};

	if (SolveNQUtil(board, 0) == false) {
		printf("Solution does not exist");
		return false;
	}

	PrintSolution(board);
	return true;
}

int main()
{
	solveNQ();
	return 0;
}

#include <stdio.h>
#include <stdbool.h>

#define N 8

int solution = 1;

//bool ispossible = false;

void printboard(int board[N][N]){
	int i, j;
	printf("Solution %d \n", solution);
	for (i=0; i<N; i++){
		for (j=0; j<N; j++){
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	solution++;
}

bool isSafe(int board[N][N], int r, int c){
	int i, j;
	
	for(i=0; i<r; i++){
		if(board[i][c]) return false;
	}
	
	for(i=r, j=c; i>=0 && j<N ; i--, j++){
		if(board[i][j]) return false;
	}
	
	for(i=r, j=c; i>=0 && j>=0 ; i--, j--){
		if(board[i][j]) return false;
	}
	
	return true;
}


void nqueens(int board[N][N], int row){
	
	if(row>=N && solution<=20){  // && !ispossible
		printboard(board);
		//ispossible = true;
		return;
	}
	
	int i, j;
	
	for(i=0; i<N; i++){
		if(isSafe(board, row, i)){
			board[row][i] = 1;
			nqueens(board, row+1);
			board[row][i] = 0;
		}
	}
}

int main(){
	int board [N][N] = {0};
	
	nqueens(board, 0);
	
	return 0;
}



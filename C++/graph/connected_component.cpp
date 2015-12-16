#include <stdio.h>
#include <stdbool.h>

#define COL 5
#define ROW 5

int isSafe(int M[][COL], int row, int col, bool visited[][COL])
{
    return (row >= 0) && (row < ROW) &&     
           (col >= 0) && (col < COL) &&      
           (M[row][col] && !visited[row][col]); 
}

void DFS(int M[][COL], int row, int col, bool visited ){
  static int rowNbr[] = {-1,-1,-1,0,0,1,1,1};
  static int colNbr[] = {-1,0,1,-1,1,-1,0,1};

  visited[row][col] = true;

  for(int k=0;k<8;k++){
  	if(isSafe(M, row+rowNbr[k], col+colNbr[k], visited))
  		DFS(M, row+rowNbr[k], col+colNbr[k], visited);
  }
}

int countIslands(int M[][COL]){
  bool visited[ROW][COL];
  memset(visited,0,sizeof(visited));

  int count = 0;

  for(int i=0;i<ROW;i++)
  	for(int j=0;j<COL;j++){
  		if(M[i][j] && !visited[i][j]){
  			DFS(M,i,j,visited);
  			++count;
  		}
  	}
}

int main(){

    int M[][COL] = {{1,1,0,0,0},
                    {0,1,0,0,1},
                    {1,0,0,1,1},
                    {0,0,0,0,0},
                    {1,0,1,0,1}};

    printf("Number of islands is:%d\n", countIslands(M));
	return 0;
}
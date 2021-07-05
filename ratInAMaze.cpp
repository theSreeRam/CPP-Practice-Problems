//Problem Name - Rat in a Maze
//Tag - Backtracking
// You are given an N*M grid. Each cell (i,j) in the grid is either blocked, or empty. The rat can move from position (i,j), down or right on the grid.
// Initially rat is on the position (1,1). It wants to reach position (N,M). Find the rightmost path through which, rat can reach this position. A path is rightmost, if the rat is at position (i,j), it will always move to (i,j+1), if there exists a path from (i,j+1) to (N,M).

// Input Format
// First line contains 2 integers, N and M, denoting the rows and columns in the grid. Next N line contains. M characters each. An 'X' in position (i,j) denotes that the cell is blocked and ans 'O' denotes that the cell is empty.

// Constraints
// 1<=N,M<=1000 GRID(i,j)='X' or 'O'

// Output Format
// If a solution exists: Print N lines, containing M integers each. A 1 at a position (i,j) denotes that the (i,j)th cell is covered in the path and a 0 denotes that the cell is not covered in the path.
// If solution doesn't exist, just print "-1".

// Sample Input
// 5 4
// OXOO
// OOOX
// OOXO
// XOOO
// XXOO
// Sample Output
// 1 0 0 0 
// 1 1 0 0 
// 0 1 0 0 
// 0 1 1 1 
// 0 0 0 1 


#include<bits/stdc++.h>
using namespace std;

void ratInAMaze(int mat[1001][1001], bool visited[1001][1001], int r, int c, int n, int m, bool &found){
	//Base cases
	if(found){
		return;
	}
	if(r>=n){
		return;
	}
	if(r == n-1 and c==m){
		//This means it has reached the end row
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cout<<visited[i][j]<<" ";
			}
			cout<<endl;
		}
		found = true;
		return;
	}
	
	if(c >= m){
		return;
	}

	//If the current cell is blocked
	if(mat[r][c] == -1){
		return;
	}
	//Otherwise we visit the current cell
	visited[r][c] = true;

	//Now we backtrack to the other positions

	ratInAMaze(mat, visited, r, c+1, n, m, found);
	ratInAMaze(mat, visited, r+1, c, n, m, found);

	visited[r][c] = false;	//Although this line is unnecessary
}

int main(){

	int mat[1001][1001] = {0};
	bool visited[1001][1001]={0};
	
	int n, m;
	cin>>n>>m;

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			char x;
			cin>>x;
			if(x=='X'){
				mat[i][j] = -1;
			} else if(x=='O'){
				mat[i][j] = 0;
			}
		}
	}

	bool found = 0;

	ratInAMaze(mat,visited, 0, 0, n, m , found);
	if(found==false)
		cout<<-1<<endl;

return 0;
}


























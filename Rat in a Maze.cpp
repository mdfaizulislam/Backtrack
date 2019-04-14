/* A Maze is given as N*N binary matrix of blocks where source block is 
* the upper left most block i.e., maze[0][0] and destination block is 
* lower rightmost block i.e., maze[N-1][N-1]. A rat starts from source and 
* has to reach destination. The rat can move only in two directions: forward 
* and down.
i/p
n
maze	// 1 - path open , 0 - path closed
4
1 0 0 0
1 1 0 1
0 1 0 0
1 1 1 1

output
1 0 0 0
1 1 0 0
0 1 0 0
0 1 1 1
*/
#include<iostream>
using namespace std;
const int MAX = 100;
int n;
int maze[MAX][MAX];

bool valid(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1)
		return true;
	return false;
}

bool backtrack(int x, int y, int solution[MAX][MAX]) {	
	if (x == n-1 && y == n-1) {
		solution[x][y] = 1;
		return true;
	}

	if (valid(x,y)) {

		solution[x][y] = 1;
		
		if (backtrack(x + 1, y, solution))
			return true;
		
		if (backtrack(x, y + 1, solution))
			return true;

		solution[x][y] = 0;
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> maze[i][j];
		}
	}

	int solution[MAX][MAX] = { 0 };

	if (backtrack(0, 0, solution)) {
		cout << "Solution:\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << solution[i][j] << " ";
			}
			cout << "\n";
		}
	}
	else {
		cout << "No Solution\n";
	}
	return 0;
}
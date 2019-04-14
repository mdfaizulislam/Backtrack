#include<iostream>
#include<cstdio>
#include<malloc.h>

using namespace std;
#define min(a,b)	((a)<(b)?(a):(b))
#define max(a,b)	((a)>(b)?(a):(b))
#define mod			1000000007
#define MAX			100
#define MIN			INT_MIN
#define ull			unsigned long long
#define ll			long long
#define ul			unsigned long
int N; // size of board
int sol[MAX][MAX];

int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
void printSolution() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << sol[i][j] << " ";
		}
		cout << "\n";
	}
}

bool isSafe(int x, int y) {
	return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}
bool solve(int x, int y, int movei) {
	if (movei == N*N)
		return true;
	int x_move=0, y_move=0, k=0;

	for (k = 0; k < N; k++) {
		x_move = x + xMove[k];
		y_move = y + yMove[k];
		if (isSafe(x_move, y_move)) {
			sol[x_move][y_move] = movei;
			if (solve(x_move, y_move, movei + 1) == true)
				return true;
			else {
				sol[x_move][y_move] = -1;
			}
		}

	}
	return false;
}
void solveKnightTour() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sol[i][j] = -1;
		}
	}
	sol[0][0] = 0;
	if (solve(0, 0, 1) == false)
		cout << "NO sulution exists!\n";
	else
		printSolution();
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(false);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	cout << "Size of Board: ";
	cin >> N;
	solveKnightTour();
	return 0;
}

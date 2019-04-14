#include<iostream>
#include<cstdio>
using namespace std;
const int MAX = 100;

int queen[MAX] = { 0 };	//column num of queen at ith row
bool column[MAX] = { false };
bool left_Diagonal[2 * MAX] = { false };	// row, col diff is same
bool right_Diagonal[2 * MAX] = { false };	// row+col sum is same

void backtrack(int index, int n) {

	if (index == n + 1) {
		for (int i = 1; i <= n; i++) {
			printf_s("(%d,%d)\t", i, queen[i]);
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {	// i-index may be (-), so n is offset
		if (queen[i] == 0 && !left_Diagonal[n + i - index] && !right_Diagonal[i + index]) {
			queen[i] = index;
			left_Diagonal[n + i - index] = right_Diagonal[i + index] = true;
			backtrack(index + 1, n);
			queen[i] = 0;
			left_Diagonal[n + i - index] = right_Diagonal[i + index] = false;
		}
	}
}

int main() {
	int n;
	cin >> n;
	backtrack(1, n);
	return 0;
}
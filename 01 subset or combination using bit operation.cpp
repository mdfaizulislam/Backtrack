#include<iostream>
#include<cstdio>
using namespace std;
int arr[4] = { 10,20,30,40 };
void subset(int index, int status, int n) {
	if (index == n) {
		for (int i = index - 1; i >= 0; i--) {
			if (status&(1 << i))
				cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	subset(index + 1, status, n);	// don't take
	status = status | (1 << index);	// include
	subset(index + 1, status, n);	// don't take
	status = status & ~(1 << index);// exculde
}

int main() {
	subset(0, 0, 4);
	return 0;
}
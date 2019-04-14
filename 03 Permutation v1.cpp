// permutation of n elements
#include<iostream>
#include<vector>
using namespace std;
#define MAX 30
int n;
int arr[MAX];
int result[MAX];
int Size = 0;
bool used[MAX] = { false };

void permute() {
	if (Size == n) {
		for (int j = 0; j < n; j++)
			cout << result[j] << " ";
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		if (used[i] == false) {
			used[i] = true;
			result[Size++] = arr[i];
			permute();
			used[i] = false;
			Size--;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	permute();
	return 0;
}

/*

vector<int> result;
bool used[MAX] = { false };

void permute() {
	if (result.size() == n) {
		for (int j = 0; j < n; j++) {
		co	ut << result[j] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		if (used[i] == false) {
			used[i] = true;
			result.push_back(arr[i]);
			permute();
			used[i] = false;
			result.pop_back();
		}
	}
}
*/
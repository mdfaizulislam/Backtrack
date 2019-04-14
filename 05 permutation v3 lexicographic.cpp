// permute in lexicographic order
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define MAX 30
int n, k;
char arr[MAX];
vector<char>result;
bool used[MAX] = { false };

void permute() {
	if (result.size() == n) {
		for (int j = 0; j < n; j++)
			cout << result[j] << " ";
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

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	//for (int i = 0; i < n; i++)
	//	cin >> arr[i];
	cin >> arr;
	sort(arr, arr + n);
	permute();

	return 0;
}
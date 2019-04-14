// given n elements. Taking k elements from the n elements, print combinations
#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 30
int n, k;
int arr[MAX];
int comb[MAX];

void combination(int index, int start) {

	if (index == k) {
		for (int i = 0; i < k; i++) {
			cout << comb[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = start; i < n - k + index + 1; i++) {
		// to remove duplicate, do the following
		while (arr[i] == arr[i + 1])
		{
			i++;
		}

		comb[index] = arr[i];
		combination(index + 1, i+1);	
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	// to remove duplicate from combination, sort the array
	sort(arr, arr + n);
	combination(0, 0);

	return 0;
}
// given n sticks, make max rectangle using all sticks
// 2 2 2 2 1 1 1 3
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
#define MAX 11
#define min(a,b) ((a)<(b)?(a):(b))
int n;
int arr[MAX];
bool used[MAX] = { false };

struct greater
{
	template<class T>
	bool operator()(T const &a, T const &b) const { return a > b; }
};

bool possible(int k) {
	int start = 0, curr_sum = 0;
	curr_sum += arr[start];
	used[start] = true;
	bool f = false;
	for (int i = 1; i <= n; i++) {
		if (curr_sum > k && start <= i) {
			curr_sum -= arr[start];
			used[start] = false;
			start++;
		}
		if (curr_sum == k) {
			f = true;
			break;
		}
		if (i < n && used[i] == false) {
			curr_sum += arr[i];
			used[i] = true;
		}
	}

	if (f) {
		int i = 0;
		while (used[i] != false && i < n)
		{
			i++;
		}
		start = i;
		curr_sum = arr[start];

		for (int i = start + 1; i <= n; i++) {
			if (curr_sum > k && start <= i) {
				curr_sum -= arr[start];
				used[start] = false;
				start++;
			}
			if (curr_sum == k) {
				return true;
			}
			if (i < n && used[i] == false) {
				curr_sum += arr[i];
				used[i] = true;
			}
		}
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(false);
	cin >> n;
	int s=0, a, b;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		s += arr[i];
	}
	
	s >>= 1; // s/2;
	a = (s >> 1);	// s/2
	b = s - a;
	if (b < a) {
		int t = a;
		a = b;
		b = t;
	}
	sort(arr, arr + n, greater());
	while (a > 0 && b < s-1)
	{
		memset(used, false, n * sizeof(bool));
		if (possible(a)){
			if (possible(b)) {
				cout << a << " " << b << " " << a*b << "\n";
				break;
			}
		}
		a--;
		b++;
	}
	return 0;
}
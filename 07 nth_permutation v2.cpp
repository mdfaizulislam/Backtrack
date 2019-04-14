/*
*Given a permutation of a string. What is the number of this permutation?
*that is nth_term = ?
* input = 236415
* output = 164
*/
#include<iostream>
#include<cstring>
using namespace std;
#define ll long long

char str[21];
bool used[21] = { false };
ll nth_term(int n, ll fact) {	// fact = (n-1)!
	ll nth = 0;
	int index = 0;
	for (int i = 0; i < n; i++) {
		// find index
		int count = 0, j = 1;
		int p = (int)str[i] - '0';
		while (true)
		{
			if (!used[j])
				count++;
			if (j == p) {
				used[j] = true;
				index = count;
				break;
			}
			j++;
		}
		nth += (index - 1)*fact;
		if(n-i-1 > 0)
			fact /= (n - i - 1);
	}
	
	return nth;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> str;
	int n = strlen(str);
	ll f = 1;
	for (int i = 2; i < n; i++)
		f *= i;
	int nth = nth_term(n, f);
	cout << nth << "\n";
	return 0;
}
/*
* given a string of n length consisting of 1 to n digit. 
* Find the nth_permutation
*	input: n =  8 or string = 12345678
*	nth_perm = 168
*/

#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long

ll fact(int n) {
	if (n == 0)	return 1;
	ll f = 1;
	while (n != 1)
	{
		f *= n;
		n--;
	}
	return f;
}

bool used[21] = { false };
void nth_permutation(int n, ll nth_term) {
	int index = 1;
	for (int i = 0; i < n; i++) {
		ll total_perms = fact(n - i);
		ll perms_per_part = total_perms / (n - i);
		// seen_terms = (index-1)*total_perms
		// remaining_terms = nth_term - seen_terms
		nth_term -= (index - 1)*total_perms;
		index = nth_term / perms_per_part + 1;

		// now print nth_term's element
		int count = 0, j = 1;
		while (true)
		{
			if (!used[j])
				count++;
			j++;
			if (count == index) {
				used[j - 1] = true;
				cout << j - 1;
				break;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	int n;
	ll nth_term;
	cin >> n >> nth_term;
	nth_permutation(n, nth_term);
	cout << "\n";
	return 0;
}
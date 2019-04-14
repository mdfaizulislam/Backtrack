#include<iostream>
#include<queue>
using namespace std;
#define MAX 30
int n;
int arr[MAX];
queue<int>q, que;

void subset(int index) {
	if (index == n) {
		while (!q.empty())
		{
			cout << q.front() << " ";
			que.push(q.front());
			q.pop();
		}
		cout << "\n";
		while (!que.empty())
		{
			q.push(que.front());
			que.pop();
		}

		return;
	}

	subset(index + 1);
	q.push(arr[index]);
	subset(index + 1);
	q.pop();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	subset(0);

	return 0;
}
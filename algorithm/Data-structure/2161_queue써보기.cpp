#include<queue>
#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n, m, f;
	queue<int> q;
	vector<int> res;
	cin >> n;
	for (int i = 0; i < n; i++) {
		q.push(i + 1);
	}
	while (q.size() > 1) {
		m = q.front();
		res.push_back(m);
		q.pop();
		if (q.size() > 1) {
			f = q.front();
			q.pop();
			q.push(f);
		}
	}
	for (int x : res) {
		cout << x << " ";
	}
	cout << q.front();
	return 0;
}
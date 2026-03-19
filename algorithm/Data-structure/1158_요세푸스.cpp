#include<queue>
#include<vector>
#include<iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	queue<int> q;
	vector<int> v;
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		q.push(i + 1);
	}
	while (!q.empty()) {
		for (int j = 0; j < k - 1; j++) {
			q.push(q.front());
			q.pop();
		}
		v.push_back(q.front());
		q.pop();
	}
	cout << "<";
	for (int k = 0; k < v.size() - 1; k++) {
		cout << v[k] << ", ";
	}
	cout << v[n - 1] << ">";
	return 0;
}
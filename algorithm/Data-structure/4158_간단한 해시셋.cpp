#include<unordered_set>
#include<iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	unordered_set<int> a;
	int n, m, t, cnt = 0;
	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		for (int i = 0; i < n; i++) {
			cin >> t;
			a.insert(t);
		}
		for (int i = 0; i < m; i++) {
			cin >> t;
			if (a.count(t)) cnt++;
		}
		cout << cnt << '\n';
		cnt = 0;
		a.clear();
	}
	return 0;
}
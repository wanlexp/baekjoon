#include<queue>
#include<vector>
#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	set<int> a, b;
	vector<int> res;
	int n, m, t;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> t;
		a.insert(t);
	}
	for (int i = 0; i < m; i++) {
		cin >> t;
		b.insert(t);
	}
	set_symmetric_difference(a.begin(), a.end(), b.begin(), b.end(), back_inserter(res));
	cout << res.size();
	return 0;
}
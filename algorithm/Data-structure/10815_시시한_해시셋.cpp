#include<unordered_set>
#include<iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, t;
	unordered_set<int> a;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		a.insert(t);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> t;
		if (a.count(t)) {
			cout << 1 << " ";
		}
		else {
			cout << 0 << " ";
		}// 실버5 그만하자 재미도없고 너무쉽네;
	}
	return 0;
}
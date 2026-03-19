#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> ls;
	int n,m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		if (m == 0) {
			if (ls.empty()) {
				cout << 0 << '\n';
			}
			else{
			cout << ls.front() << '\n';
			pop_heap(ls.begin(), ls.end());   
			ls.pop_back();
		    }
		}
		else {
			ls.push_back(m);
			push_heap(ls.begin(), ls.end());
		}
	}
	return 0;
}

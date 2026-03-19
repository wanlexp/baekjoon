#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<string> full(n);
	vector<string>partial(n - 1);

	for (int i = 0; i < n; i++) {
		cin >> full[i];
	}
	for (int i = 0; i < n - 1; i++) {
		cin >> partial[i];
	}
	sort(full.begin(), full.end());
	sort(partial.begin(), partial.end());
	for (int i = 0; i < n - 1; i++) {
		if (full[i] != partial[i]) {
			cout << full[i];
			return 0;
		}
	}
	cout << full[n - 1];
	return 0;
}
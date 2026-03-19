#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include<sstream>
using namespace std;
int main() {
	int n, a, count = 0;
	cin >> n;
	vector<int> num(n);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int i = 0; i < n; i++) {
		cin >> a;
		num.push_back(a);
	}
	int max = 0;
	for (int i = num.size() - 1; i >= 0; --i) {
		if (num[i] > max) {
			max = num[i]; count++;
		}
	}
	cout << count;
	return 0;
}
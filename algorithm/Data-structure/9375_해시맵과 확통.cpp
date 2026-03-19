#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
#include<unordered_map>
using namespace std;
int main() {
	int n, m, res = 1;
	string value, key;
	cin >> n;
	unordered_map<string, vector<string>> mp;
	for (int i = 0; i < n; i++) {
		cin >> m;
		for (int j = 0; j < m; j++) {
			cin >> value >> key;
			mp[key].push_back(value);
		}
		for (auto& it : mp) {
			res *= (mp[it.first].size() + 1);
		}
		cout << res - 1 << endl;
		res = 1;
		mp.clear();
	}
	return 0;
}
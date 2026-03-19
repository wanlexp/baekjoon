#include<unordered_map>
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	unordered_map<string, int> list;
	vector<string> res;
	string name, enter;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> name >> enter;
		if (list.count(name)) {
			list.erase(name);
		}
		else {
			list[name] = 1; // 분기를 안 나누면 지운게 의미없으므로 주의
		}
	}
	for (auto& it : list) {
		res.push_back(it.first);
	}
	sort(res.begin(), res.end(), greater<string>());
	for (string x : res) {
		cout << x << '\n';
	}
	return 0;
}
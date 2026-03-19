#include<queue>
#include<vector>
#include<iostream>
#include<set>
#include<algorithm>
#include<stack>
#include<string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, cnt = 0;
	string s;
	stack<char> st;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		m = s.size();
		for (int j = 0; j < m; j++) {
			if (st.empty()) {
				st.push(s[j]);
			}
			else if (st.top() == s[j]) {
				st.pop();
			}
			else {
				st.push(s[j]);
			}
		}
		if (st.empty()) cnt++;
		st = stack<char>();
	}
	cout << cnt;
	return 0;
}
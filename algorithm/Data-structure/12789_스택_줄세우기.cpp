#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
#include<unordered_set>
#include<stack>
using namespace std;
int main() {
	stack<int> st;
	int n, s, list = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (!st.empty() && st.top() == list) {
			while (!st.empty() && list == st.top()) { st.pop(); ++list; }
		}
		if (s == list) {
			list++;
		}
		else if (!st.empty() && st.top() != list) {
			if (s > st.top()) { cout << "Sad"; return 0; }
			st.push(s);
		}
		else if (st.empty()) {
			st.push(s);
		}

		if (!st.empty() && st.top() == list) {
			while (!st.empty() && list == st.top()) { st.pop(); ++list; }
		}

	}
	if (st.empty()) { cout << "Nice"; }
	else { cout << "Sad"; }

	return 0;
}
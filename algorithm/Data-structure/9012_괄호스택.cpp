#include<queue>
#include<vector>
#include<iostream>
#include<set>
#include<algorithm>
#include<stack>
#include<string>
#include<sstream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	cin.ignore();
	string line;
	stack<char> st;
	for (int i = 0; i < n; i++) {
		getline(cin, line);
		for (auto word = line.begin(); word != line.end(); ++word) {
			if (*word == '(' || *word == '[') {
				st.push(*word);
			}
			else if (*word == ')') {
				if (!st.empty() && st.top() == '(') {
					st.pop();
				}
				else {
					cout << "NO" << '\n'; break;
				}
			}
			else if (*word == ']') {
				if (!st.empty() && st.top() == '[') {
					st.pop();
				}
				else {
					cout << "NO" << '\n'; break;
				}
			}
			if (next(word) == line.end()) {
				if (st.empty()) {
					cout << "YES" << '\n'; break;
				}
				else {
					cout << "NO" << '\n'; break;
				}
			}
		}
		st = stack<char>();
	}
	return 0;
}
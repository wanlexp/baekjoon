#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
#include<unordered_set>
using namespace std;
int main() {
	string s;
	int n;
	cin >> s;
	n = s.size();
	unordered_set<string> st;
	for (int i = 0; i < n; i++) {
		for (int len = 1; i + len <= n; len++) {
			st.insert(s.substr(i, len));
		}
	}
	cout << st.size();
	return 0;
}
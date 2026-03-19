#include <stdio.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	string line, word;
	getline(cin, line);
	bool tag = false;
	string st;
	for (char c : line) {
		if (c == '<') {
			reverse(st.begin(), st.end());
			cout << st<<'<';
			st.clear();
			tag = true;
		}
		else if (c == '>') {
			tag = false;
			cout << c;
		}
		else if (tag) {
			cout << c;
		}
		else if (c == ' ') {
			reverse(st.begin(), st.end());
			cout << st<<' ';
			st.clear();
		}
		else {
			st.push_back(c);
		}

	}
	reverse(st.begin(), st.end());
	cout << st;
	return 0;
}
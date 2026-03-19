#include <iostream>
#include <string>
#include <stack>

using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string line;
	stack<char> left, right;
	int n;
	char command,word;
	getline(cin, line);
	int cursur = line.size();
	cin >> n;
	for (char c : line) {
		left.push(c);
	}
	for (int i = 0; i < n; i++) {
		cin >> command;
		if (command == 'L') {
			if (!left.empty()) {
				right.push(left.top());
				left.pop();
			}
		}
		else if (command == 'D') {
			if (!right.empty()) {
				left.push(right.top());
				right.pop();
			}
		}
		else if (command == 'B') {
			if (!left.empty()) {
				left.pop();
			}	
		}
		else if (command == 'P') {
			cin >> word;
			left.push(word);

		}
	}
	while (!left.empty()) {
		right.push(left.top());
		left.pop();
	}
	while (!right.empty()) {
		cout << right.top();
		right.pop();
	}
	return 0;
}
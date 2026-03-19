#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include<sstream>
using namespace std;
int main() {
	int n, casecount = 0;
	string line, word;
	cin >> n;
	cin.ignore(); // cin 이후에 개행문자가 남는다는 사실을 앞으로 평생 절대로 절대로 절대로 잊지말도록 하거라 절대 잊지말아야할것이다 절대..!
	vector<stack<string>> a(n);

	for (int i = 0; i < n; i++) {
		getline(cin, line);
		istringstream iss(line);
		while (iss >> word) {
			a[i].push(word);
		}
	}
	for (int i = 0; i < n; i++) {
		cout << "Case #" << i + 1 << ":";
		while (!a[i].empty()) {
			cout << " " << a[i].top();
			a[i].pop();
		}
		cout << endl;
	}
}
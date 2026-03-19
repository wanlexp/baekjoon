#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	int n,num,nature=1,now=0;
	stack<int> st;
	cin >> n;
	vector<char> result;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (now < num) {
			for (int j = 0; j < (num - now); j++) {
				st.push(nature);
				nature++;
				result.push_back('+');
			}
			st.pop();
			result.push_back('-');
			now = num;
		}
		else {
			if (st.top() == num) {
				st.pop();
				result.push_back('-');
			}
			else {
				cout << "NO";
				return 0;
			}

		}
	}
	for (char x : result) {
		cout << x << "\n";
	}

	return 0;
}
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int result=0 ,cnt = 0;
	string input;
	char prev = 'a';
	vector<int> stick;
	getline(cin, input);
	for (char s : input) {
		if (s == '(') {
			stick.push_back(0);
			cnt++;
		}
		else if (s == ')') {
			if (prev == '(') {
				//레이저인 경우
				cnt--;
				for (int i = 0; i < cnt; i++) {
					stick[i] = stick[i] + 1;
				}
				stick.pop_back();
			}
			else {
				//레이저가 아니라 막대가 끝나는 경우
				result = result + stick[cnt-1] + 1;
				stick.pop_back();
				cnt--;

			}
		}
		prev = s;
	}
	cout << result;

	return 0;
}
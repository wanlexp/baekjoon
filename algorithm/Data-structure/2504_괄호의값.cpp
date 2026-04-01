#include<iostream>
#include<stack>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
/* 계산을 할때 곱셈의 분배법칙을 이용하면 로직을 간단히 만들 수 있음
* 비단 구현의 문제 뿐만이 아니라 구현의 로직을 어떻게 간단히 만들 수 있을까를 고민하게 해주는 문제
* 또한 공백이 없는 입력이므로 ss를 쓸 필요없이 string s로 바로 입력받아 for 순환문으로 처리하면 더 빠르고
* 정확하게 입출력 처리가 가능함.
*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	stack<char> st;
	string s;
	char c,past=' ';
	getline(cin, s);
	stringstream ss(s);
	int temp = 1,sum=0;
	while (ss >> c) {
		if (st.empty()) {
			if(c==')'||c==']'){
				cout << 0;
				return 0;
			}
		}
		if (c == ')') {
			if (st.top() == '(') {
				if(!(past==')'||past==']')) sum += temp;
				temp /= 2;
				st.pop();
			}
			else{
				cout << 0;
				return 0;
			}
		}
		else if (c == ']') {
			if (st.top() == '[') {
				if(!(past==')'||past==']')) sum += temp;
				temp /= 3;
				st.pop();
			}
			else {
				cout << 0;
				return 0;
			}
		}
		else if (c == '(') {
			temp *= 2;
			st.push(c);
		}
		else if (c == '[') {
			temp *= 3;
			st.push(c);
		}
		past = c;
	}
	if (st.empty()) {
		cout << sum;
	}
	else {
		cout << 0;
	}
	return 0;
}
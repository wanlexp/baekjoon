#include <iostream>
#include <deque>
#include <sstream>
#include <algorithm>
#include <string>
using namespace std;
// isError의 활용, 줄바꿈, 빈배열출력과 같은 문제조건을 잘 확인할 것.

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, arr, num; // fun : 수행할 함수 입력, arr : 테스트할 배열의 크기, n: 전체 테스트 케이스 수
	string fun, input; // input: 입력받는 배열의 원소 한줄, num: 배열의 원소 하나씩 입력받는 변수
	deque<int> dq; // dq : 배열의 원소를 저장하는 덱
	bool flag = true; bool isError= false;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> fun >> arr;
		dq.clear(); // dq의 크기를 arr로 재설정하고 모든 원소를 0으로 초기화
		cin.ignore();
		getline(cin, input);
		replace(input.begin(), input.end(), '[', ' '); // 입력받은 문자열에서 대괄호와 쉼표를 공백으로 대체하여 숫자만 남도록 함
		replace(input.begin(), input.end(), ']', ' ');
		replace(input.begin(), input.end(), ',', ' ');
		flag = true; // 다음 수행전 초기화
		isError = false;
		stringstream ss(input); // 문자열 스트림을 사용하여 공백으로 구분된 숫자들을 추출
		while (ss >> num) { // 추출된 숫자를 dq에 추가
			dq.push_back(num);
		}
		for (char c : fun) { // fun 문자열의 각 문자에 대해 수행할 작업을 결정
			if (c == 'R') { // 'R'이 나타날 때마다 flag의 값을 토글하여 뒤집힘 상태를 나타냄
				if (flag) flag = false;
				else flag = true;
			}
			if (c == 'D') {// 'D'가 나타날 때마다 dq에서 원소를 제거하는데, 제거할 원소가 없는 경우 "error"를 출력하고 반복문을 종료
				if (dq.empty()) {
					cout << "error\n";
					isError = true;
					break;
				}
				if (flag) {// flag가 true인 경우 dq의 앞에서 원소를 제거하고, false인 경우 dq의 뒤에서 원소를 제거
					dq.pop_front();
				}
				else {
					dq.pop_back();
				}
			}
		}
		if (isError) continue; // error 띄운경우 출력하지않음.
			if (!dq.empty()) {
				if (flag) {
					cout << '[' << dq[0];
					for (int i = 1; i < dq.size(); i++) {
						cout << ',' << dq[i];
					}
					cout << ']'<<'\n';
				}
				else {
					cout << '[' << dq[dq.size() - 1];
					for (int i = dq.size() - 2; i >= 0; i--) {
						cout << ',' << dq[i];
					}
					cout << ']'<<'\n';
				}
			}
			else {
				cout << '[' << "]\n";
			}
		}
		
	return 0;
}

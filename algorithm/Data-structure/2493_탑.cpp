#include<iostream>
#include<vector>
#include <sstream>
#include<stack>
#include <string>
using namespace std;

/*
int main() {
	vector<int> arr,res;
	int n,current_number;
	string num;
	int number;
	cin >> n;
	cin.ignore();
	getline(cin, num);
	stringstream ss(num);
	while (ss >> number) {
		arr.push_back(number);
	}
	for (int i = arr.size()-1; i >= 0; i--) {
		number = arr[i];
		for (int j = i-1; j >= 0; j--) {
			current_number = arr[j];
			if (current_number >= number) {
				res.push_back(j+1);
				break;
			}
			else if (j == 0) {
				res.push_back(0);
				break;
			}
		}
		if (i == 0) {
			res.push_back(0);
			break;
		}
	}
	for (int i = res.size()-1; i > 0; i--) {
		cout << res[i] << " ";
	}
	cout << res[0];
	return 0;
}
*/

int main() {
	// 빠른 입출력 필수
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	// (탑의 높이, 탑의 번호)를 쌍으로 저장하는 스택
	stack<pair<int, int>> s;
	int height;
	for (int i = 1; i <= n; i++) {
		
		cin >> height;

		// 나보다 낮은 탑들은 앞으로도 레이저를 못 받으므로 스택에서 제거
		while (!s.empty() && s.top().first < height) {
			s.pop();
		}

		// 스택이 비어있으면 나를 받아줄 탑이 왼쪽에 없다는 뜻
		if (s.empty()) {
			cout << 0 << " ";
		}
		else {
			// 스택의 top이 나보다 높은 가장 가까운 탑
			cout << s.top().second << " ";
		}

		// 현재 탑 정보를 스택에 저장 (다음 탑들을 위해)
		s.push({ height, i });
	}

	return 0;
}
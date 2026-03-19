#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include<sstream>
#include<unordered_set>
#include<algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	string s;
	cin >> n;
	vector<string> ss(n);//정상문자열
	unordered_set<string> st(n); //역순문자열
	for (int i = 0; i < n; i++) {
		cin >> s;
		ss[i] = s;
		reverse(s.begin(), s.end());
		st.insert(s);
	}//정상과 역순 모두 삽입완료됨
	for (int i = 0; i < n; i++) {
		if (st.count(ss[i])) {
			auto it = st.find(ss[i]);
			s = *it;
			break;
		}
	}
	int length;
	length = s.size();
	cout << length << " " << s[length / 2];
	return 0;
}
#include<iostream>
#include<stack>
#include<vector>
//원본 배열 혹은 결과배열을 갖고 있으면 값의 위치만 알면 값을 알 수 있으므로
//값의 순서가 중요한 문제에서는 인덱스만을 저장하고 원본or결과 배열을 참조하는것도 좋은 방법임.
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin >> n;
	stack<int>st; //값이 아니라 인덱스를 저장함
	vector<int> res(n,-1), arr(n); // -1로 초기화한 정답배열과 원본배열
	for (int i = 0; i < n; i++) {
		cin >> m;
		arr[i]=m;
		if (st.empty()) {
			st.push(i);
		}
		else if (arr[st.top()] <m ) {//새로운 값이 오큰수일때
			while (!st.empty() && arr[st.top()] < m) {
				res[st.top()] = m; //정답 배열을 오큰수로 교체
				st.pop();
			}
			st.push(i);
		}
		else {//오큰수가 아닐때
			st.push(i);
		}
	}
	for (int i = 0; i < n; i++) {
		cout << res[i] << " ";
	}
	return 0;
}
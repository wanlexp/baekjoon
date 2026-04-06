#include<iostream>
#include<stack>
/* 새로운 빌딩이 들어왔을 때 그 빌딩을 볼 수 있는 빌딩에 +1을 하여 마지막에 합산 하려면 번거로운 순회가 필요하고
* 시간이 오래 걸린다.
* 그러나 새로운 빌딩이 들어왔을 때 스택에 그 빌딩의 옥상을 볼 수 있는 빌딩만 남아있다면 그 관찰자를 즉시 더하는 것은
* 결과적으로 1의 방법과 다른 것이 없다. 이러한 사고의 전환이 필수적일 것으로 보인다.
*/
using namespace std;
int main(){
	int n,h;
	long long sum=0;
	stack<int> st;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> h;
		if (st.empty()) {
			st.push(h);
			//cout << "current repeat count: " << i << " current total sum: " << sum << '\n';
			continue;
		}
		else if (st.top() <= h) {// 스택의 탑이 새로 들어온 빌딩의 높이와 같거나 작을 때
			while (!st.empty() && st.top() <= h) {
				st.pop();
			}
			sum += st.size();
			st.push(h);
		}
		else {// 스택의 탑이 아직 오른쪽 빌딩을 볼 수 있을 떄
			sum += st.size();
			st.push(h);
			//out << "current repeat count: " << i << " current total sum: " << sum << '\n';
		}
	}
	cout << sum;
	return 0;
}
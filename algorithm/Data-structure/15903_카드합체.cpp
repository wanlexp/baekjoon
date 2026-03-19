#include <iostream>
#include <queue>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	priority_queue<long long, vector<long long>, greater<long long>> pq;
	int n,m,k;
	cin >> n >> k;
	while (n--) {
		cin >> m;
		pq.push(m);
	}
	long long less1, less2,sum=0;
	while (k--) {
		less1 = pq.top(); pq.pop();
		less2 = pq.top(); pq.pop();
		sum = less1 + less2;
		pq.push(sum); pq.push(sum);
		sum = 0;
	}
	while (!pq.empty()) {
		sum += pq.top(); pq.pop();
	}
	cout << sum;
}
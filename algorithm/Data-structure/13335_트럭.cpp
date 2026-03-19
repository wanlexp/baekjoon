#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, w, l,m,current_location=0,res=0,truck_weight=0;//트럭수, 다리길이, 최대하중
	cin >> n >> w >> l;
	int* truck = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> m;
		truck[i] = m;
	}
	int i = 0;
	while (current_location < n ) {
		while (true) {
			if (i<n && l >= (truck_weight + truck[i])) {
				truck_weight = truck_weight + truck[i];
				i++;
			}
			else {
				res = res + w + (i-current_location-1);
				current_location = i;
				truck_weight = 0;
				break;
			}
		}
	}

	cout << res+1;
	return 0;
}
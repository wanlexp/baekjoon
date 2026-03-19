#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
void percolate_down(vector<int>& heap, int i) {
	int n = heap.size();
	int max = i;
	int l = 2 * i + 1, r = 2 * i + 2;
	if (l < n && heap[l] > heap[max]) max = l; //범위를 벗어나지 않는지 먼저 체크필요
	if (r < n && heap[r] > heap[max])max = r;
	if (max != i) {
		swap(heap[i], heap[max]);
		percolate_down(heap, max);
	}

}
int main() {
	int n, me, m, cnt = 0;
	vector<int> heap;
	cin >> n >> me;
	for (int i = 0; i < n - 1; i++) {
		cin >> m;
		heap.push_back(m);
	}
	make_heap(heap.begin(), heap.end());

	while (heap.size() > 0 && me <= heap[0]) { // 힙이 존재하는지 채크해서 빈공간에 접근하는걸 방지
		heap[0] -= 1;
		me += 1;
		cnt++;
		percolate_down(heap, 0);
	}
	cout << cnt;
	return 0;
}
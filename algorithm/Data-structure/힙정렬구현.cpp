#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
bool empty(vector<int> heap) {
	if (heap.empty()) return true;
	else return false;
}
void percolate_down(vector<int>& heap, int index, int size = 0) {  //size는 범위가 줄었을때만 입력
	int n;
	if (size == 0) n = heap.size(); //입력값 없으면 사이즈로 
	else n = size;
	int max = index;
	int left = 2 * index + 1, right = 2 * index + 2;
	if (left < n && heap[left] > heap[max]) max = left; //범위를 벗어나지 않는지 먼저 체크필요 
	if (right < n && heap[right] > heap[max]) max = right; //왼쪽 자식부터 더 큰 값 있으면 교체후 재귀
	if (max != index) { // 교환 일어나지 않으면 멈춤
		swap(heap[index], heap[max]);
		percolate_down(heap, max, n); // 재귀시엔 사이즈 침범안하게 값을 넣어줘야함
	}
}

void build_heap(vector<int>& heap, int parents = 0) {  // 첫 부모노드 부터 루트노드 까지 반복
	if (empty(heap)) { cout << "비어 있음" << '\n'; return; }
	if (parents == 0) parents = (heap.size() - 2) / 2;
	while (parents >= 0) {
		percolate_down(heap, parents);
		parents--;
	}
}

void heap_sort(vector<int>& heap, int tail = 0) { //루트를 맨 뒤로 보내고 사이즈를 줄여 반복
	if (empty(heap)) { cout << "비어 있음" << '\n'; return; }
	if (tail == 0) tail = heap.size() - 1;
	while (tail > 0) {
		swap(heap[0], heap[tail]);
		tail--;
		percolate_down(heap, 0, tail + 1); //size가 필요하기 때문에 호출시 인덱스+1
	}
}


int main() {
	string input;
	vector<int> heap;
	getline(cin, input);
	for (char& c : input) {
		if (!isdigit(c) && c != '-') c = ' '; //숫자가 아닌 문자는 전부 공백으로 처리
	}
	istringstream iss(input);
	int n;
	while (iss >> n) {
		heap.push_back(n); 
	}

	build_heap(heap);
	cout << "build heap: [";
	for (int i = 0; i < heap.size(); i++) {
		cout << heap[i];
		if (i != heap.size() - 1)
			cout << ", ";
	}
	cout << "]" << '\n' << '\n';

	heap_sort(heap);
	cout << "sort heap: [";
	for (int i = 0; i < heap.size(); i++) {
		cout << heap[i];
		if (i != heap.size() - 1)
			cout << ", ";
	}
	cout << "]" << '\n';
	return 0;
}
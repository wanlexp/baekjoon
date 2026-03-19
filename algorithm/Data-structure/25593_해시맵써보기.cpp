#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include<sstream>
#include<unordered_map>
#include<algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	string line;
	string worker;
	unordered_map<string, int> worklist;
	int time[] = { 4, 6, 4, 10 };
	int k = 4;
	cin >> n;
	cin.ignore(); // 개행문자 없애는거 까먹지말라고!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	for (int i = 0; i < n * 4; i++) {
		getline(cin, line);
		istringstream iss(line);
		while (iss >> worker) {
			if (worker != "-") {
				worklist[worker] += time[i % k];
			}
		}
	}
	int max = 0;
	int min = 1000000;
	for (auto& p : worklist) {
		if (p.second > max) max = p.second;
		if (p.second < min) min = p.second;
	}
	/*
	cout << endl << endl << max << " "<<min<<endl;
	for (auto& p : worklist) {
		cout << p.first << " " << p.second << endl;
	}*/
	if (max - min > 12) { cout << "No"; }
	else { cout << "Yes"; }

	return 0;
}